#include "XGL.h"
#include "Texture.h"
#include "External/loadpng/lodepng.h"


namespace XPlatform
{
	Texture::Texture()
	{
		m_Pixels.clear();
		m_Width = 0;
		m_Height = 0;
	}

	Texture::~Texture()
	{
	}

	void Texture::Load(std::wstring& filename)
	{
		lodepng::load_file(m_Pixels, filename.c_str());

		lodepng_load_file(m_Pixels, )
	}

	void Texture::Unload()
	{
	}
}