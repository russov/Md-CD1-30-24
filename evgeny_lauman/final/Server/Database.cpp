#include "Database.h"
#include <iostream>
#include <string>
#include <sstream>

SQLiteDatabase::SQLiteDatabase(std::string name)
	: dbName(name) {}

SQLiteDatabase::~SQLiteDatabase()
{
	std::cout << "Closing " + dbName << std::endl;
	sqlite3_close(db);
	std::cout << "Closed " + dbName << std::endl << std::endl;
	delete[] db;
}

bool SQLiteDatabase::openDatabase()
{
	isOpened = sqlite3_open(dbName.c_str(), &db);
	if (isOpened)
	{
		std::cerr << "Error opening SQLite3 database " + dbName + " :" << sqlite3_errmsg(db) << std::endl << std::endl;
		sqlite3_close(db);
		return false;
	
	}
	else
	{
		char* error;
		std::cout << "Opened " + dbName << std::endl << std::endl;
		const char* sqlCreateTable = "CREATE TABLE IF NOT EXISTS CHAT  (id INTEGER PRIMARY KEY AUTOINCREMENT, username STRING, message STRING, timestamp DATETIME DEFAULT CURRENT_TIMESTAMP);"
									 "CREATE TABLE IF NOT EXISTS USERS (username STRING, password STRING);";
		int rc = sqlite3_exec(db, sqlCreateTable, NULL, NULL, &error);
		if (rc != SQLITE_OK)
		{
			std::cout << "error: " << error << std::endl;
			return false;
		}
	}
	return true;
}

bool SQLiteDatabase::addMsg(std::string user, std::string msg)
{
	char* error;
	std::string sqlInsertMsg = "INSERT INTO CHAT (username, message) values ('" + user + "', '" + msg + "');";
	int rc = sqlite3_exec(db, sqlInsertMsg.c_str(), NULL, NULL, &error);
	if (rc != SQLITE_OK)
	{
		std::cout << "error: " << error << std::endl;
		return false;
	}
	return true;
}


bool SQLiteDatabase::addUser(std::string user, std::string password)
{
	char* error;
	std::string sqlInsertMsg = "INSERT INTO USERS (username, password) values ('" + user + "', '" + password + "');";
	int rc = sqlite3_exec(db, sqlInsertMsg.c_str(), NULL, NULL, &error);
	if (rc != SQLITE_OK)
	{
		std::cout << "insert error: " << error << std::endl;
		return false;
	}
	return true;
}

std::string SQLiteDatabase::getLast10Msg()
{
	std::string result{ "" };
	char* error;
	sqlite3_stmt* stmt;
	const int count = 10;
	std::string query{ "select username, message from CHAT ORDER BY id DESC LIMIT " + std::to_string(count) };
	sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, 0);
	for (int i = 0; i < count; i++)
	{
		sqlite3_step(stmt);
		std::string username{ (const char*)sqlite3_column_text(stmt,0) };
		std::string message{ (const char*)sqlite3_column_text(stmt,0) };
		result = username + ": " + message + "\n" + result;
	}
	return result;
}
