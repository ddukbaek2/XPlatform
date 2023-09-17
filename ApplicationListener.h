#pragma once

#include "XPlatform.h"

namespace XPlatform
{
	class ApplicationListener : public IApplicationListener
	{
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
	};
}