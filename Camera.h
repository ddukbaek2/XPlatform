#pragma once

#include "XPlatform.h"
#include "Object.h"
#include "Vector3.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 카메라.
	/////////////////////////////////////////////////////////////////////////////
	class Camera : public Object
	{
	private:
		typedef Object Base;

	public:
		void SetPosition(const Vector3& position);
		void SetEulerAngles(const Vector3& eulerAngles);
	};
}
