#pragma once
#include "DatabaseDownloader.h"
#include <iostream>

using namespace std;

class Dashboard
{
private:
	// the user will define what is considered an extreme sway in degrees between consecutive tests
	int _extremeSway;	

	DatabaseDownloader* _databaseDownloader;
	void DisplayAverageTemperature();

public:
	Dashboard(int extremeSway,string databaseName, string tableName);
	~Dashboard();
	void DisplayNumberOfExtremeTemperatureChanges();
	void DisplayAllData();
	int GetNumberOfPreviousTestsFromDatabase();

};

