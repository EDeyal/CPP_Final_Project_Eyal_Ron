#pragma once
#include "SensorData.h"
#include "vector"
#include <mysql.h>

class DatabaseDownloader
{
private:
	vector<SensorData>* _databaseData;
	void InitDatabase();

	// MySQL fields
	MYSQL* _connection;
	MYSQL_ROW _row;
	MYSQL_RES* _result;

public:
	DatabaseDownloader();
	~DatabaseDownloader();
	int GetNumberOfPreviousTests();
	vector<SensorData> RecieveAllData();
};

