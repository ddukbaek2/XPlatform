#include "Node.h"

namespace XPlatform
{
	Node::Node()
	{
		m_Parent = nullptr;
		m_Children.clear();
	}

	Node::~Node()
	{
	}

	void Node::AddChild(Node* childNode)
	{
		m_Children.emplace_back(childNode);
	}

	void Node::RemoveChild(Node* childNode)
	{
		auto it = std::find(m_Children.begin(), m_Children.end(), childNode);
		if (it != m_Children.end())
		{
			m_Children.erase(it);
		}
	}

	std::vector<Node*> Node::GetChildren()
	{
		return m_Children;
	}
}