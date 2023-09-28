#include "Scene.h"


namespace XPlatform
{
	Scene::Scene()
	{
		m_IsVisible = true;
		m_RootNode = std::make_shared<Node>();
	}

	Scene::~Scene()
	{
		m_RootNode.reset();
	}

	void Scene::SetVisible(bool visible)
	{
		m_IsVisible = visible;	
	}

	bool Scene::IsVisible()
	{
		return m_IsVisible;
	}
}