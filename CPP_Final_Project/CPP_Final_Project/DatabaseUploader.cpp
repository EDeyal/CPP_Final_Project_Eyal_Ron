#include "DatabaseUploader.h"
#include <iostream>
#include <sstream>

using namespace std;

DatabaseUploader::DatabaseUploader()
{
	_connection = mysql_init(0);
	_connection = mysql_real_connect(_connection, "localhost", "root", "Password", "temperaturesDatabase1", 3306, NULL, 0);

	// If database doesn't exist - create one
	if (_connection)
	{
		cout << "database found" << endl;
	}
	else
	{
		// Database not found - creating a new database

		cout << "database not found - creating new database" << endl;

		stringstream statement;
		statement << "CREATE DATABASE [IF NOT EXISTS] temperaturesDatabase1";

		string statementString = statement.str();


		const char* query = statementString.c_str();
		//int query_state = mysql_query(NULL, query);

		//ExecuteQuery(statementString);
		//_connection = mysql_init(0);
		//_connection = mysql_real_connect(_connection, "localhost", "root", "Password", "temperaturesDatabase1", 3306, NULL, 0);
	}

	// If table doesn't exist - create one

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


		ExecuteQuery(insertString);
	}
	else
	{
		cout << "Connection to database has failed!" << endl;
	}
	

	//mysql_close(_connection);
}

void DatabaseUploader::ExecuteQuery(string statement)
{
	const char* query = statement.c_str();
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
