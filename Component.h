#pragma once

#include "Object.h"

namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 컴포넌트 : 노드에 부착되는 컴포넌트 요소.
	/////////////////////////////////////////////////////////////////////////////
	class Component : public Object
	{
	protected:
	public:
	protected:
		Component();
		virtual ~Component();

		virtual void OnEnable() = 0;
		virtual void OnDisable() = 0;
		virtual void OnUpdate(float deltaTime) = 0;
	};
}
