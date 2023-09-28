#include "SceneManager.h"


namespace XPlatform
{
	void SceneManager::Add(std::shared_ptr<Scene> scene)
	{
		m_Scenes.push_back(scene);
	}

	void SceneManager::Remove(std::shared_ptr<Scene> scene)
	{
		if (scene == nullptr)
			return;

		auto it = std::find(m_Scenes.begin(), m_Scenes.end(), scene);
		if (it == m_Scenes.end())
			return;

		m_Scenes.erase(it);
	}

	void SceneManager::RemoveAt(uint32_t index) {}
	Scene* SceneManager::GetScene(const wchar_t* sceneName) { return nullptr; }
	Scene* SceneManager::GetSceneAt(uint32_t index) { return nullptr; }
}