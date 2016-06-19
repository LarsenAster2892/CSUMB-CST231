//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 1A - Problem 2
// *******************************************************
//
// ------  Includes -----

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <iomanip>
#include <string>

const int cMINs_IN_HOUR = 60;    // Number of Minutes in an Hour

long Convert2Minutes(long,long);

int main()
{ 
	long lng_hours, lng_mins;

  cout << "Enter number of hours: ";
  cin >> lng_hours;
  
  cout << "Enter number of mintues: ";
  cin >> lng_mins;
		 
  cout << lng_hours << " Hours and " 
	   << lng_mins << " minutes is equal to " 
	   << Convert2Minutes(lng_hours, lng_mins) << " mintues. " << std::endl;

 
  return 0;
}

long Convert2Minutes(long in_hours, long in_mins)
{
	return ((in_hours * cMINs_IN_HOUR) + in_mins);
}
