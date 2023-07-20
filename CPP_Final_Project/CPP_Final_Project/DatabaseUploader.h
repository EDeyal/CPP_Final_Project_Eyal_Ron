#pragma once
#include "SensorData.h"
#include <mysql.h>

class DatabaseUploader
{
	// MySQL fields
	MYSQL* _connection;

public:
	DatabaseUploader();
	~DatabaseUploader();
	void UploadSensorData(SensorData data);

};

