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

	void SceneManager::OnRender(std::shared_ptr<IGL> gl)
	{
		for (auto scene : m_Scenes)
		{
			scene->OnRender(gl);
		}
	}

	void SceneManager::Play(std::shared_ptr<Scene> scene, bool pauseAllOtherScenes)
	{
	}

	void SceneManager::Stop(std::shared_ptr<Scene> scene)
	{
	}

	void SceneManager::Pause(std::shared_ptr<Scene> scene)
	{
	}

	void SceneManager::Resume(std::shared_ptr<Scene> scene)
	{
	}

	bool SceneManager::IsPlaying(std::shared_ptr<Scene> scene)
	{
		return false;
	}

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

	void SceneManager::RemoveAt(uint32_t index)
	{
		if (index >= m_Scenes.size())
			return;

		auto it = m_Scenes.begin() + index;
		m_Scenes.erase(it);
	}

	std::shared_ptr<Scene> SceneManager::GetScene(String& sceneName)
	{
		if (String::IsNullOrEmpty(sceneName))
			return nullptr; // std::shared_ptr<Scene>(nullptr);

		for (auto it = m_Scenes.begin(); it != m_Scenes.end(); ++it)
		{
			auto scene = (*it).get();
			//scene.getName();
		}

		return nullptr; // std::shared_ptr<Scene>(nullptr);
	}

	std::shared_ptr<Scene> SceneManager::GetSceneAt(uint32_t index)
	{
		if (index >= m_Scenes.size())
			return nullptr; // std::shared_ptr<Scene>(nullptr);

		return m_Scenes.at(index);
	}
}
