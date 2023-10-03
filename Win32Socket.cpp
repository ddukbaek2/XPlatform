#include "Win32Socket.h"

#include <winsock2.h>
#include <ws2tcpip.h>
#pragma comment(lib, "ws2_32.lib")


namespace XPlatform
{
	void WWWThread(const String& uniformResourceLocator, StringCallback callback)
	{
        //addrinfo* result = nullptr;
        //addrinfo hints = {};
        //hints.ai_family = AF_UNSPEC;
        //hints.ai_socktype = SOCK_STREAM;
        //hints.ai_protocol = IPPROTO_TCP;

        //getaddrinfo(uniformResourceLocator.GetConstString().c_str(), "80", &hints, &result);

        //SOCKET ConnectSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        //connect(ConnectSocket, result->ai_addr, (int)result->ai_addrlen);
        //freeaddrinfo(result);

        //std::string request = "GET " + std::string(path) + " HTTP/1.1\r\nHost: " + host + "\r\nConnection: close\r\n\r\n";
        //send(ConnectSocket, request.c_str(), (int)request.length(), 0);

        //char buffer[2048];
        //int bytesRead = 0;
        //std::string response;
        //do {
        //    bytesRead = recv(ConnectSocket, buffer, sizeof(buffer), 0);
        //    if (bytesRead > 0) {
        //        response.append(buffer, bytesRead);
        //    }
        //} while (bytesRead > 0);

        //callback(response);
        //closesocket(ConnectSocket);
	}

	Win32Socket::Win32Socket()
	{
		WSADATA wsaData;
		if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
			return;
	}

	Win32Socket::~Win32Socket()
	{
		WSACleanup();
	}

	void Win32Socket::WWWThread(const String& uniformResourceLocator, StringCallback callback)
	{
		auto thread = std::thread(XPlatform::WWWThread, uniformResourceLocator, callback);
        thread.join();
	}
}
