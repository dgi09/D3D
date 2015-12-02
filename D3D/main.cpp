#include "Window.h"
#include "StaticEntity.h"
#include "Scene.h"
#include "Camera.h"
#include "DirectionalLight.h"
#include "PointLight.h"
#include "AnimatedEntity.h"
#include <string>
#include "AnimationController.h"
#include "Material.h"
#include <time.h>
#include "InputManager.h"
#include "FPSCameraController.h"
#include "ModelCreator.h"


#include "ITest.h"
#include "Dragon_Dogs_ParticleSystem.h"
#include "Model_Creator.h"
#include "Billboard_Test.h"
#include "Object_Picking_Test.h"

#undef main

#define LOOP_STYLE

//int WINAPI WinMain( _In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nShowCmd )
int main(int argc, char** argv)
{

	srand(time_t(0));

	unsigned int w = 1000;
	unsigned int h = 1000;
	Window * window = Window::Create(w,h,"Game");

	Scene * scene = window->GetScene();

#ifdef WORK_PC
	scene->SetShadersPath("E:\\D3D\\ShaderTamplates");
#else 
	scene->SetShadersPath("E:\\Projects\\D3D\\ShaderTamplates");
#endif
	
	scene->Init();
	scene->SetGlobalAmbient(0.03f,0.03f,0.03f,1.0f);
	scene->SetBackgroundColor(Color::Blue());
	CameraPtr camPtr = scene->AddCamera();
	Camera * cam = camPtr.Get();


	cam->SetPosition(0.0f,0.0f,-5.0f);
	cam->LookAt(0.0f,0.0f,0.0f);
	cam->SetNearDistance(2.0f);
	cam->SetFarDistance(50000.0f);
	cam->SetFOV(60.0f);

	scene->SetActiveCamera(camPtr);


	ITest * test = new Dragon_Dogs_ParticleSystem;
	test->Init(scene);
	
	
	InputManager * mgr = window->GetInputManager();


	//((Object_Picking_Test*)test)->SetInputMgr(mgr);

	FPSCameraController fps;
	fps.SetCamera(camPtr);
	fps.SetMovementSpeed(2.0f);



#ifdef LOOP_STYLE
	long time = GetTickCount();
	while(window->IsOpen())
	{
		if(GetTickCount() - time < 12)
			continue;

		window->HandleEvents();
	

		test->Update();

		if (mgr->KeyPressed(SDL_SCANCODE_LEFT))
			fps.InjectKeyDown(FPSBind_Key_Left);
		else fps.InjectKeyUp(FPSBind_Key_Left);

		if (mgr->KeyPressed(SDL_SCANCODE_RIGHT))
			fps.InjectKeyDown(FPSBind_Key_Right);
		else fps.InjectKeyUp(FPSBind_Key_Right);

		if (mgr->KeyPressed(SDL_SCANCODE_UP))
			fps.InjectKeyDown(FPSBind_Key_Up);
		else fps.InjectKeyUp(FPSBind_Key_Up);

		if (mgr->KeyPressed(SDL_SCANCODE_DOWN))
			fps.InjectKeyDown(FPSBind_Key_Down);
		else fps.InjectKeyUp(FPSBind_Key_Down);

		if (mgr->MouseButtonDown(B_RIGHT))
			fps.InjectMouseDown(FPSBind_Mouse_Right);
		else fps.InjectMouseUp(FPSBind_Mouse_Right);

		fps.InjectMouseMove(mgr->MouseMove());

		fps.InjectMousePos(mgr->GetMouseX(), mgr->GetMouseY());
			
		fps.Update();

		scene->DrawAll();

		time  = GetTickCount();
	}

#else 
	scene->DrawAll();
	window->Close();
#endif


	Window::Destroy(window);
	return 0;
}


