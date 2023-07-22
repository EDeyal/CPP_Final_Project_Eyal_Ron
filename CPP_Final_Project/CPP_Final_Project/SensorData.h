#pragma once
#include <string>

using namespace std;

class SensorData
{
public:
	string SensorName;
	int TestNumber;
	int Temperature;

	SensorData(string sensorName, int testNumber, int temperature);

	std::string ToString() const;
};

