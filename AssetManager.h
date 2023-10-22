#pragma once

#include "XPlatform.h"
#include "Asset.h"



namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 어셋 매니저.
	/////////////////////////////////////////////////////////////////////////////
	class AssetManager
	{
	private:
		friend class Application;

	private:
		std::map<String, Ref<Asset>> m_Textures;

	protected:
		virtual void OnCreate();
		virtual void OnDestroy();

	public:
		AssetManager();
		virtual ~AssetManager();

		void Add(const String& key, Ref<Asset> texture);
		void Remove(const String& key);

		Ref<Asset> Get(const String& key);
		bool Exists(const String& key);
	};
}