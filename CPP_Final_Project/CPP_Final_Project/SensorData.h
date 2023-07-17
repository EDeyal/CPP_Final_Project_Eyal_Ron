#pragma once
#include <string>

using namespace std;

class SensorData
{
public:
	string _sensorName;
	int _testNumber;
	int _temperature;

	SensorData(string sensorName, int testNumber, int temperature);

	std::string ToString() const;
};

