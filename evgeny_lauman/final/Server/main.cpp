#include <iostream>
#include <string>
#include "ChatServer.h"

using namespace std; 

const string serverIP = "127.0.0.1";

int main() 
{
	TCPServer server(serverIP, 54010);
	if (server.initWinsock()) 
	{
		server.run();
	}
}
