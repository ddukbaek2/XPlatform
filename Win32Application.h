#pragma once

#include "Application.h"
#include <windows.h>


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 윈도우 어플리케이션.
	/////////////////////////////////////////////////////////////////////////////
	class Win32Application : public Application
	{
	public:
		static Win32Application* s_Instance;

	private:
		HWND m_WindowHandle; // 현재 윈도우 핸들.
		HCURSOR m_Cursor;
		HICON m_Icon;

	private:
		static long __stdcall Procedure(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam);

	public:
		Win32Application();
		virtual ~Win32Application();

		bool Run(std::shared_ptr<Scene> scene, int width, int height, bool useFullscreen);
		void Quit();
	};
}
