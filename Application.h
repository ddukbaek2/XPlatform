#pragma once

#include "XPlatform.h"
#include "IGL.h"
#include "SceneManager.h"
#include "TextureManager.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션.
	/////////////////////////////////////////////////////////////////////////////
	class Application
	{
	protected:
		float m_DeltaTime;
		bool m_IsPlaying;
		std::chrono::system_clock::time_point m_PreviousTime;
		Ref<IGL> m_GL;
		Ref<SceneManager> m_SceneManager;
		Ref<TextureManager> m_TextureManager;

	public:
		Application();
		virtual ~Application();

	protected:
		virtual void OnCreate();
		virtual void OnStart(Ref<Scene> initializeOnLoadScene);
		virtual void OnDestroy();
		virtual void OnPause();
		virtual void OnResume();
		virtual void OnUpdate(float deltaTime);
		virtual void OnRender(Ref<IGL> gl);
		virtual void OnMainLoop();

	public:
		void SetGL(Ref<IGL> gl);
		Ref<IGL> GetGL();
		bool IsPlaying();
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션 실행.
	/////////////////////////////////////////////////////////////////////////////
	int32_t StartApplication(Ref<Scene> initializeOnLoadScene, int32_t width, int32_t height, bool useFullscreen);

	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션 종료.
	/////////////////////////////////////////////////////////////////////////////
	void QuitApplication();

	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션 객체 반환.
	/////////////////////////////////////////////////////////////////////////////
	Ref<Application> GetApplication();
}
