#pragma once

#include "ISocket.h"
#include "String.h"


namespace XPlatform
{
	/////////////////////////////////////////////////////////////////////////////
	// @ 윈도우 소켓.
	/////////////////////////////////////////////////////////////////////////////
	class Win32Socket : public ISocket
	{
	public:
		Win32Socket();
		virtual ~Win32Socket();

		void WWWThread(const String& uniformResourceLocator, StringCallback callback);
	};
}
