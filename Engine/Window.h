#pragma once
#include "Common.h"
#include <d3d11.h>
#include <Windows.h>
#include <SDL.h>
#include "InputManager.h"

class EXPORT Scene;

class EXPORT Window
{

	SDL_Window * sdlWindow;
	SDL_Event ev;


	HWND handle;
	ID3D11DeviceContext * context;
	ID3D11Device * device;
	IDXGISwapChain * swapChain;
	ID3D11RenderTargetView * backBufferView;
	ID3D11RasterizerState * rState;

	ID3D11DepthStencilView * depthView;
	ID3D11DepthStencilState * depthState;
	ID3D11Texture2D * depthTexture;

	bool windowOpened;
	int width;
	int height;

	MSG msg;

	Scene * scene;
	InputManager * inputManager;

	Window(void);
	~Window(void);


public:
	
	static Window * Create(int width,int height,const char* caption);
	static Window * Create(int width,int height,HWND handle);
	static void Destroy(Window * window);
	
	void HandleEvents();
	bool IsOpen();
	void Close();

	void EndDraw();

	void BeginDraw();

	HWND GetHandle();

	Scene * GetScene();
	InputManager * GetInputManager();

protected:
	void InitD3D(HWND handle,int width,int height);
};

extern LRESULT CALLBACK WinProc(HWND hWindow, UINT msg, WPARAM wParam, LPARAM lParam);

