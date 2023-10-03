#pragma once

#include "XPlatform.h"
#include "String.h"


namespace XPlatform
{
	class WebRequest
	{
	public:
		static void Get(const String& url);
	};
}
