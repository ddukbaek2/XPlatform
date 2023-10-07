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
		Ref<Node> m_Parent;
		std::vector<Ref<Node>> m_Children;
		bool m_IsActive;

	protected:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;

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
		bool Contains(Ref<Node> childNode, bool checkHierarchy = false);
		Ref<Node> FindChild(String& nodeName);
		void AddChild(Ref<Node> childNode);
		void RemoveChild(Ref<Node> childNode);
		void RemoveChildren();
		bool IsRootNode();
		String& GetName();
		String& GetFullName();
		unsigned int GetChildCount();
		Ref<Node> GetParent();
		Ref<Node> GetChild(uint32_t childIndex);
	};
}
