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

enum scales { FARRENHEIT = 'F', CELSIUS = 'C', KELVIN = 'K' };

class Temperature
{
  private:
    enum Sign { NEGATIVE = -1, POSITIVE = 1 };
    Sign sign_;

	
	scales scale_;
	double temp_;
	
	static double FtoC (double ftemp);
	static double CtoF (double ctemp);
	static double KtoC (double ktemp);
	static double CtoK (double ctemp);

  public:
    Temperature(double inTemp = 0, scales inScale = FARRENHEIT  );

	double fahrenheit();
	void fahrenheit(double amount);
	
	double celsius();
	void celsius(double amount);

	double kelvin();
	void kelvin(double amount);

	char Scale() const { return ((char)(scale_)); }
	void Scale(scales inScale);

//
// --- Operators
//
	bool operator<(const Temperature &t) const;
	bool operator>(const Temperature &t) const;
	bool operator==(const Temperature &t) const;
	bool operator!=(const Temperature &t) const;
	bool operator<=(const Temperature &t) const;
	bool operator>=(const Temperature &t) const;

//
//  -- Stream Functions
//
	friend std::ostream & operator<<(std::ostream &os, const Temperature &t);
	friend std::istream & operator>>(std::istream &is, Temperature &t);
};
//
// unary Operators
// 

   Temperature operator+(const Temperature &a);
   Temperature operator-(const Temperature &a);


   Temperature operator+(const Temperature &a, const Temperature &b);
   Temperature operator-(const Temperature &a, const Temperature &b);
   
   
   std::ostream & operator<<(std::ostream &os, const Temperature &t);
   std::istream & operator>>(std::istream &is, Temperature &t);

#endif

