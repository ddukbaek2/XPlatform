#include "Node.h"
#include <sstream>


namespace XPlatform
{
	Node::Node()
	{
		m_Parent = nullptr;
		m_Name.clear();
		m_FullName.clear();
		m_Children.clear();
	}

	Node::~Node()
	{
	}

	void Node::SetFullName()
	{
		std::wstringstream ss;
		std::vector<Node*> nodes;

		auto currentNode = this;
		while (currentNode != nullptr)
		{
			nodes.push_back(currentNode);
			currentNode = currentNode->m_Parent;
		}

		for (auto it = nodes.rbegin(); it != nodes.rend(); ++it)
		{
			auto node = *it;

			if (it == nodes.rbegin())
			{
				ss << L"" << node->m_Name;
			}
			else
			{
				ss << L"/" << node->m_Name;
			}
		}

		m_FullName.clear();
		m_FullName = ss.str();
	}

	void Node::OnDestroy()
	{
		RemoveChildren();
	}


	void Node::SetName(const wchar_t* nodeName)
	{
		m_Name = nodeName;
		SetFullName();
	}

	void Node::SetSiblingIndex(unsigned int siblingIndex)
	{
		if (m_Parent == nullptr)
			return;


	}

	void Node::SetFirstSibling()
	{
	}

	void Node::SetLastSibling()
	{
	}

	bool Node::Contains(Node* childNode, bool checkHeirarchy)
	{
		childNode
		if ()
	}

	void Node::FindChild(const wchar_t* nodeName)
	{
		for (auto it = m_Children.begin(); it != m_Children.end(); ++it)
		{
			auto childNode = *it;
			//childNode->m_Name.compare()
		}
	}

	void Node::AddChild(Node* childNode)
	{
		if (childNode == nullptr)
			return;

		if (childNode->m_Parent == this)
			return;

		if (childNode->m_Parent != nullptr)
		{
			childNode->m_Parent->RemoveChild(childNode);
			childNode->m_Parent = nullptr;
		}

		m_Children.emplace_back(childNode);
		childNode->m_Parent = this;
		childNode->SetFullName();
	}

	void Node::RemoveChild(Node* childNode)
	{
		if (childNode == nullptr)
			return;

		auto it = std::find(m_Children.begin(), m_Children.end(), childNode);
		if (it == m_Children.end())
			return;

		m_Children.erase(it);

		if (childNode->m_Parent == this)
			childNode->m_Parent = nullptr;

		childNode->SetFullName();
	}

	void Node::RemoveChildren()
	{
		for (auto it = m_Children.begin(); it != m_Children.end(); ++it)
		{
			auto childNode = *it;
			m_Children.erase(it);

			if (childNode->m_Parent == this)
				childNode->m_Parent = nullptr;
		}
	}

	bool Node::IsRootNode()
	{
		return m_Parent == nullptr;
	}

	const wchar_t* Node::GetName()
	{
		return m_Name.c_str();
	}

	const wchar_t* Node::GetFullName()
	{
		return m_FullName.c_str();
	}

	unsigned int Node::GetChildCount()
	{
		return m_Children.size();
	}

	const Node* Node::GetParent()
	{
		return m_Parent;
	}

	const Node* Node::GetChild(unsigned int childIndex)
	{
		if (childIndex < m_Children.size())
			return nullptr;

		return m_Children[childIndex];
	}

	//std::vector<Node*> Node::GetChildren()
	//{
	//	return m_Children;
	//}
}