#pragma once

#include "XPlatform.h"
#include "Node.h"
#include "Vector3.h"


namespace XPlatform
{
	class TransformNode : public Node
	{
	protected:
		typedef Node Base;

	protected:
		Vector3 m_Position;
		Vector3 m_Scale;
		Vector3 m_EulerAngles;

	public:

	};
}
