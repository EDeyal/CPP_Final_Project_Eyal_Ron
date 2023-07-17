#pragma once
#include "HeatSensor.h"
#include "SensorData.h"
class SensorHandler
{
	int _testNumber;

public:
	HeatSensor* _heatSensor;
	SensorHandler();
	SensorData GenerateFakeSensorData();
};

