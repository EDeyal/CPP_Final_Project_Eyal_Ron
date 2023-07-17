#include "SensorHandler.h"

using namespace std;

SensorHandler::SensorHandler()
{
	int minTemperature = -20;
	int maxTemperature = 50;
	int maxTemperatureSway = 10;	// the amount of degrees the temperature can change between tests
	HeatSensor tempSensor(minTemperature, maxTemperature, maxTemperatureSway);
	_heatSensor = &tempSensor;

	_testNumber = 0;
}

SensorData SensorHandler::GenerateFakeSensorData()
{
	float testResult = _heatSensor->GetSensorData();
	_testNumber++;
	SensorData sensorData(_heatSensor->SensorName, _testNumber, testResult);
	return sensorData;
}
