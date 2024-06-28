#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include "ChatClient.h"
#include "json/json.hpp"
#pragma comment (lib, "ws2_32.lib")
#undef max

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
	if (client->initWinsock()) 
	{
		if (client->connectSock())
		{
			client->recvThread = thread([&]
				{
					client->threadRecv();
				});
			while (true)
			{
				std::string messageToSend{};
				if (client->joinChat == true)
				{
					char choice = 0;
					std::cout << "MENU:\n"
						<< "1. LOGIN\n"
						<< "2. SIGNUP\n"
						<< "x. EXIT"
						<< std::endl;
					std::cin >> choice;
					std::cout << "SELECTED: " << choice << "\n";
					switch (choice)
					{
					case '1':
					{
						string password{ "" };
						cout << "Enter your username." << endl;
						cin >> client->username;
						cout << "Enter your password." << endl;
						cin >> password;
						auto j = json{ {"username", client->username}, {"password", password}, {"data", ""}, {"type", messageType::LOGIN} };
						messageToSend = to_string(j);
						client->joinChat = false;
						break;
					}
					case '2':
					{
						string username{ "" };
						string password{ "" };
						cout << "Enter your username." << endl;
						cin >> client->username;
						cout << "Enter your password." << endl;
						cin >> password;
						auto j = json{ {"username", client->username}, {"password", password}, {"data", ""}, {"type", messageType::SIGNUP} };
						messageToSend = to_string(j);
						break;
					}
					case 'x':
					{
						return 0;
					}
					default:
						break;
					}
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //flush cin buffer
				}
				else
				{
					getline(cin, msg);
					auto j = json{ {"username", client->username}, {"data", msg}, {"type", messageType::DATASEND} };
					messageToSend = to_string(j);
				}
				client->sendMsg(messageToSend);
			}
		}
	}
	delete client; 
	cin.get(); 
	return 0;
}