#include <iostream>
#include "SensorHandler.h"
#include "Dashboard.h"
using namespace std;
int main()
{
	cout << "Here We Go" << endl;
	SensorHandler sensorHandler;


	/*for (size_t i = 0; i < 5; i++)
	{
		SensorData sd= sensorHandler.GenerateFakeSensorData();
		string hmm = sd.ToString();
		cout << hmm << endl;
	}*/

	Dashboard dashboard(8);
	dashboard.DisplayAllData();
	dashboard.DisplayNumberOfExtremeTemperatureChanges();
	dashboard.DisplayAllData();

	return 0;
}