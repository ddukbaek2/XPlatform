#pragma once
#include "XPlatform.h"
#include "Object.h"
#include "XString.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 노드.
	/////////////////////////////////////////////////////////////////////////////
	class Node : public Object
	{
	private:
		XString m_Name;
		XString m_FullName;
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
		void SetName(const XString& nodeName);

		void SetSiblingIndex(uint32_t siblingIndex);
		void SetFirstSibling();
		void SetLastSibling();
		bool Contains(Node* childNode, bool checkHierarchy = false);
		Node* FindChild(XString& nodeName);
		void AddChild(Node* childNode);
		void RemoveChild(Node* childNode);
		void RemoveChildren();
		bool IsRootNode();
		XString& GetName();
		XString& GetFullName();
		unsigned int GetChildCount();
		const Node* GetParent();
		const Node* GetChild(uint32_t childIndex);
	};
}