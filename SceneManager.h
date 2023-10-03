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
	public:
		friend class Application;

	private:
		std::vector<std::shared_ptr<Scene>> m_Scenes;

	protected:
		virtual void OnCreate();
		virtual void OnDestroy();
		virtual void OnPause();
		virtual void OnResume();
		virtual void OnUpdate(float deltaTime);
		virtual void OnRender(std::shared_ptr<IGL> gl);

	public:
		void Play(std::shared_ptr<Scene> scene, bool pauseAllOtherScenes = true);
		void Stop(std::shared_ptr<Scene> scene);
		void Pause(std::shared_ptr<Scene> scene);
		void Resume(std::shared_ptr<Scene> scene);
		bool IsPlaying(std::shared_ptr<Scene> scene);

		void Add(std::shared_ptr<Scene> scene);
		void Remove(std::shared_ptr<Scene> scene);
		void RemoveAt(uint32_t index);
		std::shared_ptr<Scene> GetScene(String& sceneName);
		std::shared_ptr<Scene> GetSceneAt(uint32_t index);
	};
}
