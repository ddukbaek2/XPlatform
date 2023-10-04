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
		std::vector<Ref<Scene>> m_Scenes;

	protected:
		virtual void OnCreate();
		virtual void OnDestroy();
		virtual void OnPause();
		virtual void OnResume();
		virtual void OnUpdate(float deltaTime);
		virtual void OnRender(Ref<IGL> gl);

	public:
		void Play(Ref<Scene> scene, bool pauseAllOtherScenes = true);
		void Stop(Ref<Scene> scene);
		void Pause(Ref<Scene> scene);
		void Resume(Ref<Scene> scene);
		bool IsPlaying(Ref<Scene> scene);

		void Add(Ref<Scene> scene);
		void Remove(Ref<Scene> scene);
		void RemoveAt(uint32_t index);
		Ref<Scene> GetScene(String& sceneName);
		Ref<Scene> GetSceneAt(uint32_t index);
	};
}
