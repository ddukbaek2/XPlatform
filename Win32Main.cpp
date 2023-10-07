#include "XPlatform.h"
#include "InitializeOnLoadScene.h"
//#include "Win32Application.h"
#include <windows.h> // GetConsoleWindow(), ShowWindow(), ExitProcess().


/////////////////////////////////////////////////////////////////////////////
// @ 진입점.
/////////////////////////////////////////////////////////////////////////////
//int32_t __stdcall wWinMain(HINSTANCE, HINSTANCE, wchar_t*, int32_t)
int32_t main()
{
	// 콘솔 감추기.
#if !defined(_DEBUG)
	auto consoleWindowHandle = GetConsoleWindow(); // consoleapi3.h
	ShowWindow(consoleWindowHandle, SW_HIDE); // WinUser.h
#endif

	// 어플리케이션 실행.
	XPlatform::StartApplication(CreateRef<InitializeOnLoadScene>(), 1280, 640, false);

#if !defined(_DEBUG)
	ExitProcess(0); // processthreadsapi.h
#endif

	return 0;
}
