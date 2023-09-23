#pragma once
#include "XPlatform.h"
#include "SharedClass.h"
#include "String.h"
#include "Scene.h"


namespace XPlatform
{
	class SceneManager : public SharedClass<SceneManager>
	{
	private:
		std::vector<Scene*> m_Scenes;
		std::vector<Scene*> m_ActiveScenes;

	public:
		void Add(Scene* scene);
		void Remove(Scene* scene);
		void RemoveAt(uint32_t index);
		Scene* GetScene(const wchar_t* sceneName);
		Scene* GetSceneAt(uint32_t index);
	};
}