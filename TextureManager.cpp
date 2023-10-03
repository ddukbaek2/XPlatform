#include "TextureManager.h"

namespace XPlatform
{
	TextureManager::TextureManager()
	{
	}

	TextureManager::~TextureManager()
	{
	}

	void TextureManager::Add(const String& key, const Texture& texture)
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
}
