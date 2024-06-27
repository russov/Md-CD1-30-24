#pragma once
#pragma comment (lib, "ws2_32.lib")
#include <string>
#include <WS2tcpip.h>
#include "Database.h"

class TCPServer 
{
private:
	SOCKET createSocket();
	std::string listenerIPAddress;
	int listenerPort;
public:
	TCPServer(std::string ipAddress, int port);
	~TCPServer(); 

	bool initWinsock(); 
	void run();
	void cleanupWinsock(); 
};