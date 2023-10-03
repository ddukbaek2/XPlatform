#include "Scene.h"


namespace XPlatform
{
	Scene::Scene()
	{
		m_IsVisible = true;
		m_RootNode = std::make_shared<Node>();
		OnCreate();
	}

	Scene::~Scene()
	{
		OnDestroy();
		auto rootNode = m_RootNode.get();
		m_RootNode.reset();

		//rootNode->destroy
	}

	void Scene::OnCreate()
	{
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

	void Scene::OnDestroy()
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

	void Scene::OnRender(std::shared_ptr<XPlatform::IGL> gl)
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
