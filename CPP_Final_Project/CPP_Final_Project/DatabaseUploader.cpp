#include "DatabaseUploader.h"
#include <iostream>
#include <sstream>

using namespace std;

DatabaseUploader::DatabaseUploader()
{
	_connection = mysql_init(0);
	_connection = mysql_real_connect(_connection, "localhost", "root", "Password", "temperaturesDatabase", 3306, NULL, 0);
}

DatabaseUploader::~DatabaseUploader()
{

}

void DatabaseUploader::UploadSensorData(SensorData data)
{
	if (_connection)
	{
		cout << "Successful connection to database on WRITE!" << endl;

		stringstream insertStatement;
		insertStatement << "INSERT INTO temperatureTests(sensorName, TestNumber, Temperature) Values('" + data.SensorName + "', '" + to_string(data.TestNumber) + "', '" + to_string(data.Temperature) + "')";

		string insertString = insertStatement.str();
		const char* query = insertString.c_str();
		int query_state = mysql_query(_connection, query);

		if (query_state == 0)
		{
			cout << "Data Inserted..." << endl;
		}
		else
		{
			cout << "Failed to insert data..." << endl;
		}
	}
	else
	{
		cout << "Connection to database has failed!" << endl;
	}
	

	//mysql_close(_connection);
}
