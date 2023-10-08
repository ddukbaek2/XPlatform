#include "Application.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 생성자.
	/////////////////////////////////////////////////////////////////////////////
	Application::Application()
	{
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
		m_SceneManager = CreateRef<SceneManager>();
		m_SceneManager->OnCreate();
	}

	void Application::OnStart(Ref<Scene> initializeOnLoadScene)
	{
		m_SceneManager->Add(initializeOnLoadScene);
		m_SceneManager->Play(initializeOnLoadScene);
	}

	void Application::OnDestroy()
	{
		m_SceneManager->OnDestroy();
	}

	void Application::OnPause()
	{
		m_SceneManager->OnPause();
	}

	void Application::OnResume()
	{
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
		//auto deltaTime = currentTime - m_PreviousTime; // std::chrono::duration<float>
		auto deltaTime = std::chrono::duration_cast<std::chrono::duration<float>>(currentTime - m_PreviousTime);
		{
			m_DeltaTime = deltaTime.count();
			OnUpdate(m_DeltaTime);
			OnRender(gl);
		}

		m_PreviousTime = currentTime;
	}

	/////////////////////////////////////////////////////////////////////////////
	// @ OpenGL 셋팅.
	/////////////////////////////////////////////////////////////////////////////
	void Application::SetGL(Ref<IGL> gl)
	{
		m_GL = gl;
	}

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
