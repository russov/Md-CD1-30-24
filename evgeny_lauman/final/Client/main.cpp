#include <iostream>
#include <string>
#include <WS2tcpip.h>
#include "ChatClient.h"
#pragma comment (lib, "ws2_32.lib")
#undef max

using json = nlohmann::json;

enum messageType
{
	SIGNUP,
	LOGIN,
	DATASEND
};

int main() 
{
	TCPClient *client = new TCPClient; 
	std::string msg{ "" };
	bool isAuthorized = false;
	if (client->initWinsock()) 
	{
		if (client->connectSock())
		{
			client->recvThread = std::thread([&]
				{
					client->threadRecv(isAuthorized);
				});
			while (true)
			{
				std::string messageToSend{};
				if (!isAuthorized)
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
						std::string password{ "" };
						std::cout << "Enter your username." << std::endl;
						std::cin >> client->username;
						std::cout << "Enter your password." << std::endl;
						std::cin >> password;
						auto j = json{ {"username", client->username}, {"password", password}, {"data", ""}, {"type", messageType::LOGIN} };
						messageToSend = to_string(j);
						client->sendMsg(messageToSend);
						std::this_thread::sleep_for(std::chrono::milliseconds(150));
						break;
					}
					case '2':
					{
						std::string username{ "" };
						std::string password{ "" };
						std::cout << "Enter your username." << std::endl;
						std::cin >> client->username;
						std::cout << "Enter your password." << std::endl;
						std::cin >> password;
						auto j = json{ {"username", client->username}, {"password", password}, {"data", ""}, {"type", messageType::SIGNUP} };
						messageToSend = to_string(j);
						client->sendMsg(messageToSend);
						std::this_thread::sleep_for(std::chrono::milliseconds(150));
						break;
					}
					case 'x':
					{
						return 0;
					}
					default:
						break;
					}
				}
				else
				{
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //flush cin buffer
					std::getline(std::cin, msg);
					auto j = json{ {"username", client->username}, {"data", msg}, {"type", messageType::DATASEND} };
					messageToSend = to_string(j);
					client->sendMsg(messageToSend);
				}
			}
		}
	}
	delete client; 
	std::cin.get();
	return 0;
}