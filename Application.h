#pragma once

#include "XPlatform.h"
#include "IGL.h"
#include "SceneManager.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 실제 애플리케이션 객체.
	/////////////////////////////////////////////////////////////////////////////
	class Application
	{
	protected:
		//std::shared_ptr<ApplicationEventHandler> m_ApplicationEventHandler;
		//VoidCallback m_CreateEvent;
		//VoidCallback m_DestroyEvent;
		//VoidCallback m_PauseEvent;
		//VoidCallback m_ResumeEvent;
		//FloatCallback m_TickEvent;
		//IGLCallback m_RenderEvent;
		float m_DeltaTime;
		bool m_IsPlaying;
		std::chrono::system_clock::time_point m_PreviousTime;
		std::shared_ptr<IGL> m_GL;
		std::shared_ptr<SceneManager> m_SceneManager;

	public:
		Application();
		virtual ~Application();

	protected:
		virtual void OnCreate();
		virtual void OnDestroy();
		virtual void OnPause();
		virtual void OnResume();
		virtual void OnUpdate(float deltaTime);
		virtual void OnRender(std::shared_ptr<IGL> gl);
		virtual void OnMainLoop();

	public:
		//void SetApplicationListener(std::shared_ptr<ApplicationEventHandler> applicationEventHandler);
		void SetGL(std::shared_ptr<IGL> gl);
		//std::shared_ptr<ApplicationEventHandler> GetApplicationListener();
		std::shared_ptr<IGL> GetGL();
		bool IsPlaying();
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 실행.
	/////////////////////////////////////////////////////////////////////////////
	void StartApplication(std::shared_ptr<Scene> scene, int width, int height, bool useFullscreen);

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 종료.
	/////////////////////////////////////////////////////////////////////////////
	void QuitApplication();

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 객체 반환.
	/////////////////////////////////////////////////////////////////////////////
	Application* GetApplication();

	///////////////////////////////////////////////////////////////////////////////
	//// @ 애플리케이션 이벤트 핸들러.
	///////////////////////////////////////////////////////////////////////////////
	//class ApplicationEventHandler
	//{
	//public:
	//	friend class Application;

	//protected:
	//	virtual void OnCreate() = 0;
	//	virtual void OnDestroy() = 0;
	//	virtual void OnUpdate(float deltaTime) = 0;
	//	virtual void OnRender(std::shared_ptr<IGL> gl) = 0;
	//	virtual void OnPause() = 0;
	//	virtual void OnResume() = 0;

	//	//virtual void OnOrientation() = 0;
	//	//virtual void OnResize(int width, int height) = 0;
	//	//virtual void OnTouchPress(float x, float y) = 0;
	//	// virtual void OnTouchDrag(float x, float y) = 0;
	//	//virtual void OnTouchRelease(float x, float y) = 0;
	//	//virtual void OnKeyPress(int keyCode) = 0;
	//	//virtual void OnKeyRelease(int keyCode) = 0;
	//};
}
