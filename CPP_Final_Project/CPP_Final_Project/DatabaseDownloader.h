#pragma once
#include "SensorData.h"
#include "vector"
#include <mysql.h>

class DatabaseDownloader
{
private:
	vector<SensorData>* _databaseData;
	void InitDatabase();

	string _databaseName;
	string _tableName;
	// MySQL fields
	MYSQL* _connection;
	MYSQL_ROW _row;
	MYSQL_RES* _result;

public:
	DatabaseDownloader(string databaseName, string tableName);
	~DatabaseDownloader();
	int GetNumberOfPreviousTests();
	vector<SensorData> RecieveAllData();
};

