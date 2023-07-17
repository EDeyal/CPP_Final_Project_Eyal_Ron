#pragma once
#include <string>

using namespace std;

class SensorData
{
public:
	string _sensorName;
	int _testNumber;
	float _temperature;

	SensorData(string sensorName, int testNumber, float temperature);

	std::string ToString() const;
};

