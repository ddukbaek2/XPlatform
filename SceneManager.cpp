#include "SceneManager.h"


namespace XPlatform
{
	void SceneManager::OnCreate()
	{
	}

	void SceneManager::OnDestroy()
	{
		m_Scenes.clear();
	}

	void SceneManager::OnPause()
	{
		for (auto scene : m_Scenes)
		{
			scene->OnPause();
		}
	}

	void SceneManager::OnResume()
	{
		for (auto scene : m_Scenes)
		{
			scene->OnResume();
		}
	}

	void SceneManager::OnUpdate(float deltaTime)
	{
		for (auto scene : m_Scenes)
		{
			scene->OnUpdate(deltaTime);
		}
	}

	void SceneManager::OnRender(Ref<IGL> gl)
	{
		for (auto scene : m_Scenes)
		{
			scene->OnRender(gl);
		}
	}

	void SceneManager::Play(Ref<Scene> scene, bool pauseAllOtherScenes)
	{
	}

	void SceneManager::Stop(Ref<Scene> scene)
	{
	}

	void SceneManager::Pause(Ref<Scene> scene)
	{
	}

	void SceneManager::Resume(Ref<Scene> scene)
	{
	}

	bool SceneManager::IsPlaying(Ref<Scene> scene)
	{
		return false;
	}

	void SceneManager::Add(Ref<Scene> scene)
	{
		m_Scenes.push_back(scene);
	}

	void SceneManager::Remove(Ref<Scene> scene)
	{
		if (scene == nullptr)
			return;

		auto it = std::find(m_Scenes.begin(), m_Scenes.end(), scene);
		if (it == m_Scenes.end())
			return;

		m_Scenes.erase(it);
	}

	void SceneManager::RemoveAt(uint32_t index)
	{
		if (index >= m_Scenes.size())
			return;

		auto it = m_Scenes.begin() + index;
		m_Scenes.erase(it);
	}

	Ref<Scene> SceneManager::GetScene(String& sceneName)
	{
		if (sceneName.empty())
			return nullptr; // std::shared_ptr(nullptr);

		for (auto it = m_Scenes.begin(); it != m_Scenes.end(); ++it)
		{
			auto scene = *it;
			if (scene->m_Name == sceneName)
				return scene;
		}

		return nullptr; // std::shared_ptr(nullptr);
	}

	Ref<Scene> SceneManager::GetSceneAt(uint32_t index)
	{
		if (index >= m_Scenes.size())
			return nullptr; // std::shared_ptr(nullptr);

		return m_Scenes.at(index);
	}
}
