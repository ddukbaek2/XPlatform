#include "Scene.h"


namespace XPlatform
{
	void Scene::OnCreate()
	{
		m_IsVisible = true;
		m_RootNode = CreateInstance(Node);
	}

	void Scene::OnDestroy()
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