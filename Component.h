#pragma once

#include "Object.h"

namespace XPlatform
{
	class Component : public Object
	{
	protected:
	public:
	protected:
		void OnCreate() override;
		void OnDestroy() override;

		virtual void OnEnable() = 0;
		virtual void OnDisable() = 0;
		virtual void OnUpdate(float deltaTime) = 0;
	};

	RegisterObject(Component);
}