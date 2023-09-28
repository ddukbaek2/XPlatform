#pragma once
#include "XPlatform.h"
#include "SharedClass.h"
#include "String.h"
#include "Scene.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ ¾À¸Å´ÏÀú.
	/////////////////////////////////////////////////////////////////////////////
	class SceneManager : public SharedClass<SceneManager>
	{
	private:
		std::vector<std::shared_ptr<Scene>> m_Scenes;
		std::vector<std::shared_ptr<Scene>> m_ActiveScenes;

	public:
		void Add(std::shared_ptr<Scene> scene);
		void Remove(std::shared_ptr<Scene> scene);
		void RemoveAt(uint32_t index);
		Scene* GetScene(const wchar_t* sceneName);
		Scene* GetSceneAt(uint32_t index);
	};
}