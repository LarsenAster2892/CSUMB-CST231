//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 3B - Problem 2
//  (DRIVER)
// *******************************************************
//
// ------  Includes ------
#include <iostream>

#include "TEMPERATURE.h"
using std::cin; using std::cout; using std::endl;

//
// ------  Main (Driver) ------
int main(void)
{
	Temperature Temp1(98.6);
	Temperature Temp2;
	Temperature Temp3 = 105.8;
	double fatal;

	cout << " Enter your current temperature:" ;
	
	while (!(cin >> Temp2)){
		cout << "Invalid temperature. Please enter in form of 999.9F" << endl;
		cout << endl;
	}



	cout << " Ideal body temperature is " << Temp1 << endl;
	cout << " Your temperature is " <<	Temp2 << 	 endl;
	cout << " The difference is " << Temp2.fahrenheit() - Temp1.fahrenheit() << endl;

	cout << " What is the fatal temperature? ";

	cin >> fatal;
	Temp3.fahrenheit(fatal);

	cout <<  " You are " << Temp3.fahrenheit() - Temp2.fahrenheit() << " away from fatal "<< endl;

	
	return 0;
}

