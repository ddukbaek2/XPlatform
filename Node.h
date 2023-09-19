#pragma once
#include "XPlatform.h"
#include "Object.h"


namespace XPlatform
{
	class Node : public Object
	{
	private:
		Node* m_Parent;
		std::vector<Node*> m_Children;

	public:
		Node();
		virtual ~Node();
		void AddChild(Node* childNode);
		void RemoveChild(Node* childNode);
		std::vector<Node*> GetChildren();
	};
}