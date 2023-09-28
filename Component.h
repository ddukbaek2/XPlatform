#pragma once

#include "Object.h"

namespace XPlatform
{
	class Component : public Object
	{
	protected:
	public:
	protected:
		Component() { }
		virtual ~Component() { }

		virtual void OnEnable() = 0;
		virtual void OnDisable() = 0;
		virtual void OnUpdate(float deltaTime) = 0;
	};
}