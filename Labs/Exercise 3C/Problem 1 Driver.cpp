//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 3C - Problem 1
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
	Temperature Temp1(98.6,FARRENHEIT );
	Temperature Temp2;


	double fatal;
	fatal;


	cout << " The Body Temperature is " << endl;
	Temp1.Scale(CELSIUS);
	cout << "    Celsius    : " << Temp1 << endl;
	Temp1.Scale(KELVIN);
	cout << "    Kelven     : " << Temp1 << endl;
	Temp1.Scale(FARRENHEIT);
	cout << "    Fahrenheit : " << Temp1 << endl;

	



	cout << " Enter your current temperature:" ;
	
	while (!(cin >> Temp2)){
		cout << "Invalid temperature. Please enter in form of 999.99S" << endl;
		cout << endl;
	}


	cout << " The Temperature you Entered is in " << Temp2.Scale() <<endl;
	Temperature Temp3;
	Temp3 = Temp2;
	cout << "    Celsius    : " << Temp3.celsius() << endl;
	cout << "    Kelven     : " << Temp3.kelvin() << endl;
	cout << "    Fahrenheit : " << Temp3.fahrenheit() << endl;


	Temperature Temp4 = Temp2 - Temp1 ;
	Temp3 = Temp2 + Temp1;

	cout << " Difference your temperature and body temperature is : " << Temp4 << endl;
	cout << " Sum your temperature and body temperature is : " << Temp3 << endl;
	return 0;
}

