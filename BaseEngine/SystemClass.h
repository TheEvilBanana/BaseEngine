#ifndef _SYSTEMCLASS_H_
#define _SYSTEMCLASS_H_

// Pre-Process directive
#define WIN32_LEAN_AND_MEAN   // Used for building process, reduces the size of some header files and excludes some APIs
 
#include <Windows.h>

#include "InputClass.h"
#include "GraphicsClass.h"


class SystemClass
{
public:
	SystemClass();
	SystemClass(const SystemClass&);
	~SystemClass();

	bool Initialize();
	void Shutdown();
	void Run();

	LRESULT CALLBACK MessageHandler(HWND, UINT, WPARAM, LPARAM);  // For windows message handling when app is running

private:
	bool Frame();
	void InitializeWindows(int&, int&);
	void ShutdownWindows();


	LPCWSTR m_applicationName;
	HINSTANCE m_hinstance;
	HWND m_hwnd;

	InputClass* m_Input; // Pointer to Input handler object
	GraphicsClass* m_Graphics; // Pointer to Graphic handler object
};

// Function prototype
static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);  // included to redirect windows system messages to message handler function

//global
static SystemClass* ApplicationHandle = 0;


#endif


