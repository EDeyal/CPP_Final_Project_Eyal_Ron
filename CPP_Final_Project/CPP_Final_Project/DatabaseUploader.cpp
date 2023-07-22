#include "DatabaseUploader.h"
#include <iostream>
#include <sstream>

using namespace std;

DatabaseUploader::DatabaseUploader(string databaseName,string tableName)
{
	_databaseName = databaseName;
	_tableName = tableName;
	_connection = mysql_init(0);
	_connection = mysql_real_connect(_connection, "localhost", "root", "Password", _databaseName.c_str(), 3306, NULL, 0);

	// If database doesn't exist - create one
	if (_connection)
	{
		cout << "database found" << endl;
	}
	else
	{
		// Database not found - creating a new database

		cout << "database not found - creating new database" << endl;
		
		// 1. Create the database
		stringstream createDatabaseStatement;
		createDatabaseStatement << "CREATE DATABASE IF NOT EXISTS " << _databaseName;
		string statementString = createDatabaseStatement.str();

		_connection = mysql_init(0);
		_connection = mysql_real_connect(_connection, "localhost", "root", "Password", NULL, 3306, NULL, 0);
		ExecuteQuery(statementString);

		// 2. Use the database (connect the newly created database to _connection)
		stringstream useDatabaseStatement;
		useDatabaseStatement << "USE " << _databaseName;

		string statementString1 = useDatabaseStatement.str();
		ExecuteQuery(statementString1);


		// 3. Create new table
		stringstream createTableStatement;
		createTableStatement << "CREATE TABLE " << _tableName << " (SensorName varchar(32),TestNumber int,Temperature int)";
		string statementString2 = createTableStatement.str();
		ExecuteQuery(statementString2);
	}

}

void DatabaseUploader::UploadSensorData(SensorData data)
{
	if (_connection)
	{
		//cout << "Successful connection to database on WRITE!" << endl;

		// Parse and Insert SensorData to database
		stringstream insertStatement;
		insertStatement << "INSERT INTO " <<_tableName<< "(SensorName, TestNumber, Temperature) Values('" + data.SensorName + "', '" + to_string(data.TestNumber) + "', '" + to_string(data.Temperature) + "')";
		string insertString = insertStatement.str();

		ExecuteQuery(insertString);
	}
	else
	{
		cout << "Connection to database has failed!" << endl;
	}
}

void DatabaseUploader::ExecuteQuery(string statement)
{
	// ExecuteQuery excutes commands that have been already converted to string format (using commands according to MySQL commandline)

	// 1. Converting string to char
	const char* query = statement.c_str();

	// 2. Sending MySQL command through _connection
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
