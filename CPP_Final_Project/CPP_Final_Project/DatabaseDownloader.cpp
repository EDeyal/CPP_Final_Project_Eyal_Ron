#include "DatabaseDownloader.h"

DatabaseDownloader::DatabaseDownloader()
{
    _databaseData = new vector<SensorData>();
}

DatabaseDownloader::~DatabaseDownloader()
{
    delete _databaseData;
}

vector<SensorData> DatabaseDownloader::RecieveAllData()
{
    SensorData temporaryData("HeatSensor", 1, 18);
    SensorData temporaryData1("HeatSensor", 2, 20);
    SensorData temporaryData2("HeatSensor", 3, -10);
    SensorData temporaryData3("HeatSensor", 3, -19);
    _databaseData->push_back(temporaryData);
    _databaseData->push_back(temporaryData1);
    _databaseData->push_back(temporaryData2);
    _databaseData->push_back(temporaryData3);
    return *_databaseData;
}
