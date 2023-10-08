#pragma once

#ifndef XPLATFORM_WINDOWS
#define XPLATFORM_WINDOWS
#endif

#include "Application.h"
#include "IGL.h"
#include "Node.h"
#include "Scene.h"

using namespace XPlatform;


/////////////////////////////////////////////////////////////////////////////
// @ 초기화씬.
/////////////////////////////////////////////////////////////////////////////
class InitializeOnLoadScene : public Scene
{
private:
	typedef Scene Base;

public:
	void OnCreate() override;
	void OnDestroy() override;
	void OnPause() override;
	void OnResume() override;
	void OnUpdate(float deltaTime) override;
	void OnRender(Ref<IGL> gl) override;
};
