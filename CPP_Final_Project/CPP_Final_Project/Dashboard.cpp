#include "Dashboard.h"

Dashboard::Dashboard(int extremeSway, DatabaseDownloader* downloaderPTR)
{
	_extremeSway = extremeSway;
	_databaseDownloader = downloaderPTR;
	//_databaseDownloader = new DatabaseDownloader("test17", "table1");
}

void Dashboard::DisplayAverageTemperature()
{
	vector<SensorData> data = _databaseDownloader->RecieveAllData();

	float totalTemperature = 0;
	int numberOfTestsPreformed = data.size();
	for (size_t i = 0; i < numberOfTestsPreformed; i++)
	{
		totalTemperature += data[i].Temperature;
	}

	float averageTemperature = totalTemperature / numberOfTestsPreformed;
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

		// if the temperature change is equal or greater than extremeSway parameter, it is recorded.
		if (abs(data[i].Temperature - data[i - 1].Temperature) >= _extremeSway)
		{
			numberOfExtremeChanges++;
		}

	}

	cout << "The Extreme temperature change is defined as a change that's equal to/greater than " << _extremeSway << " degrees" << endl;
	cout << "The number of extreme temperature changes is: " << numberOfExtremeChanges << endl;
}

void Dashboard::DisplayAllData()
{

	vector<SensorData> data = _databaseDownloader->RecieveAllData();

	for (size_t i = 0; i < data.size(); i++)
	{
		cout << data[i].ToString() << endl;
	}

	DisplayAverageTemperature();
	DisplayNumberOfExtremeTemperatureChanges();
}
