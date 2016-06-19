//********************************************************
// File Name   : fraction-driver.cpp 
// Author      : Clarence Mitchell
// Assignment  : Number 5
// Date Due    : July 31, 2003 (11:59 PM)
// Description : (fraction-driver.cpp) Driver for 
//                testing Fraction Exceptions
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
#include "fraction.h"

int main(void)
{
	
	try
	{
	Fraction f1(2,3);
	cout << "f1 =" << f1 << endl;
	Fraction f2(1,0);
	cout << "f2 =" << f2 << endl;

	cout << "f1 =" << f1 << endl;
	}

	catch(Fraction::IllegalArgumentException & iae)
	{
		cout << iae.what() << endl;
	}
	try{
	Fraction f3;
	cout << "f3 =" << f3 << endl;

	f3.invert();
	cout << "f3 =" << f3 << endl;


	}
	catch(Fraction::InvalidStateException & iae)
	{
		cout << iae.what() << endl;
	}
	
	Fraction *f4 = Fraction().getInstance(1,2);

	if (f4) 
     cout << "f4 =" << *f4 << endl;

 	Fraction *f5 = Fraction().getInstance();

	if (f5) 
     cout << "f5 =" << *f5 << endl;

	cout << "end of program" << endl;

}

