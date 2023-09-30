#pragma once

#include "XPlatform.h"
#include "XGL.h"
#include "SceneManager.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 실제 애플리케이션 객체.
	/////////////////////////////////////////////////////////////////////////////
	class XApplication
	{
	protected:
		std::shared_ptr<XApplicationEventHandler> m_ApplicationEventHandler;
		VoidFunction m_CreateEvent;
		VoidFunction m_DestroyEvent;
		VoidFunction m_PauseEvent;
		VoidFunction m_ResumeEvent;
		FloatFunction m_TickEvent;
		XGLFunction m_RenderEvent;
		float m_DeltaTime;
		bool m_IsPlaying;
		std::chrono::system_clock::time_point m_PreviousTime;
		std::shared_ptr<XGL> m_GL;
		std::shared_ptr<SceneManager> m_SceneManager;

	public:
		XApplication();
		virtual ~XApplication();

	protected:
		virtual void OnCreate();
		virtual void OnDestroy();
		virtual void OnPause();
		virtual void OnResume();
		virtual void OnMainLoop();

	public:
		void SetApplicationListener(std::shared_ptr<XApplicationEventHandler> applicationEventHandler);
		void SetGL(std::shared_ptr<XGL> gl);
		std::shared_ptr<XApplicationEventHandler> GetApplicationListener();
		std::shared_ptr<XGL> GetGL();
		bool IsPlaying();
	};

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 실행.
	/////////////////////////////////////////////////////////////////////////////
	void StartApplication(std::shared_ptr<XApplicationEventHandler> applicationEventHandler, int width, int height, bool useFullscreen);

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 종료.
	/////////////////////////////////////////////////////////////////////////////
	void QuitApplication();

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 실행중인지 여부.
	/////////////////////////////////////////////////////////////////////////////
	bool IsRunningApplication();

	/////////////////////////////////////////////////////////////////////////////
	// @ 어플리케이션 객체 반환.
	/////////////////////////////////////////////////////////////////////////////
	XApplication* GetApplication();

	/////////////////////////////////////////////////////////////////////////////
	// @ 애플리케이션 이벤트 핸들러.
	/////////////////////////////////////////////////////////////////////////////
	class XApplicationEventHandler
	{
	public:
		friend class XApplication;

	protected:
		virtual void OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void OnUpdate(float deltaTime) = 0;
		virtual void OnRender(std::shared_ptr<XGL> gl) = 0;
		virtual void OnPause() = 0;
		virtual void OnResume() = 0;

		//virtual void OnOrientation() = 0;
		//virtual void OnResize(int width, int height) = 0;
		//virtual void OnTouchPress(float x, float y) = 0;
		// virtual void OnTouchDrag(float x, float y) = 0;
		//virtual void OnTouchRelease(float x, float y) = 0;
		//virtual void OnKeyPress(int keyCode) = 0;
		//virtual void OnKeyRelease(int keyCode) = 0;
	};
}