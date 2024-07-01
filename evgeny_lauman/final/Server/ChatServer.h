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
	const std::string key = "THE@LAst#project!";
public:
	TCPServer(std::string ipAddress, int port);
	~TCPServer(); 

	bool initWinsock(); 
	void run();
	void cleanupWinsock(); 
	void sendMsg(SOCKET outSock, std::string txt, std::string access = "Unauthorized");
	std::string encryptData(std::string input);
};