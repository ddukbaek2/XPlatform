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
		std::shared_ptr<Node> m_Parent;
		std::vector<std::shared_ptr<Node>> m_Children;
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
		bool Contains(std::shared_ptr<Node> childNode, bool checkHierarchy = false);
		std::shared_ptr<Node> FindChild(String& nodeName);
		void AddChild(std::shared_ptr<Node> childNode);
		void RemoveChild(std::shared_ptr<Node> childNode);
		void RemoveChildren();
		bool IsRootNode();
		String& GetName();
		String& GetFullName();
		unsigned int GetChildCount();
		std::shared_ptr<Node> GetParent();
		std::shared_ptr<Node> GetChild(uint32_t childIndex);
	};
}
