#include <iostream>
#include "SensorHandler.h"
#include "Dashboard.h"
#include "DatabaseUploader.h"

using namespace std;
int main()
{

	int userExtremeSway = 0;
	bool isUserExtremeSwayLegal = false;
	
	// Get extreme sway from user
	while (!isUserExtremeSwayLegal)
	{
		cout << "Please define what you consider to be an extreme temperature change per day (1 - 10 degrees): " << endl;
		cin >> userExtremeSway;
		if (userExtremeSway <= 10 && userExtremeSway >= 1)
		{
			isUserExtremeSwayLegal = true;
		}
		else
		{
			cout << "Invalid Input: please try again" << endl;
		}
	}
	

	// Initialize Dashboard, SensorHandler and DatabaseUploader
	DatabaseUploader uploader;
	Dashboard dashboard(userExtremeSway);
	int numberOfPreviousTests = dashboard.GetNumberOfPreviousTestsFromDatabase();
	SensorHandler sensorHandler(numberOfPreviousTests);
	
	// Loop
	bool isProgramRunning = true;
	int input = 0;
	while (isProgramRunning)
	{
		cout << endl;
		cout << "Press [1] to measure temperatures and upload data " << endl;
		cout << "Press [2] to display data from the database " << endl;
		cout << "Press [3] to exit program " << endl;
		cin >> input;

		switch (input)
		{
			case 1:
				uploader.UploadSensorData( sensorHandler.GenerateFakeSensorData() );
				break;

			case 2:
				dashboard.DisplayAllData();
				break;

			case 3:
				isProgramRunning = false;
				break;

			default:
				cout << "Invalid Input: please try again" << endl;
				break;
		}

	}

	

	return 0;
}