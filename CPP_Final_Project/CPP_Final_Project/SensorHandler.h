#pragma once
#include "HeatSensor.h"
#include "SensorData.h"
class SensorHandler
{
	HeatSensor _heatSensor;

public:
	SensorData GetSensorData();
};

