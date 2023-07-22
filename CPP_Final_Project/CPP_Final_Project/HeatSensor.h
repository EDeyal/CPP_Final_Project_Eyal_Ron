#pragma once
#include "Sensor.h"

class HeatSensor : public Sensor
{
	int _lastTemprature;
	int _currentTemprature;
	int _minTemprature;
	int _maxTemprature;
	int _tempratureSway; //the maximum amount of change in temp per test



public:
	HeatSensor(int minTemprature, int maxTemprature,int tempratureSway, int lastTemperatureMeasured);
	float GenerateFakeSensorData();

};

