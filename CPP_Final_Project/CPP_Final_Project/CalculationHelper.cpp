#include "CalculationHelper.h"
#include <stdlib.h>
#include <time.h>

int CalculationHelper::GetRandomNumber(int lowerBound, int upperBound)
{
	// the total range from 0 to the maximum amount of steps
	int absoluteRange = abs(lowerBound - upperBound);

	// get a random number within absoluteRange
	int randomNumberFromRange = rand() % (absoluteRange + 1);
	
	// Adding the randomNumberFromRange we got to the lowerBound will get us a number between lowerBound and upperBound (including)
	int randomNumber = lowerBound + randomNumberFromRange;

	return randomNumber;
}
