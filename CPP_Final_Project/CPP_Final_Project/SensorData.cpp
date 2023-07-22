#include "SensorData.h"


SensorData::SensorData(string sensorName, int testNumber, int temperature)
{
	SensorName = sensorName;
	TestNumber = testNumber;
	Temperature = temperature;
}

string SensorData::ToString() const
{
	return "Sensor Name: " + SensorName + ", Test Number: " + to_string(TestNumber) + ", Temperature: " + to_string(Temperature);
}
