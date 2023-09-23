#include "Node.h"
#include <sstream>
#include <cwchar>


namespace XPlatform
{
	Node::Node()
	{
		m_Parent = nullptr;
		m_Name.clear();
		m_FullName.clear();
		m_Children.clear();
		m_IsActive = true;
	}

	Node::~Node()
	{
	}

	void Node::SetFullName()
	{
		std::wstringstream stringStream;
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
				stringStream << L"" << node->m_Name.c_str();
			}
			else
			{
				stringStream << L"/" << node->m_Name.c_str();
			}
		}

		auto fullname = stringStream.str();
		m_FullName.assign(fullname.c_str());
	}

	void Node::OnCreate()
	{
	}

	void Node::OnDestroy()
	{
		RemoveChildren();
	}

	void Node::SetActiveSelf(bool isActive)
	{
		m_IsActive = isActive;
	}

	bool Node::IsActiveSelf()
	{
		return m_IsActive;
	}

	bool Node::IsActiveInHierarchy()
	{
		if (!IsActiveSelf())
			return false;

		auto parent = m_Parent;
		while (parent != nullptr)
		{
			if (!parent->IsActiveSelf())
				return false;

			parent = parent->m_Parent;
		}

		return true;
	}

	void Node::SetName(const wchar_t* nodeName)
	{
		m_Name.assign(nodeName);
		SetFullName();
	}

	void Node::SetName(const std::wstring& nodeName)
	{
		m_Name.assign(nodeName);
	}

	void Node::SetSiblingIndex(uint32_t siblingIndex)
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

	bool Node::Contains(Node* childNode, bool checkHierarchy)
	{
		if (childNode == nullptr)
			return false;

		for (auto it = m_Children.begin(); it != m_Children.end(); ++it)
		{
			auto currentNode = *it;
			if (currentNode == childNode)
				return true;

			if (checkHierarchy)
			{
				if (currentNode->Contains(childNode, true))
					return true;
			}
		}

		return false;
	}

	Node* Node::FindChild(const wchar_t* nodeName)
	{
		for (auto it = m_Children.begin(); it != m_Children.end(); ++it)
		{
			auto childNode = *it;
			//childNode->m_Name.compare()
		}

		return nullptr;
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

	const Node* Node::GetChild(uint32_t childIndex)
	{
		if (childIndex < m_Children.size())
			return nullptr;

		return m_Children[childIndex];
	}
}