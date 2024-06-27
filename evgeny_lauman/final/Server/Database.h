#pragma once
#include <string>
#include <WS2tcpip.h>
#include "sqlite/sqlite3.h"

class SQLiteDatabase
{
private:
	sqlite3* db;
	std::string dbName;
	bool isOpened = false;
public:
	SQLiteDatabase(std::string name);
	~SQLiteDatabase();

	bool openDatabase();
	bool addMsg(std::string user, std::string msg);
	bool addUser(std::string user, std::string password);
	std::string getLast10Msg();
};