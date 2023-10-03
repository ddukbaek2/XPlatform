#pragma once

//#define XPLATFORM_WINDOWS

#include "Application.h"
#include "IGL.h"
#include "Node.h"
#include "Scene.h"

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
//namespace XPlatform
//{
//	class ApplicationEventHandler : public ApplicationEventHandler
//	{
//	protected:
//		std::shared_ptr<Node> m_RootNode;
//
//	protected:
//		void OnCreate() override;
//		void OnDestroy() override;
//		void OnUpdate(float deltaTime) override;
//		void OnRender(std::shared_ptr<IGL> gl) override;
//		void OnPause() override;
//		void OnResume() override;
//
//		//virtual void OnKeyPress(int keyCode) override;
//	};
//}


/////////////////////////////////////////////////////////////////////////////
// @ 진입씬.
/////////////////////////////////////////////////////////////////////////////
class InitializeScene : public XPlatform::Scene
{
private:
	typedef XPlatform::Scene Base;

public:
	void OnCreate() override;
	void OnDestroy() override;
	void OnRender(std::shared_ptr<XPlatform::IGL> gl) override;
};
