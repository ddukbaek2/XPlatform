#include "Node.h"
#include <sstream>
#include <cwchar>


namespace XPlatform
{
	void Node::OnCreate()
	{
		m_Parent = nullptr;
		m_Name.clear();
		m_FullName.clear();
		m_Children.clear();
		m_IsActive = true;
	}

	void Node::OnDestroy()
	{
		RemoveChildren();
	}

	void Node::SetFullName()
	{
		std::stringstream stringStream;
		std::vector<Ref<Node>> nodes;

		auto currentNode = GetRef<Node>();
		while (currentNode != nullptr)
		{
			nodes.push_back(currentNode);
			currentNode = currentNode->m_Parent;
		}

		for (auto it = nodes.rbegin(); it != nodes.rend(); ++it)
		{
			auto& node = *it;

			if (it == nodes.rbegin())
			{
				stringStream << UTF8("") << node->m_Name;
			}
			else
			{
				stringStream << UTF8("/") << node->m_Name;
			}
		}

		auto fullname = stringStream.str();
		m_FullName.assign(fullname);
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

		auto& parent = m_Parent;
		while (parent != nullptr)
		{
			if (!parent->IsActiveSelf())
				return false;

			parent = parent->m_Parent;
		}

		return true;
	}

	void Node::SetName(const String& nodeName)
	{
		m_Name.assign(nodeName);
		SetFullName();
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

	bool Node::Contains(Ref<Node> childNode, bool checkHierarchy)
	{
		if (childNode == nullptr)
			return false;

		for (auto it = m_Children.begin(); it != m_Children.end(); ++it)
		{
			auto& currentNode = *it;
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

	Ref<Node> Node::FindChild(const String& nodeName)
	{
		for (auto it = m_Children.begin(); it != m_Children.end(); ++it)
		{
			auto& childNode = *it;
			if (childNode->m_Name == nodeName)
				return childNode;
		}

		return nullptr;
	}

	void Node::AddChild(Ref<Node> childNode)
	{
		if (childNode == nullptr)
			return;

		if (childNode->m_Parent == GetRef<Node>())
			return;

		if (childNode->m_Parent != nullptr)
		{
			childNode->m_Parent->RemoveChild(childNode);
			childNode->m_Parent = nullptr;
		}

		m_Children.emplace_back(childNode);
		childNode->m_Parent = GetRef<Node>();
		childNode->SetFullName();
	}

	void Node::RemoveChild(Ref<Node> childNode)
	{
		if (childNode == nullptr)
			return;

		auto it = std::find(m_Children.begin(), m_Children.end(), childNode);
		if (it == m_Children.end())
			return;

		m_Children.erase(it);

		if (childNode->m_Parent == GetRef<Node>())
			childNode->m_Parent = nullptr;

		childNode->SetFullName();
	}

	void Node::RemoveChildren()
	{
		for (auto it = m_Children.begin(); it != m_Children.end(); ++it)
		{
			auto& childNode = *it;
			m_Children.erase(it);

			if (childNode->m_Parent == GetRef<Node>())
				childNode->m_Parent = nullptr;
		}
	}

	bool Node::IsRootNode()
	{
		return m_Parent == nullptr;
	}

	const String& Node::GetName()
	{
		return m_Name;
	}

	const String& Node::GetFullName()
	{
		return m_FullName;
	}

	size_t Node::GetChildCount()
	{
		return m_Children.size();
	}

	Ref<Node> Node::GetParent()
	{
		return m_Parent;
	}

	Ref<Node> Node::GetChild(uint32_t childIndex)
	{
		if (childIndex < m_Children.size())
			return nullptr;

		return m_Children[childIndex];
	}
}
