//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 3B - Problem 2
//  (CLASS HEADER FILE)
// *******************************************************
#ifndef TEMPERATURE_H
#define TEMPERATURE_H

class Temperature
{
  private:
    enum Sign { NEGATIVE = -1, POSITIVE = 1 };
    Sign sign_;
    
	double temp_;
 
  public:
    Temperature(double temp = 0);

	double fahrenheit(void) const { return (sign_ * temp_); }
	void fahrenheit(double amount);

	friend std::ostream & operator<<(std::ostream &os, const Temperature &t);
	friend std::istream & operator>>(std::istream &is, Temperature &t);
};
	std::ostream & operator<<(std::ostream &os, const Temperature &t);
	std::istream & operator>>(std::istream &is, Temperature &t);
#endif

