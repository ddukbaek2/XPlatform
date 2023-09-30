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

	protected:
		virtual void OnCreate() = 0;
		virtual void OnDestroy() = 0;
		virtual void OnPause() = 0;
		virtual void OnResume() = 0;
		virtual void OnTick(float deltaTime) = 0;
		virtual void OnRender() = 0;

	public:
		Scene();
		virtual ~Scene();

		void SetVisible(bool visible);
		bool IsVisible();
	};
}