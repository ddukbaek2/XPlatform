#pragma once
#include "XPlatform.h"
#include "Object.h"
#include "String.h"
#include "Node.h"


namespace XPlatform
{
	class Scene : public Object
	{
	protected:
		std::wstring m_Name;
		bool m_IsVisible;
		std::shared_ptr<Node> m_RootNode;

	public:
		Scene();
		virtual ~Scene();

		void SetVisible(bool visible);
		bool IsVisible();
	};
}