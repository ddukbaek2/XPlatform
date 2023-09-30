#include "XApplication.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 생성자.
	/////////////////////////////////////////////////////////////////////////////
	XApplication::XApplication()
	{
		m_ApplicationEventHandler = nullptr;
		m_DeltaTime = 0.0f;
		m_IsPlaying = false;
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 소멸자.
	/////////////////////////////////////////////////////////////////////////////
	XApplication::~XApplication()
	{
	}

	void XApplication::OnCreate()
	{
		m_PreviousTime = std::chrono::system_clock::now();
		m_SceneManager = std::make_shared<SceneManager>();
		m_CreateEvent();
	}

	void XApplication::OnDestroy()
	{
		m_DestroyEvent();
	}

	void XApplication::OnPause()
	{
		m_PauseEvent();
	}

	void XApplication::OnResume()
	{
		m_ResumeEvent();
	}

	void XApplication::OnMainLoop()
	{ 
		auto gl = GetGL();
		auto currentTime = std::chrono::system_clock::now();
		auto deltaTime = currentTime - m_PreviousTime; // std::chrono::duration<float>
		{
			m_DeltaTime = deltaTime.count();
			m_TickEvent(m_DeltaTime);
			m_RenderEvent(gl);
		}
		m_PreviousTime = currentTime;

		//m_Application->OnBeginUpdate();
		//m_Application->OnUpdate(g_DeltaTime);
		//m_Application->OnDraw(m_GL);
		//m_Application->OnEndUpdate();
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션 리스너 설정.
	/////////////////////////////////////////////////////////////////////////////
	void XApplication::SetApplicationListener(std::shared_ptr<XApplicationEventHandler> applicationEventHandler)
	{
		m_ApplicationEventHandler = applicationEventHandler;
		m_CreateEvent = std::bind(&XApplicationEventHandler::OnCreate, m_ApplicationEventHandler);
		m_DestroyEvent = std::bind(&XApplicationEventHandler::OnDestroy, m_ApplicationEventHandler);
		m_TickEvent = std::bind(&XApplicationEventHandler::OnUpdate, m_ApplicationEventHandler, std::placeholders::_1);
		m_RenderEvent = std::bind(&XApplicationEventHandler::OnRender, m_ApplicationEventHandler, std::placeholders::_1);
		m_PauseEvent = std::bind(&XApplicationEventHandler::OnPause, m_ApplicationEventHandler);
		m_ResumeEvent = std::bind(&XApplicationEventHandler::OnResume, m_ApplicationEventHandler);
	}

	void XApplication::SetGL(std::shared_ptr<XGL> gl)
	{
		m_GL = gl;
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션 리스너 반환.
	/////////////////////////////////////////////////////////////////////////////
	std::shared_ptr<XApplicationEventHandler> XApplication::GetApplicationListener()
	{
		return m_ApplicationEventHandler;
	}

	std::shared_ptr<XGL> XApplication::GetGL()
	{
		return m_GL;
	}

	bool XApplication::IsPlaying()
	{
		return m_IsPlaying;
	}
}