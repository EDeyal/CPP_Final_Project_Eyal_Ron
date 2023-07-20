#pragma once
#include "SensorData.h"
#include "vector"
#include <mysqul.h>

class DatabaseDownloader
{
private:
	vector<SensorData>* _databaseData;
	void InitDatabase();

public:
	DatabaseDownloader();
	~DatabaseDownloader();
	vector<SensorData> RecieveAllData();
};

