#include "SensorData.h"


SensorData::SensorData(string sensorName, int testNumber, int temperature)
{
	_sensorName = sensorName;
	_testNumber = testNumber;
	_temperature = temperature;
}

string SensorData::ToString() const
{
	//string bla = "Sensor Name: " + _sensorName + ", Test Number: " + to_string(_testNumber) + ", Temperature: " + to_string(_temperature);
	return "Sensor Name: " + _sensorName + ", Test Number: " + to_string(_testNumber) + ", Temperature: " + to_string(_temperature);
}
