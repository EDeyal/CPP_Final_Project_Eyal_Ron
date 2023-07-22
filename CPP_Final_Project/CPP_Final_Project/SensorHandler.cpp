#include "SensorHandler.h"
#include "CalculationHelper.h"


using namespace std;

SensorHandler::SensorHandler(DatabaseDownloader* downloaderPTR)
{
	_testNumber = downloaderPTR->GetNumberOfPreviousTests();

	// The heat sensor generates fake data, so we need to define the range for that fake data
	int minTemperature = -20;
	int maxTemperature = 50;
	int maxTemperatureSway = 10;	// the amount of degrees the temperature can change between tests

	/* If no tests were done yet - the "starting" temperature is randomly somewhere between min and max temperature.
	   If a test was done before (previous sessions of running the program) - the last temperature recorded will be pulled
	   from the database. */

	int lastTemperatureMeasured = 0;
	if (_testNumber == 0)
	{
		lastTemperatureMeasured = CalculationHelper::GetRandomNumber(minTemperature, maxTemperature);
	}
	else
	{
		lastTemperatureMeasured = downloaderPTR->GetLastTemperatureMeasured();
	}

	_heatSensor = new HeatSensor(minTemperature, maxTemperature, maxTemperatureSway, lastTemperatureMeasured);

}

SensorHandler::~SensorHandler()
{
	delete _heatSensor;
}

SensorData SensorHandler::GetSensorData()
{
	float testResult = _heatSensor->GenerateFakeSensorData();
	_testNumber++;
	SensorData sensorData(_heatSensor->SensorName, _testNumber, testResult);
	return sensorData;
}
