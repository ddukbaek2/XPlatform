#include "Win32Application.h"
#include "Win32GL.h"
#include <windows.h>


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전역변수 선언.
	/////////////////////////////////////////////////////////////////////////////
	Win32Application* Win32Application::s_Instance;


	/////////////////////////////////////////////////////////////////////////////
	// @ 생성자.
	/////////////////////////////////////////////////////////////////////////////
	Win32Application::Win32Application()
	{
		m_WindowHandle = nullptr;
		m_Cursor = nullptr;
		m_Icon = nullptr;
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 소멸자.
	/////////////////////////////////////////////////////////////////////////////
	Win32Application::~Win32Application()
	{
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 실행.
	/////////////////////////////////////////////////////////////////////////////
	bool Win32Application::Run(Ref<Scene> scene, int width, int height, bool useFullscreen)
	{
		m_IsPlaying = true;
		//SetApplicationListener(applicationEventHandler);

		HINSTANCE instance = GetModuleHandleW(NULL); // libloaderapi.h
		m_Icon = LoadIconW(NULL, IDI_APPLICATION); // winuser.h
		m_Cursor = LoadCursorW(NULL, IDC_ARROW); // winuser.h

		WNDCLASSEXW windowClassEx;
		memset(&windowClassEx, 0, sizeof(WNDCLASSEX));
		windowClassEx.cbSize = sizeof(WNDCLASSEX);
		//typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
		windowClassEx.lpfnWndProc = (WNDPROC)&Win32Application::Procedure;
		windowClassEx.hInstance = instance;
		windowClassEx.hIcon = m_Icon;
		windowClassEx.hCursor = m_Cursor;
		windowClassEx.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(191, 191, 191)); // wingdi.h
		windowClassEx.lpszClassName = L"XPlatform";
		windowClassEx.hIconSm = m_Icon;
		RegisterClassExW(&windowClassEx); // winuser.h 

		//m_WindowHandle = CreateWindowExW(0L, L"XPlatform", L"XPlatform",
		//	WS_VISIBLE | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | WS_POPUP,
		//	CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		//	nullptr, nullptr, instance, nullptr); // winuser.h
		m_WindowHandle = CreateWindowExW(0L, L"XPlatform", L"XPlatform",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT, width, height,
			nullptr, nullptr, instance, nullptr); // winuser.h

		if (!m_WindowHandle)
		{
			return false;
		}

		// 렌더러 초기화.
		HDC deviceContext = GetDC(m_WindowHandle); // winuser.h
		PIXELFORMATDESCRIPTOR pixelFormatDescriptor;
		memset(&pixelFormatDescriptor, 0, sizeof(PIXELFORMATDESCRIPTOR)); // vcruntime_string.h
		pixelFormatDescriptor.nSize = sizeof(pixelFormatDescriptor);
		pixelFormatDescriptor.nVersion = 1;
		pixelFormatDescriptor.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL;
		pixelFormatDescriptor.iPixelType = PFD_TYPE_RGBA;
		pixelFormatDescriptor.cColorBits = 32;

		int pixelFormat = ChoosePixelFormat(deviceContext, &pixelFormatDescriptor); // wingdi.h
		if (pixelFormat == 0)
		{
			return false;
		}

		if (!SetPixelFormat(deviceContext, pixelFormat, &pixelFormatDescriptor)) // wingdi.h
		{
			return false;
		}

		DescribePixelFormat(deviceContext, pixelFormat, sizeof(PIXELFORMATDESCRIPTOR), &pixelFormatDescriptor); // wingdi.h
		//ReleaseDC(m_WindowHandle, deviceContext);
		//deviceContext = GetDC(m_WindowHandle);
		HGLRC renderingContext = wglCreateContext(deviceContext); // wingdi.h
		wglMakeCurrent(deviceContext, renderingContext); // wingdi.h

		// GL 생성.
		auto gl = std::make_shared<Win32GL>();
		SetGL(gl);
		gl->SetClearColor(0.72f, 0.72f, 0.72f, 1.0f);

		//ShowWindow(m_WindowHandle, /*SW_SHOW*/SW_SHOWMAXIMIZED); // winuser.h
		ShowWindow(m_WindowHandle, SW_SHOW); // winuser.h
		UpdateWindow(m_WindowHandle); // winuser.h

		// 메시지 루프.
		MSG msg;
		memset(&msg, 0, sizeof(MSG));
		msg.message = WM_NULL;

		while (msg.message != WM_QUIT)
		{
			if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessageW(&msg);
			}
			else
			{
				Application::OnMainLoop();
				Sleep(1);
			}
		}

		//wglMakeCurrent(NULL, NULL); // wingdi.h
		//wglDeleteContext(renderingContext); // wingdi.h
		//renderingContext = nullptr;
		ReleaseDC(m_WindowHandle, deviceContext); // winuser.h

		//return (int32)msg.wParam;
		return true;
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 종료.
	/////////////////////////////////////////////////////////////////////////////
	void Win32Application::Quit()
	{
		//CloseWindow(m_WindowHandle); // winuser.h
		//DestroyWindow(m_WindowHandle); // ==> WM_DESTROY // winuser.h
		//m_WindowHandle = 0;

		//SendMessageW(m_WindowHandle, WM_CLOSE, 0, 0);
		PostQuitMessage(0);
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 프로시저.
	/////////////////////////////////////////////////////////////////////////////
	long __stdcall Win32Application::Procedure(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_CREATE:
			{
				//s_Instance->m_CreateEvent();
				s_Instance->OnCreate();
				//SetCursor(Instance->m_Cursor);
				//SendMessage(windowHandle, WM_SETICON, ICON_BIG, (LPARAM)Instance->m_Icon);
				//SendMessage(windowHandle, WM_SETICON, ICON_SMALL, (LPARAM)Instance->m_Icon);
				break;
			}

		case WM_SETFOCUS:
			{
				s_Instance->OnResume();

				//s_Instance->m_ResumeEvent();
				//SetCursor(Instance->m_Cursor);
				//SendMessage(windowHandle, WM_SETICON, ICON_BIG, (LPARAM)Instance->m_Icon);
				//SendMessage(windowHandle, WM_SETICON, ICON_SMALL, (LPARAM)Instance->m_Icon);
				break;
			}

		case WM_KILLFOCUS:
			{
				//s_Instance->m_PauseEvent();
				s_Instance->OnPause();
				break;
			}

		case WM_SIZE:
			{
				uint16_t width = LOWORD(lParam); // minwindef.h
				uint16_t height = HIWORD(lParam); // minwindef.h
				if (s_Instance != nullptr)
				{
					//if (Instance->m_Application != nullptr)
					//{
					//	Instance->m_Application->OnResize(width, height);
					//}

					s_Instance->GetGL()->SetViewport(0, 0, width, height);
				}
				break;
			}

		case WM_KEYDOWN:
			{
				//if (Instance != nullptr && Instance->m_Application != nullptr)
				{
					switch (wParam)
					{
					case VK_ESCAPE:
						//Instance->m_Application->OnKeyPress(IApplication::EKeyCode::Escape);
						QuitApplication();
						break;
					case VK_LEFT:
						break;
					case VK_RIGHT:
						break;
					case VK_UP:
						break;
					case VK_DOWN:
						break;
					}
				};
				break;
			}

		case WM_KEYUP:
			{
				//if (Instance != nullptr && Instance->m_Application != nullptr)
				{
					switch (wParam)
					{
					case VK_ESCAPE:
						//Instance->m_Application->OnKeyRelease(IApplication::EKeyCode::Escape);
						break;
					case VK_LEFT:
						break;
					case VK_RIGHT:
						break;
					case VK_UP:
						break;
					case VK_DOWN:
						break;
					}
				}
				break;
			}

		case WM_CLOSE:
			{
				DestroyWindow(windowHandle); // ==> WM_DESTROY // winuser.h
				//SendMessageW(windowHandle, WM_DESTROY, 0, 0);
				return 0;
			}

		case WM_DESTROY:
			{
				//if (Instance != nullptr && Instance->m_Application != nullptr)
				//	Instance->m_Application->OnDestroy();
				//s_Instance->m_DestroyEvent();
				s_Instance->OnDestroy();
				PostQuitMessage(0); // ==> WM_QUIT // winuser.h
				return 0;
			}
		}

		return DefWindowProcW(windowHandle, message, wParam, lParam); // winuser.h
	}


#ifdef XPLATFORM_WINDOWS
	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션 실행.
	/////////////////////////////////////////////////////////////////////////////
	void StartApplication(Ref<Scene> scene, int width, int height, bool useFullscreen)
	{
		if (Win32Application::s_Instance == nullptr)
			Win32Application::s_Instance = new Win32Application();

		if (Win32Application::s_Instance->IsPlaying())
			return;

		auto isSuccessed = Win32Application::s_Instance->Run(scene, width, height, useFullscreen);
		delete Win32Application::s_Instance;
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션 종료.
	/////////////////////////////////////////////////////////////////////////////
	void QuitApplication()
	{
		if (Win32Application::s_Instance != nullptr)
		{
			Win32Application::s_Instance->Quit();
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션 객체 반환.
	/////////////////////////////////////////////////////////////////////////////
	Application* GetApplication()
	{
		return static_cast<Application*>(Win32Application::s_Instance);
	}
#endif
}
