#include "DatabaseDownloader.h"
#include <iostream>

using namespace std;

DatabaseDownloader::DatabaseDownloader()
{
    _databaseData = new vector<SensorData>();
    InitDatabase();
}

void DatabaseDownloader::InitDatabase()
{
    // ------------
    _connection = mysql_init(0);
    _connection = mysql_real_connect(_connection, "localhost", "root", "Password", "temperaturesDatabase", 3306, NULL, 0);

}

DatabaseDownloader::~DatabaseDownloader()
{
    delete _databaseData;

    /* MySQL deletes its pointers on its own? Not sure why, but manually deleting these pointers
    // result in an error */

    //delete _connection;
    //delete _result;
}

int DatabaseDownloader::GetNumberOfPreviousTests()
{
    if (_connection)
    {
        string queryStatement = "SELECT * FROM temperatureTests";
        const char* query = queryStatement.c_str();

        // Sends a query to the database and establishes a link with it
        int query_state = mysql_query(_connection, query);
        if (!query_state)
        {
            int result = 0;
            _result = mysql_store_result(_connection);

            while (_row = mysql_fetch_row(_result))
            {   
                // row[1] refers to the test number, so the last _row[1] (which belongs to the last test on the table)
                // will have the latest (and largest) testNumber.
                result = stoi(_row[1]);
            }

            return result;
        }
        else
        {
            cout << "Query failed: " << mysql_error(_connection) << endl;
        }
    }
    else
    {
        cout << "Connection to database has failed!" << endl;
    }
}

vector<SensorData> DatabaseDownloader::RecieveAllData()
{
    _databaseData->clear();

    if (_connection)
    {
        cout << "Successful connection to database on READ!" << endl;

        string queryStatement = "SELECT * FROM temperatureTests";
        const char* query = queryStatement.c_str();

        // Sends a query to the database and establishes a link with it
        int query_state = mysql_query(_connection, query);
        if (!query_state)
        {
            _result = mysql_store_result(_connection);
            while (_row = mysql_fetch_row(_result))
            {
                string sensorName(_row[0]);
                int testNumber = stoi(_row[1]);
                int temperature = stoi(_row[2]);

                SensorData sensorData(sensorName, testNumber, temperature);
                _databaseData->push_back(sensorData);
            }

            return *_databaseData;
        }
        else
        {
            cout << "Query failed: " << mysql_error(_connection) << endl;
        }
    }
    else
    {
        cout << "Connection to database has failed!" << endl;
    }
}
