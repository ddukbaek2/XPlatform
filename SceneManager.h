#pragma once
#include "XPlatform.h"
#include "SharedClass.h"
#include "String.h"
#include "Scene.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 씬매니저.
	/////////////////////////////////////////////////////////////////////////////
	class SceneManager
	{
	private:
		std::vector<std::shared_ptr<Scene>> m_Scenes;
		std::vector<std::shared_ptr<Scene>> m_ActiveScenes;

	public:
		void Add(std::shared_ptr<Scene> scene);
		void Remove(std::shared_ptr<Scene> scene);
		void RemoveAt(uint32_t index);
		std::shared_ptr<Scene> GetScene(const wchar_t* sceneName);
		std::shared_ptr<Scene> GetSceneAt(uint32_t index);
	};
}
