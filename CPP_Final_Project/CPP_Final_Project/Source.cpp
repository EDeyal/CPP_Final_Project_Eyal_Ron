#include <iostream>
#include "SensorHandler.h"
#include "Dashboard.h"
#include "DatabaseUploader.h"

using namespace std;

// ---- IMPORTANT! ----
/* 
* For this program to work, you have to first install MySQL on your machine.
* A Link to our video explaining exactly what and how to install: https://drive.google.com/file/d/1IKPK3eTK4ZDNFgdrPSHpdQ4oiWAbCtf5/view?usp=sharing
* Or - On the MySQL website, go to:
* Downloads � MySQL Community (GPL) Downloads � MySQL Installer for Windows � download first option (Windows (x86, 32-bit), MSI Installer)
*
* MySQL Server Version: 8.0.11 - x64
* Connector/C++ Version: 1.1.11 - x64
*
* Link to explanation video about the project: https://drive.google.com/file/d/1VdTynPyO00-uEStp6USdlI_K8F51Av7v/view?usp=drive_link
*/

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