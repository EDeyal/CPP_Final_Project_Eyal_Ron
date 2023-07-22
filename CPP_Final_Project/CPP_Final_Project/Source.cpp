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

	// Initialize DatabaseUploader/Downloader

	// -------- Optional Changes for User --------
	
	// If the user wants to create a new database - they should change the value of databaseName
	string databaseName = "temperatures2023";
	// When changing databaseName, you can also change tableName
	string tableName = "temperatureTests";

	// -------------------------------------------

	DatabaseUploader* uploader = new DatabaseUploader(databaseName,tableName);
	DatabaseDownloader* downloader = new DatabaseDownloader(databaseName, tableName);
	
	// Initialize SensorHandler
	int numberOfPreviousTests = downloader->GetNumberOfPreviousTests();
	int lastTemperatureMeasured;
	
	SensorHandler sensorHandler(downloader);

	// Initialize Dashboard
	Dashboard dashboard(userExtremeSway, downloader);
	
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
				system("cls");
				uploader->UploadSensorData( sensorHandler.GetSensorData() );
				break;

			case 2:
				system("cls");
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

	delete uploader;
	delete downloader;


	return 0;
}