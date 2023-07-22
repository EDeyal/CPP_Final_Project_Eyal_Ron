#pragma once
#include "HeatSensor.h"
#include "SensorData.h"
#include "DatabaseDownloader.h"
class SensorHandler
{
	int _testNumber;
	HeatSensor* _heatSensor;

public:
	SensorHandler(DatabaseDownloader* downloaderPTR);
	~SensorHandler();
	SensorData GetSensorData();
};

