#pragma once

#include "XPlatform.h"
#include "Object.h"


namespace XPlatform
{
	class Asset : public Object
	{
	private:
		typedef Object Base;

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

		static void SaveAsset(const String& assetPath, Ref<Asset> asset);
	};
}
