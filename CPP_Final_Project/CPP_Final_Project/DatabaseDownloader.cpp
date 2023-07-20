#include "DatabaseDownloader.h"

DatabaseDownloader::DatabaseDownloader()
{
    _databaseData = new vector<SensorData>();
    InitDatabase();
}

void DatabaseDownloader::InitDatabase()
{
    SensorData temporaryData("HeatSensor", 1, 18);
    SensorData temporaryData1("HeatSensor", 2, 20);
    SensorData temporaryData2("HeatSensor", 3, -10);
    SensorData temporaryData3("HeatSensor", 3, -19);
    _databaseData->push_back(temporaryData);
    _databaseData->push_back(temporaryData1);
    _databaseData->push_back(temporaryData2);
    _databaseData->push_back(temporaryData3);

    // ------------
    _connection = mysql_init(0);
    _connection = mysql_real_connect(_connection, "localhost", "root", "password", "testDB", 3306, NULL, 0);

}

DatabaseDownloader::~DatabaseDownloader()
{
    delete _databaseData;
    delete _connection;
}

vector<SensorData> DatabaseDownloader::RecieveAllData()
{   
    return *_databaseData;
}
