#pragma once

#include "XPlatform.h"

/*
* 공통 기능.
*	- 내부 뷰영역을 화면영역과 동일하게 가져갈 것인지 별도로 정할 것인지.
* 
* 윈도우 / 맥 / 리눅스 같은 데스크탑 전용 기능.
*	- 전체화면 / 윈도우전체화면 / 윈도우화면

* 
* 아이폰 / 안드로이드 같은 모바일 전용 기능.
*	- 
* 
*/
namespace XPlatform
{
	class ApplicationListener : public IApplicationListener
	{
	private:

	public:
		ApplicationListener();
		virtual ~ApplicationListener();

	protected:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;
		virtual void OnUpdate(float deltaTime) override;
		virtual void OnRender(IGL* gl) override;
		virtual void OnPause() override;
		virtual void OnResume() override;

		//virtual void OnKeyPress(int keyCode) override;
	};
}