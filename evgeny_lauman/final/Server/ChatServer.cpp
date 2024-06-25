#include "ChatServer.h"
#include <iostream>
#include <string>
#include <sstream>

TCPServer::TCPServer(std::string ipAddress, int port)
	: listenerIPAddress(ipAddress), listenerPort(port) {}

TCPServer::~TCPServer() 
{
	cleanupWinsock();
}

bool TCPServer::initWinsock() 
{
	const int versionWinSock = 2;
	const int subversionWinSock = 2;
	WSADATA data;
	WORD ver = MAKEWORD(versionWinSock, subversionWinSock);
	int wsInit = WSAStartup(ver, &data);
	if (wsInit != 0) 
	{
		std::cout << "Error: can't initialize Winsock." << std::endl; 
		return false;
	}
	return true;
}

SOCKET TCPServer::createSocket() 
{
	const int TCPIPprotocol = AF_INET;
	const int TCPconnection = SOCK_STREAM;
	const int windowsPlatform = 0;
	SOCKET listeningSocket = socket(TCPIPprotocol, TCPconnection, windowsPlatform);
	if (listeningSocket != INVALID_SOCKET) 
	{
		sockaddr_in hint;

		hint.sin_family = TCPIPprotocol;
		hint.sin_port = htons(listenerPort);	//htons - converts to TCP/IP view
		inet_pton(AF_INET, listenerIPAddress.c_str(), &hint.sin_addr); 	//converts IP string to bytes and pass it to hint

		int bindCheck = bind(listeningSocket, (sockaddr*)&hint, sizeof(hint));

		if (bindCheck != SOCKET_ERROR) 
		{
			int listenCheck = listen(listeningSocket, SOMAXCONN);
			if (listenCheck == SOCKET_ERROR) 
			{
				std::cout << WSAGetLastError();
				return -1;
			}
		}
		else 
		{
			std::cout << WSAGetLastError();
			return -1;
		}
		return listeningSocket;
	}
	else
	{
		std::cout << WSAGetLastError();
		return -1;
	}
}

void TCPServer::run() 
{
	const int MAX_BUFFER_SIZE = 4096;
	char buf[MAX_BUFFER_SIZE];
	SOCKET listeningSocket = createSocket();
	while (true) 
	{
		if (listeningSocket == INVALID_SOCKET) 
		{
			std::cout << WSAGetLastError();
			break;
		}

		fd_set master;				//file descriptor storing all the sockets
		FD_ZERO(&master);
		FD_SET(listeningSocket, &master);

		while (true) {

			fd_set copy = master;
			int socketCount = select(0, &copy, nullptr, nullptr, nullptr);				//get active sockets

			for (int i = 0; i < socketCount; i++) 
			{
				SOCKET sock = copy.fd_array[i];

				if (sock == listeningSocket) 
				{	//Case 1: accept new connection.
					SOCKET client = accept(listeningSocket, nullptr, nullptr);
					FD_SET(client, &master);		//add new socket
					const std::string welcome = "Welcome to Chat.\n";
					send(client, welcome.c_str(), welcome.size() + 1, 0);
					std::cout << "New user joined the chat." << std::endl;
				}
				else 
				{	//Case 2: receive a msg.	
					ZeroMemory(buf, MAX_BUFFER_SIZE);
					int bytesReceived = recv(sock, buf, MAX_BUFFER_SIZE, 0);
					if (bytesReceived <= 0) 
					{	//no msg = drop client. 
						closesocket(sock);
						FD_CLR(sock, &master);	//remove socket
					}
					else 
					{
						for (int i = 0; i < master.fd_count; i++) 
						{	
							SOCKET outSock = master.fd_array[i];	
							if (outSock != listeningSocket) 
							{
								if (outSock == sock) 
								{	
									std::string msgSent = "Message delivered.";
									send(outSock, msgSent.c_str(), msgSent.size() + 1, 0);
								}
								else 
								{	
									send(outSock, buf, bytesReceived, 0);
								}
							}
						}
						std::cout << std::string(buf, 0, bytesReceived) << std::endl;
					}
				}
			}
		}
	}
}

void TCPServer::sendMsg(int clientSocket, std::string msg) {
	send(clientSocket, msg.c_str(), msg.size() + 1, 0);
}

void TCPServer::cleanupWinsock() {
	WSACleanup();
}

