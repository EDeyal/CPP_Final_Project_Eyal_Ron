#include "Dashboard.h"

Dashboard::Dashboard(int extremeSway)
{
	_extremeSway = extremeSway;
	_databaseDownloader = new DatabaseDownloader();
}

Dashboard::~Dashboard()
{
	delete _databaseDownloader;
}

void Dashboard::DisplayAverageTemperature()
{
	vector<SensorData> data = _databaseDownloader->RecieveAllData();

	float totalTemperature = 0;
	for (size_t i = 0; i < data.size(); i++)
	{
		totalTemperature += data[i]._temperature;
	}

	float averageTemperature = totalTemperature / data.size();
	cout << "Average Temperature is: " << averageTemperature << endl;
}

void Dashboard::DisplayNumberOfExtremeTemperatureChanges()
{
	int numberOfExtremeChanges = 0;

	vector<SensorData> data = _databaseDownloader->RecieveAllData();

	for (size_t i = 0; i < data.size(); i++)
	{
		if (i == 0)
		{
			continue;
		}

		if (abs(data[i]._temperature - data[i - 1]._temperature) >= _extremeSway)
		{
			numberOfExtremeChanges++;
		}

	}

	cout << "The number of extreme temperature changes is: " << numberOfExtremeChanges << endl;
}

void Dashboard::DisplayAllData()
{
	//system("cls");
	vector<SensorData> data = _databaseDownloader->RecieveAllData();

	for (size_t i = 0; i < data.size(); i++)
	{
		cout << data[i].ToString() << endl;
	}

	DisplayAverageTemperature();
}
