#pragma once
#include "XPlatform.h"


namespace XPlatform
{
	class Node
	{
	public:
		Node* m_Parent;
		std::vector<Node*> m_Children;

	};
}