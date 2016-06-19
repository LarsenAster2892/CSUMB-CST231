//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 3B - Problem 2
//  (CLASS METHODS)
// *******************************************************
//
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include "TEMPERATURE.h"
//
// ------  Class Methods ------
// Method definitions for the Money class
//
// ------ Constructor ---
//
Temperature::Temperature(double temp)
{
  
   sign_ = (temp < 0 ? NEGATIVE : POSITIVE);
  temp_ = temp;
}


//
// ------  fahrenheit mutator ---
//
void Temperature::fahrenheit(double temp)
{
   sign_ = (temp < 0 ? NEGATIVE : POSITIVE);
  temp_ = temp;
}

//
// --- STREAM OVERLOAD OPERATORS ---
std::ostream & operator<<(std::ostream &os, const Temperature &t)
{

    os << (t.sign_ == t.NEGATIVE ? "-" : "") << t.temp_  << 'F';

	return os;
}
std::istream & operator>>(std::istream &is, Temperature &t)
{
	double temp = 0.0;
	char first_char;

	is >> first_char;
	is.putback(first_char);

	if (first_char < '0' || first_char >'9') 
	{
		is.setf( std::ios::failbit);
	}
	else {
		bool success = (bool)(is >> temp);
		success = success && (is.peek() == 'F') && is.ignore();
		if (success) 
			t = Temperature(temp);
		else
			is.setf( std::ios::failbit);
	}
	return is;
}