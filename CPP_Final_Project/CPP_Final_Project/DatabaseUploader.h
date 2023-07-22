#pragma once
#include "SensorData.h"
#include <mysql.h>
class DatabaseUploader
{
private:
	// MySQL fields
	MYSQL* _connection;
	string _databaseName;
	string _tableName;

public:
	DatabaseUploader(string databaseName, string tableName);
	void UploadSensorData(SensorData data);

private:
	void ExecuteQuery(string statement);

};

