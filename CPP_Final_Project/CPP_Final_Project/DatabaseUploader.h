#pragma once
#include "SensorData.h"
#include <mysql.h>

class DatabaseUploader
{
	// MySQL fields
	MYSQL* _connection;
	void ExecuteQuery(string statement);

public:
	DatabaseUploader();
	~DatabaseUploader();
	void UploadSensorData(SensorData data);

};

