#include "Scene.h"


namespace XPlatform
{
	void Scene::OnCreate()
	{
		Base::OnCreate();

		m_IsPlaying = false;
		m_IsVisible = true;
		m_RootNode = CreateRef<Node>();
	}

	void Scene::OnDestroy()
	{
		Base::OnDestroy();
	}

	void Scene::OnLoadStarted()
	{
	}

	void Scene::OnLoadCompleted()
	{
	}

	void Scene::OnUnloadStarted()
	{
	}

	void Scene::OnUnloadCompleted()
	{
	}

	void Scene::OnPause()
	{
	}

	void Scene::OnResume()
	{
	}

	void Scene::OnUpdate(float deltaTime)
	{
	}

	void Scene::OnRender(Ref<XPlatform::IGL> gl)
	{
	}

	void Scene::SetVisible(bool visible)
	{
		m_IsVisible = visible;	
	}

	bool Scene::IsVisible()
	{
		return m_IsVisible;
	}

	std::shared_ptr<Node> Scene::GetRootNode()
	{
		return m_RootNode;
	}
}
