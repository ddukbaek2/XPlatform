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
		String m_Name;
		bool m_IsVisible;
		std::shared_ptr<Node> m_RootNode;

	protected:
		virtual void OnCreate() = 0;
		virtual void OnLoadStarted() = 0;
		virtual void OnLoadCompleted() = 0;
		virtual void OnUnloadStarted() = 0;
		virtual void OnUnloadCompleted() = 0;
		virtual void OnDestroy() = 0;
		virtual void OnPause() = 0;
		virtual void OnResume() = 0;
		virtual void OnUpdate(float deltaTime) = 0;
		virtual void OnRender() = 0;

	public:
		Scene();
		virtual ~Scene();

		void SetVisible(bool visible);
		bool IsVisible();
		bool IsLoaded();
	};
}
