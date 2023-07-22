#pragma once
#include "SensorData.h"
#include <mysql.h>
class DatabaseUploader
{
	// MySQL fields
	MYSQL* _connection;
	string _databaseName;
	string _tableName;
	void ExecuteQuery(string statement);
public:
	DatabaseUploader(string databaseName, string tableName);
	~DatabaseUploader();
	void UploadSensorData(SensorData data);

};

