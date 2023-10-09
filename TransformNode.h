#pragma once

#include "XPlatform.h"
#include "Node.h"
#include "Vector3.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 트랜스폼 노드.
	/////////////////////////////////////////////////////////////////////////////
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
