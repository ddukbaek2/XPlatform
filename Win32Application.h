#pragma once

#include "Application.h"
#include <windows.h>


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 윈도우 애플리케이션.
	/////////////////////////////////////////////////////////////////////////////
	class Win32Application : public Application
	{
	private:
		typedef Application Base;

	public:
		static Ref<Win32Application> s_Instance;

	private:
		HWND m_WindowHandle; // 현재 윈도우 핸들.
		HCURSOR m_Cursor;
		HICON m_Icon;

	private:
		static uint64_t __stdcall Procedure(HWND windowHandle, uint32_t message, WPARAM wParam, LPARAM lParam);

	public:
		Win32Application();
		virtual ~Win32Application();

		bool Run(Ref<Scene> initializeOnLoadScene, int width, int height, bool useFullscreen);
		void Quit();
	};
}
