#include "TextureManager.h"

namespace XPlatform
{
	TextureManager::TextureManager()
	{
		m_Textures.clear();
	}

	TextureManager::~TextureManager()
	{
	}

	void TextureManager::OnCreate()
	{
	}

	void TextureManager::OnDestroy()
	{
	}


	void TextureManager::Add(const String& key, Ref<Texture> texture)
	{
		auto it = m_Textures.find(key);
		if (it != m_Textures.end())
			return;

		m_Textures.emplace(key, texture);
	}

	void TextureManager::Remove(const String& key)
	{
		auto it = m_Textures.find(key);
		if (it == m_Textures.end())
			return;

		m_Textures.erase(it);
	}

	Ref<Texture> TextureManager::Get(const String& key)
	{
		auto it = m_Textures.find(key);
		if (it == m_Textures.end())
			return nullptr;

		auto pair = *it;
		return pair.second;
	}

	bool TextureManager::Contains(const String& key)
	{
		auto exists = Get(key) == nullptr;
		return exists;
	}
}
