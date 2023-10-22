#pragma once

#include "XPlatform.h"
#include "Object.h"


namespace XPlatform
{
	class Asset : public Object
	{
	private:
		typedef Object Base;

	private:
		uint64_t m_GUID;
		String m_AssetPath;
		String m_AssetName;

		Ref<Asset> m_Parent;
		std::vector<Ref<Asset>> m_Children;

	protected:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;

	public:
		template<typename T> static typename std::enable_if<std::is_base_of<Asset, T>::value, Ref<T>>::type CreateAsset()
		{
			auto asset = CreateRef<T>();
			auto shared = asset->shared_from_this();
			return CastRef<T>(shared);
		};

		template<typename T> static typename std::enable_if<std::is_base_of<Asset, T>::value, Ref<T>>::type LoadAsset(const String& assetPath)
		{
			auto asset = Asset::CreateAsset<T>();
			//return CastRef<T>(shared);
			return asset;
		};

		static void UnloadAsset(Ref<Asset> asset);
		static void SaveAsset(const String& assetPath, Ref<Asset> asset);
		static bool IsValid(Ref<Asset> asset);
		static bool IsLoaded(Ref<Asset> asset);
	};
}
