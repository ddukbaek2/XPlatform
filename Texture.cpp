#include "IGL.h"
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
		Unload();
	}

	void Texture::Load(const String& filename)
	{
		lodepng::load_file(m_Pixels, filename);

		//lodepng_load_file(m_Pixels, )
	}

	void Texture::Unload()
	{
		m_Width = m_Height = 0;
		m_Pixels.clear();
		//GL::DELETETEXTURE(ID);
	}

	bool Texture::IsLoaded()
	{
		return m_Width > 0 && m_Height > 0;
	}
}
