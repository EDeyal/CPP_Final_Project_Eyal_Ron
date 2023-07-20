#pragma once
#include "SensorData.h"
#include "vector"
class DatabaseDownloader
{
private:
	vector<SensorData>* _databaseData;

public:
	DatabaseDownloader();
	~DatabaseDownloader();
	vector<SensorData> RecieveAllData();
};

