#pragma once
#include "XPlatform.h"
#include "Object.h"
#include "String.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 노드.
	/////////////////////////////////////////////////////////////////////////////
	class Node : public Object
	{
	private:
		String m_Name;
		String m_FullName;
		Node* m_Parent;
		std::vector<Node*> m_Children;
		bool m_IsActive;

	public:
		Node();
		virtual ~Node();

	private:
		void SetFullName();

	public:
		void SetActiveSelf(bool active);
		bool IsActiveSelf();
		bool IsActiveInHierarchy();

	public:
		void SetName(const String& nodeName);

		void SetSiblingIndex(uint32_t siblingIndex);
		void SetFirstSibling();
		void SetLastSibling();
		bool Contains(Node* childNode, bool checkHierarchy = false);
		Node* FindChild(String& nodeName);
		void AddChild(Node* childNode);
		void RemoveChild(Node* childNode);
		void RemoveChildren();
		bool IsRootNode();
		String& GetName();
		String& GetFullName();
		unsigned int GetChildCount();
		const Node* GetParent();
		const Node* GetChild(uint32_t childIndex);
	};
}
