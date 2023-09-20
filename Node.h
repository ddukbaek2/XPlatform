#pragma once
#include "XPlatform.h"
#include "Object.h"


namespace XPlatform
{
	class Node : public Object
	{
	private:
		std::wstring m_Name;
		std::wstring m_FullName;
		Node* m_Parent;
		std::vector<Node*> m_Children;

	public:
		Node();
		virtual ~Node();

	private:
		void SetFullName();

	protected:
		virtual void OnDestroy() override;

	public:
		void SetName(const wchar_t* nodeName);
		void SetSiblingIndex(unsigned int siblingIndex);
		void SetFirstSibling();
		void SetLastSibling();
		void Contains(Node* childNode, bool checkHeirarchy = false);
		void FindChild(const wchar_t* nodeName);
		void AddChild(Node* childNode);
		void RemoveChild(Node* childNode);
		void RemoveChildren();
		bool IsRootNode();
		const wchar_t* GetName();
		const wchar_t* GetFullName();
		unsigned int GetChildCount();
		const Node* GetParent();
		const Node* GetChild(unsigned int childIndex);
		//std::vector<Node*> GetChildren();
	};
}