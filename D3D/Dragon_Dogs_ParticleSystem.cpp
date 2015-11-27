#include "Dragon_Dogs_ParticleSystem.h"

void Dragon_Dogs_ParticleSystem::Init(Scene * scene)
{
	psPtr = scene->AddParticleSystem();
	ParticleSystem * ps = psPtr.Get();
	ps->SetColorTexture("assets/fire.png");
	ps->SetEmmiterPosition(Vector3(45.0f, 0.0f, 0.0f));
	ps->SetMinSpawnPosition(Vector3(-1.0f, 0.0f, 0.0f));
	ps->SetMaxSpawnPosition(Vector3(1.0f, 0.0f, 0.0f));
	ps->SetMaxLifeTime(70);
	ps->SetMinLifeTime(50);
	ps->SetMaxParticles(70);
	ps->SetSpawnTime(4.0);
	ps->SetMinSize(10);
	ps->SetMaxSize(14);
	////entitiy->SetPosition(10.0f,0.0f,0.0f);


	drPtr = scene->AddParticleSystem();
	ps = drPtr.Get();

	ps->SetColorTexture("assets/fire.png");
	ps->SetEmmiterPosition(Vector3(-30.0f, 150.0, 10.0f));
	ps->SetMinSpawnPosition(Vector3(-0.2f, 0.3f, 0.0f));
	ps->SetMaxSpawnPosition(Vector3(0.2f, -0.3f, 0.0f));
	ps->SetMinSpawnVelocity(Vector3(-1.0f, -2.0f, -1.8f));
	ps->SetMaxSpawnVelocity(Vector3(1.0f, -2.0f, -1.0f));
	ps->SetMaxLifeTime(30);
	ps->SetMinLifeTime(45);
	ps->SetMaxParticles(70);
	ps->SetSpawnTime(4.0);
	ps->SetMinSize(10);
	ps->SetMaxSize(14);
	ps->AllowParticleAdd(false);

	plDragon = scene->AddPointLight();
	PointLight * plD = plDragon.Get();
	plD->SetDiffuse(1.0f, 0.4f, 0.0f, 1.0f);
	plD->SetRange(1.0f);
	plD->SetPosition(-30.0f, 150.0, 10.0f);

	dragonTime = 0;
	dragonOn = false;
	enPtr = scene->AddAnimatedEntity("assets/ninja.model", "ninja");

	AnimatedEntity * en = enPtr.Get();
	en->SetPosition(0.0f, 0.0f, 0.0f);
	en->Illuminate(false);
	en->SetScale(10.0f, 10.0f, 10.0f);
	en->SetPosZ(-100);
	//en->SetRotationY(90.0f);

	Material * mat = en->GetMaterial(0);
	mat->UseDiffuseMap(true);
	mat->SetDiffuseColor(Color::White());
	mat->SetDiffuseMap("assets/nskin.jpg");

	mat->SetEmmisivePower(1);
	mat->SetSpecularPower(0);
	mat->SetSpecularIntesity(0);

	mat = en->GetMaterial(1);
	mat->UseDiffuseMap(false);
	mat->SetEmmisivePower(1);
	mat->SetSpecularIntesity(0);
	mat->SetSpecularPower(0);
	mat->SetDiffuseColor(Color(0.3f, 0.3f, 0.3f, 1.0f));

	pointLight = scene->AddPointLight();

	PointLight * p = pointLight.Get();
	p->SetDiffuse(1.0f, 0.4f, 0.0f, 1.0f);
	p->SetRange(500.0f);
	p->SetPosition(45.0f, 4.0f, 0.0f);

	planePtr = scene->AddStaticEntity("assets/plane.model", "plane");
	StaticEntity * plane = planePtr.Get();
	plane->Illuminate(true);
	plane->SetScale(50.0f, 1.0f, 50.0f);

	Material * pMat = plane->GetMaterial(0);
	pMat->UseDiffuseMap(false);
	pMat->SetDiffuseColor(Color(0.3f, 0.3f, 0.3f, 1.0f));
	pMat->SetEmmisivePower(1);
	pMat->SetSpecularPower(0);
	pMat->SetSpecularIntesity(0);

	plane->SetPosition(0.0f, -7.0f, 0.0f);

	dogPtr = scene->AddStaticEntity("assets/dog.smodel", "dog");
	StaticEntity * dog = dogPtr.Get();
	dog->Illuminate(true);
	dog->SetPosition(80.0f, 10.0, 60.0f);
	dog->SetScale(400.0f, 400.0f, 400.0f);
	dog->SetRotation(0.0f, 60.0f, 180.0f);
	dog->SetRotationY(45.0f);

	pMat = dog->GetMaterial(0);
	pMat->SetDiffuseColor(Color(0.2f, 0.2f, 0.2f, 1.0f));

	dogPtr2 = scene->AddStaticEntity("assets/dog.smodel", "dog");
	dog = dogPtr2.Get();

	dog->Illuminate(true);
	dog->SetPosition(-100.0f, 10.0, 60.0f);
	dog->SetScale(400.0f, 400.0f, 400.0f);
	dog->SetRotation(0.0f, -60.0f, 180.0f);
	//dog->SetRotationY(45.0f);

	pMat = dog->GetMaterial(0);
	pMat->SetDiffuseColor(Color(0.2f, 0.0f, 0.0f, 1.0f));

	lightChangeTime = 0.0f;

	powerMin = 0.6f;
	powerMax = 1.0f;

	animContr = enPtr.Get()->LoadAnimationFromFile("assets/ninja.anim", "animPack");
	enPtr.Get()->SetCurrentAnimationController(animContr);
	animContr->AddAnimationState(0, 14, LOOP, "idle");
	animContr->SetCurrentAnimationState("idle");

	torchPtr = scene->AddStaticEntity("assets/smaug.smodel", "m24");
	StaticEntity * torch = torchPtr.Get();
	torch->SetPosition(-30.0f, 100.0, 70.0f);
	torch->SetScale(3.0f, 3.0f, 3.0f);
	torch->Illuminate(true);

	mat = torch->GetMaterial(0);
	mat->SetEmmisivePower(1);
	mat->SetSpecularPower(10);

	treePtr = scene->AddStaticEntity("assets/tree.smodel", "tree");
	StaticEntity * tree = treePtr.Get();

	tree->SetPosition(150.0f, 23.0f, 0.0f);
	tree->SetScale(10.0f, 10.0f, 10.0f);
	tree->Illuminate(true);


	mat = tree->GetMaterial(0);
	mat->UseDiffuseMap(true);
	mat->SetDiffuseMap("assets/w3.jpg");

	swordPtr = scene->AddStaticEntity("assets/sword.smodel", "sword");
	StaticEntity * sword = swordPtr.Get();
	sword->SetPosition(150.0f, 80.0f, 0.0f);
	sword->Illuminate(false);
	sword->SetScale(2.0f, 2.0f, 2.0f);
	sword->SetRotationZ(180.0f);
	mat = sword->GetMaterial(0);
	mat->UseDiffuseMap(false);
	mat->SetDiffuseColor(Color::White());
	mat->SetEmmisivePower(10);
}


void Dragon_Dogs_ParticleSystem::Update()
{
	dragonTime++;

	if (dragonTime >= 150)
	{
		if (dragonOn)
		{
			plDragon.Get()->SetRange(1.0f);
			drPtr.Get()->AllowParticleAdd(false);
			dragonOn = false;
		}
		else
		{
			plDragon.Get()->SetRange(200.0f);
			drPtr.Get()->AllowParticleAdd(true);
			dragonOn = true;
		}
		dragonTime = 0;
	}

	drPtr.Get()->AddTime(1.0);

	

	enPtr.Get()->Yaw(0.01f);
	psPtr.Get()->AddTime(1.0);


	enPtr.Get()->Move(0.0f, 0.0f, 1.0f);
	animContr->AddTime(0.2f);

	lightChangeTime += 1.0f;
	if (lightChangeTime >= 6.0f)
	{

		float powerCoef = (float)rand() / RAND_MAX;
		float pow = powerMin + powerCoef * (powerMax - powerMin);
		pointLight.Get()->SetDiffuse(1.0f * pow, 0.3f * pow, 0.0f, 1.0f);

		lightChangeTime = 0.0f;
	}
}