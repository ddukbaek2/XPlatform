#pragma once
#include "Texture.h"

#include "XPlatform.h"
#include "Object.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ ÆùÆ®.
	/////////////////////////////////////////////////////////////////////////////
	class Font : public Object
	{
	private:
		typedef Object Base;

	private:
		Ref<Texture> m_Texture;

	protected:
		virtual void OnCreate() override;
		virtual void OnDestroy() override;

	public:
	};
}