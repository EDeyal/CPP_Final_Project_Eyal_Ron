#pragma once
#include "Sensor.h"

class HeatSensor : public Sensor
{
	float _lastTemprature;
	float _currentTemprature;
	int _minTemprature;
	int _maxTemprature;
	int _tempratureMaxDelta;
	int _tempratureSway;//the maximum amount of change in temp per test



public:
	HeatSensor(int minTemprature, int maxTemprature,int _tempratureSway);
	float GetSensorData();

private:
	float GenerateSensorData();

};

