#pragma once
#include <string>
#include <thread>
#include <WS2tcpip.h>
#include "json/json.hpp"
using json = nlohmann::json;
#pragma comment (lib, "ws2_32.lib")

class TCPClient
{
private:
	SOCKET createSocket();
	const std::string serverIP = "127.0.0.1";
	const int serverPort = 54010;
	const std::string key = "THE@LAst#project!";
	sockaddr_in hint;
	SOCKET serverSocket;
	bool recvThreadRunning;
public:
	TCPClient();
	~TCPClient();
	bool initWinsock(); 
	bool connectSock();
	void sendMsg(std::string txt);
	std::thread recvThread;
	void threadRecv(bool& isAuthorized);
	std::string encryptData(std::string input);
	std::string username;
	bool joinChat = true;
};
