#pragma once
#include "SensorData.h"
#include "vector"
#include <mysql.h>

class DatabaseDownloader
{
private:
	vector<SensorData>* _databaseData;
	void InitDatabase();
	MYSQL* conn;

public:
	DatabaseDownloader();
	~DatabaseDownloader();
	vector<SensorData> RecieveAllData();
};

