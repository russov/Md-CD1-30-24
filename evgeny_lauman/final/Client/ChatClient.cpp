#include "ChatClient.h"
#include <iostream>
#include <string>
#include <thread>

using namespace std;


TCPClient::TCPClient()
{
	recvThreadRunning = false; 
}


TCPClient::~TCPClient()
{
	closesocket(serverSocket); 
	WSACleanup();
	if (recvThreadRunning) 
	{
		recvThreadRunning = false;
		recvThread.join();	//destroy thread
	}
}


bool TCPClient::initWinsock() 
{
	const int versionWinSock = 2;
	const int subversionWinSock = 2;
	WSADATA data;
	WORD ver = MAKEWORD(versionWinSock, subversionWinSock);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0) 
	{
		cout << "Error: can't start Winsock." << endl;
		return false;
	}
	return true;
}

SOCKET TCPClient::createSocket() 
{
	const int TCPIPprotocol = AF_INET;
	const int TCPconnection = SOCK_STREAM;
	const int windowsPlatform = 0;
	SOCKET sock = socket(TCPIPprotocol, TCPconnection, windowsPlatform);
	if (sock == INVALID_SOCKET) 
	{
		cout << "Error: can't create socket." << endl;
		WSACleanup();
		return -1;
	}
	hint.sin_family = TCPIPprotocol;
	hint.sin_port = htons(serverPort);	//htons - converts to TCP/IP view
	inet_pton(AF_INET, serverIP.c_str(), &hint.sin_addr); 	//converts IP string to bytes and pass it to hint
	return sock;
}

void TCPClient::threadRecv() 
{

	recvThreadRunning = true;
	while (recvThreadRunning) 
	{
		char buf[4096];
		ZeroMemory(buf, 4096);

		int bytesReceived = recv(serverSocket, buf, 4096, 0);	
		if (bytesReceived > 0) 
		{	
			std::cout << string(buf, 0, bytesReceived) << std::endl;
		}
	}
}

void TCPClient::connectSock() 
{
	serverSocket = createSocket();
	int connResult = connect(serverSocket, (sockaddr*)&hint, sizeof(hint));
	if (connResult == SOCKET_ERROR) 
	{
		cout << "Error: can't connect to server." << endl;
		closesocket(serverSocket);
		WSACleanup();
		return;
	}
}

void TCPClient::sendMsg(string txt) 
{
	if (!txt.empty() && serverSocket != INVALID_SOCKET) 
	{
		send(serverSocket, txt.c_str(), txt.size() + 1, 0);
	}
}
