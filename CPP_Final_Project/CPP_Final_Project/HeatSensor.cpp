#include "time.h"
#include "HeatSensor.h"
#include <stdlib.h>
#include "CalculationHelper.h"

HeatSensor::HeatSensor(int minTemprature, int maxTemprature, int tempratureSway)
{
	_minTemprature = minTemprature;
	_maxTemprature = maxTemprature;
	_tempratureSway = tempratureSway;
	if (_minTemprature >= _maxTemprature)
	{
		throw "HeatSensor recived minimum temprature that is bigger or equal than maximum remprature";
	}//Enter better numbers siirrrrr
	srand(time(NULL));
	_tempratureMaxDelta = abs(_minTemprature - _maxTemprature);
	_lastTemprature = CalculationHelper::GetRandomNumber(_minTemprature, _maxTemprature) ;//use calc helper
}

float HeatSensor::GetSensorData()
{
	//if we had a sensor we would connect it here and send it's data back
	return GenerateSensorData();
}

float HeatSensor::GenerateSensorData()
{

	//algorithem for sensor
	// addition or reduction from last temprature
	_currentTemprature = _lastTemprature + CalculationHelper::GetRandomNumber(-_tempratureSway, _tempratureSway); //use calculation helper for random
	// need to check if in range
	// if no in range than will be at max or minimum
	if (_currentTemprature < _minTemprature)
	{
		_currentTemprature = _minTemprature;
	}
	else if (_currentTemprature > _maxTemprature)
	{
		_currentTemprature = _maxTemprature;
	}
	// change last temprature
	_lastTemprature = _currentTemprature;
	// return sensor data
	return _currentTemprature;
}
//delta (min-max)ABS
//random = min + delta