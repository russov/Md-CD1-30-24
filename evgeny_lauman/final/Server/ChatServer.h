#pragma once

#include <string>
#include <WS2tcpip.h>
#pragma comment (lib, "ws2_32.lib")

class TCPServer 
{
private:
	SOCKET createSocket();
	std::string listenerIPAddress;
	int listenerPort;
public:
	TCPServer(std::string ipAddress, int port);
	~TCPServer(); 

	void sendMsg(int clientSocket, std::string msg);
	bool initWinsock(); 
	void run();
	void cleanupWinsock(); 
};