#pragma once
#include "XPlatform.h"
#include "Object.h"
#include "XString.h"
#include "Node.h"


namespace XPlatform
{
	class Scene : public Object
	{
	protected:
		XString m_Name;
		bool m_IsVisible;
		std::shared_ptr<Node> m_RootNode;

	public:
		Scene();
		virtual ~Scene();

		void SetVisible(bool visible);
		bool IsVisible();
	};
}