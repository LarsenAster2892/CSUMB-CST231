//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 2B - Problem 2
//  (DRIVER)
// *******************************************************
//
// ------  Includes ------
#include <iostream>

#include "MONEY.h"
using std::cin; using std::cout; using std::endl;

//
// ------  Main (Driver) ------
int main(void)
{
	Money Giveme(10,120);
	Money IWant(11.20);
	Money GotNone;

	cout << " I gave you " ;	Giveme.show();	cout << endl;
	cout << " You Wanted " ;	IWant.show(); 	cout << endl;
	cout << " you got nothing " ; GotNone.show() ; cout << endl;
	return 0;

}

