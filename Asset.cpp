#include "Asset.h"


namespace XPlatform
{
	void Asset::OnCreate()
	{
		Base::OnCreate();
	}

	void Asset::OnDestroy()
	{
		Base::OnDestroy();
	}

	void Asset::UnloadAsset(Ref<Asset> asset)
	{
	}

	void Asset::SaveAsset(const String& assetPath, Ref<Asset> asset)
	{

	}

	bool Asset::IsValid(Ref<Asset> asset)
	{
		return true;
	}

	bool Asset::IsLoaded(Ref<Asset> asset)
	{
		return true;
	}
}
