#include "WebRequest.h"


#ifdef _WIN32
#include <WinSock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")
#endif

namespace XPlatform
{
    void winsock_get()
    {
    }

    void WebRequest::Get(const String& url)
    {
    }
}
