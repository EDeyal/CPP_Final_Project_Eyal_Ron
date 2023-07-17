#pragma once
#include "HeatSensor.h"
#include "SensorData.h"
class SensorHandler
{
	int _testNumber;
	HeatSensor* _heatSensor;

public:
	SensorHandler();
	~SensorHandler();
	SensorData GenerateFakeSensorData();
};

