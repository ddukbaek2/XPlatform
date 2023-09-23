#include "XPlatform.h"
#include "Win32Application.h"
#include "Win32GL.h"
#include "SharedClass.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 전역 변수.
	/////////////////////////////////////////////////////////////////////////////
	//std::chrono::system_clock::time_point g_StartTime;
	float g_DeltaTime = 0.0f;
	Win32Application* Win32Application::s_Instance = nullptr;
	bool g_IsRunning = false;
	std::function<void(void)> g_ApplicationListenerOnCreateEvent;
	std::function<void(void)> g_ApplicationListenerOnDestroyEvent;
	std::function<void(void)> g_ApplicationListenerOnPauseEvent;
	std::function<void(void)> g_ApplicationListenerOnResumeEvent;
	std::function<void(float)> g_ApplicationListenerOnUpdateEvent;
	std::function<void(IGL*)> g_ApplicationListenerOnRenderEvent;


	/////////////////////////////////////////////////////////////////////////////
	// @ 생성자.
	/////////////////////////////////////////////////////////////////////////////
	IApplication::IApplication()
	{
		m_ApplicationListener = nullptr;
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 소멸자.
	/////////////////////////////////////////////////////////////////////////////
	IApplication::~IApplication()
	{
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션 리스너 설정.
	/////////////////////////////////////////////////////////////////////////////
	void IApplication::SetApplicationListener(std::shared_ptr<IApplicationListener> applicationListener)
	{
		m_ApplicationListener = applicationListener;
		g_ApplicationListenerOnCreateEvent = std::bind(&IApplicationListener::OnCreate, m_ApplicationListener);
		g_ApplicationListenerOnDestroyEvent = std::bind(&IApplicationListener::OnDestroy, m_ApplicationListener);
		g_ApplicationListenerOnUpdateEvent = std::bind(&IApplicationListener::OnUpdate, m_ApplicationListener, std::placeholders::_1);
		g_ApplicationListenerOnRenderEvent = std::bind(&IApplicationListener::OnRender, m_ApplicationListener, std::placeholders::_1);
		g_ApplicationListenerOnPauseEvent = std::bind(&IApplicationListener::OnPause, m_ApplicationListener);
		g_ApplicationListenerOnResumeEvent = std::bind(&IApplicationListener::OnResume, m_ApplicationListener);
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션 리스너 반환.
	/////////////////////////////////////////////////////////////////////////////
	std::shared_ptr<IApplicationListener> IApplication::GetApplicationListener()
	{
		return m_ApplicationListener;
	}


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
	bool Win32Application::Run(std::shared_ptr<IApplicationListener> applicationListener, int width, int height, bool useFullscreen)
	{		
		SetApplicationListener(applicationListener);

		HINSTANCE instance = GetModuleHandleW(NULL); // libloaderapi.h
		m_Icon = LoadIconW(NULL, IDI_APPLICATION); // winuser.h
		m_Cursor = LoadCursorW(NULL, IDC_ARROW); // winuser.h

		WNDCLASSEXW windowClassEx;
		memset(&windowClassEx, 0, sizeof(WNDCLASSEX));
		windowClassEx.cbSize = sizeof(WNDCLASSEX);
		typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);
		windowClassEx.lpfnWndProc = &Win32Application::Procedure;
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

		Win32GL::GetSharedInstance()->SetClearColor(0.72f, 0.72f, 0.72f, 1.0f);

		//ShowWindow(m_WindowHandle, /*SW_SHOW*/SW_SHOWMAXIMIZED); // winuser.h
		ShowWindow(m_WindowHandle, SW_SHOW); // winuser.h
		UpdateWindow(m_WindowHandle); // winuser.h

		// 메시지 루프.
		MSG msg;
		memset(&msg, 0, sizeof(MSG));
		msg.message = WM_NULL;

		auto prevTime = std::chrono::system_clock::now();
		while (msg.message != WM_QUIT)
		{
			if (PeekMessageW(&msg, NULL, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&msg);
				DispatchMessageW(&msg);
			}
			else
			{
				auto currentTime = std::chrono::system_clock::now();
				std::chrono::duration<float> deltaTime = currentTime - prevTime;
				g_DeltaTime = deltaTime.count();

				g_ApplicationListenerOnUpdateEvent(g_DeltaTime);
				g_ApplicationListenerOnRenderEvent(Win32GL::GetSharedInstance());

				//m_Application->OnBeginUpdate();
				//m_Application->OnUpdate(g_DeltaTime);
				//m_Application->OnDraw(m_GL);
				//m_Application->OnEndUpdate();

				prevTime = currentTime;
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
	__int64 __stdcall Win32Application::Procedure(HWND windowHandle, UINT message, WPARAM wParam, LPARAM lParam)
	{
		switch (message)
		{
		case WM_CREATE:
			{
				g_ApplicationListenerOnCreateEvent();
				//SetCursor(Instance->m_Cursor);
				//SendMessage(windowHandle, WM_SETICON, ICON_BIG, (LPARAM)Instance->m_Icon);
				//SendMessage(windowHandle, WM_SETICON, ICON_SMALL, (LPARAM)Instance->m_Icon);
				break;
			}

		case WM_SETFOCUS:
			{
				g_ApplicationListenerOnResumeEvent();
				//SetCursor(Instance->m_Cursor);
				//SendMessage(windowHandle, WM_SETICON, ICON_BIG, (LPARAM)Instance->m_Icon);
				//SendMessage(windowHandle, WM_SETICON, ICON_SMALL, (LPARAM)Instance->m_Icon);
				break;
			}

		case WM_KILLFOCUS:
			{
				g_ApplicationListenerOnPauseEvent();
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

					Win32GL::GetSharedInstance()->SetViewport(0, 0, width, height);
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
				g_ApplicationListenerOnDestroyEvent();

				PostQuitMessage(0); // ==> WM_QUIT // winuser.h
				return 0;
			}
		}

		return DefWindowProcW(windowHandle, message, wParam, lParam); // winuser.h
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 실행.
	/////////////////////////////////////////////////////////////////////////////
	void StartApplication(std::shared_ptr<IApplicationListener> applicationListener, int width, int height, bool useFullscreen)
	{
		if (Win32Application::s_Instance == nullptr)
			Win32Application::s_Instance = new Win32Application();

		if (g_IsRunning)
			return;

		g_IsRunning = true;
		auto isSuccessed = Win32Application::s_Instance->Run(applicationListener, width, height, useFullscreen);
		delete Win32Application::s_Instance;
	}


	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 종료.
	/////////////////////////////////////////////////////////////////////////////
	void QuitApplication()
	{
		if (Win32Application::s_Instance != nullptr)
		{
			Win32Application::s_Instance->Quit();
		}
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 실행중인지 여부.
	/////////////////////////////////////////////////////////////////////////////
	bool IsRunningApplication()
	{
		return g_IsRunning;
	}
}