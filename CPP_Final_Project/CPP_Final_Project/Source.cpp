#include <iostream>
#include "HeatSensor.h"

using namespace std;
int main()
{
	cout << "Here We Go" << endl;
	HeatSensor h(-20, 50, 7);
	cout << h.GetSensorData() << endl;
	cout << h.GetSensorData() << endl;
	cout << h.GetSensorData() << endl;
	cout << h.GetSensorData() << endl;
	return 0;
}