#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include "ChatClient.h"
#include "json/json.hpp"
#pragma comment (lib, "ws2_32.lib")

using json = nlohmann::json;
using namespace std;

enum messageType
{
	SIGNUP,
	LOGIN,
	DATASEND
};

int main() 
{
	TCPClient *client = new TCPClient; 
	string msg{ "" };
	string username{ "" };

	cout << "Enter your username." << endl;
	cin >> username;
	client->username = username; 

	if (client->initWinsock()) 
	{
		client->connectSock();
		client->recvThread = thread([&] 
		{
			client->threadRecv(); 
		});
		while (true) 
		{
			getline(cin, msg); 
			std::string messageToSend; 
			if (client->joinChat == false) 
			{
				auto j = json{ {"username", client->username}, {"data", msg}, {"type", messageType::DATASEND} };
				messageToSend = to_string(j);
			}
			else if (client->joinChat == true) 
			{
				auto j = json{ {"username", client->username}, {"data", ""}, {"type", messageType::LOGIN} };
				messageToSend = to_string(j);
				client->joinChat = false; 
			}
			client->sendMsg(messageToSend);
		}
	}
	delete client; 
	cin.get(); 
	return 0;
}