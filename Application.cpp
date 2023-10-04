#include "Application.h"
#include "InitializeScene.h"

namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 생성자.
	/////////////////////////////////////////////////////////////////////////////
	Application::Application()
	{
		//m_ApplicationEventHandler = nullptr;
		m_DeltaTime = 0.0f;
		m_IsPlaying = false;
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 소멸자.
	/////////////////////////////////////////////////////////////////////////////
	Application::~Application()
	{
	}

	void Application::OnCreate()
	{
		m_PreviousTime = std::chrono::system_clock::now();
		m_SceneManager = std::make_shared<SceneManager>();
		//m_CreateEvent();

		// 기본씬은 항상 생성.
		m_SceneManager->Add(std::make_shared<InitializeScene>());
		auto scene = m_SceneManager->GetSceneAt(0);
		m_SceneManager->Play(scene);
	}

	void Application::OnDestroy()
	{
		//m_DestroyEvent();
	}

	void Application::OnPause()
	{
		//m_PauseEvent();
		m_SceneManager->OnPause();
	}

	void Application::OnResume()
	{
		//m_ResumeEvent();
		m_SceneManager->OnResume();
	}

	void Application::OnUpdate(float deltaTime)
	{
		m_SceneManager->OnUpdate(deltaTime);
	}

	void Application::OnRender(Ref<IGL> gl)
	{
		m_SceneManager->OnRender(gl);
	}

	void Application::OnMainLoop()
	{ 
		auto gl = GetGL();
		auto currentTime = std::chrono::system_clock::now();
		auto deltaTime = currentTime - m_PreviousTime; // std::chrono::duration<float>
		{
			m_DeltaTime = deltaTime.count();
			
			//m_TickEvent(m_DeltaTime);
			//m_RenderEvent(gl);

			OnUpdate(m_DeltaTime);
			OnRender(gl);
		}
		m_PreviousTime = currentTime;

		//m_Application->OnBeginUpdate();
		//m_Application->OnUpdate(g_DeltaTime);
		//m_Application->OnDraw(m_GL);
		//m_Application->OnEndUpdate();
	}

	///////////////////////////////////////////////////////////////////////////////
	//// @ 애플리케이션 리스너 설정.
	///////////////////////////////////////////////////////////////////////////////
	//void Application::SetApplicationListener(Reference<ApplicationEventHandler> applicationEventHandler)
	//{
	//	m_ApplicationEventHandler = applicationEventHandler;
	//	m_CreateEvent = std::bind(&Application::OnCreate, m_ApplicationEventHandler);
	//	m_DestroyEvent = std::bind(&Application::OnDestroy, m_ApplicationEventHandler);
	//	m_TickEvent = std::bind(&Application::OnUpdate, m_ApplicationEventHandler, std::placeholders::_1);
	//	m_RenderEvent = std::bind(&Application::OnRender, m_ApplicationEventHandler, std::placeholders::_1);
	//	m_PauseEvent = std::bind(&Application::OnPause, m_ApplicationEventHandler);
	//	m_ResumeEvent = std::bind(&Application::OnResume, m_ApplicationEventHandler);
	//}

	/////////////////////////////////////////////////////////////////////////////
	// @ OpenGL 셋팅.
	/////////////////////////////////////////////////////////////////////////////
	void Application::SetGL(Ref<IGL> gl)
	{
		m_GL = gl;
	}

	///////////////////////////////////////////////////////////////////////////////
	//// @ 애플리케이션 리스너 반환.
	///////////////////////////////////////////////////////////////////////////////
	//Reference<ApplicationEventHandler> Application::GetApplicationListener()
	//{
	//	return m_ApplicationEventHandler;
	//}

	/////////////////////////////////////////////////////////////////////////////
	// @ OpenGL 반환.
	/////////////////////////////////////////////////////////////////////////////
	Ref<IGL> Application::GetGL()
	{
		return m_GL;
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 플레이 여부 반환.
	/////////////////////////////////////////////////////////////////////////////
	bool Application::IsPlaying()
	{
		return m_IsPlaying;
	}
}
