#pragma once

#include "Object.h"
#include "IDrawable.h"

namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 렌더러.
	/////////////////////////////////////////////////////////////////////////////
	class Renderer : public Object
	{
	private:
		typedef Object Base;

	protected:
		std::vector<IDrawable> m_Drawables;

	public:
		void OnRender()
		{
		}
	};
}
