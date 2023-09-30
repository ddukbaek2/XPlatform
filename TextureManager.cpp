#include "TextureManager.h"

namespace XPlatform
{
	TextureManager::TextureManager()
	{
	}

	TextureManager::~TextureManager()
	{
	}

	void TextureManager::Add(const XString& key, const Texture& texture)
	{
		auto it = m_Textures.find(key);
		if (it != m_Textures.end())
			return;

		m_Textures.emplace(key, texture);
	}

	void TextureManager::Remove(const XString& key)
	{
		auto it = m_Textures.find(key);
		if (it == m_Textures.end())
			return;

		m_Textures.erase(it);
	}
}
