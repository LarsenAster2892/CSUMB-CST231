//********************************************************
// File Name   : Fraction.h  
// Author      : Clarence Mitchell
// Assignment  : Number 5
// Date Due    : July 31, 2003 (11:59 PM)
// Description : Header file for flight class
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************

#ifndef FRACTION_h
#define FRACTION_h

class Fraction
{
  private:
	int numerator_;							  	
    int denominator_;
	
	// --- private functions ----
	void normalize(void);					   // checks Fraction for zero values and reset it.
	void Convert2Lowest(void);				   // Converts terms to lowest values
	static int GCD(int numerator, int denominator);   // Return Greatest Common Divisor
	int FracCmp(const Fraction &f1) const;

  public:
	#include "myexceptions.h"
    // --- Constructors ----

	Fraction(int numerator =0, int denominator = 1); // throw (Fraction::IllegalArgumentException &);

	//  --- static fatory metod ---
	static Fraction * getInstance(int num = 0, int den = 0);
	
	// --- Accessors -----
	int num() const { return (numerator_); }
	int den() const { return (denominator_); }

	// --- Conversion functions -------
	operator double() const { return ((double)(numerator_) / (double) (denominator_)); };

	//double decvalue() const { return ((double)(numerator_) / (double) (denominator_)); }
	// ---- Mutators -------
	void num(int new_num);				   				
	void den(int new_den); // throw (Fraction::IllegalArgumentException &);

	// --- Member Methods ---
	Fraction invert(void); // throw (Fraction::InvalidStateException &);

	// -- operators --

	Fraction operator++();
	Fraction operator++(int);

	Fraction operator--();
	Fraction operator--(int);

	bool operator<(const Fraction &f) const;
	bool operator>(const Fraction &f) const;
	bool operator==(const Fraction &f) const;
	bool operator<=(const Fraction &f) const;
	bool operator>=(const Fraction &f) const;
	bool operator!=(const Fraction &f) const;

	// -- stream functions ---
	friend std::ostream & operator<<(std::ostream &os, const Fraction &f);
	friend std::istream & operator>>(std::istream &is, Fraction &f);

};

	Fraction operator+(const Fraction &f);
	Fraction operator-(const Fraction &f);

	Fraction operator+(const Fraction &f1, const Fraction &f2);
	Fraction operator-(const Fraction &f1, const Fraction &f2);

	Fraction operator*(const Fraction &f1, const Fraction &f2);
	Fraction operator/(const Fraction &f1, const Fraction &f2);

	std::ostream & operator<<(std::ostream &os, const Fraction &f);
	std::istream & operator>>(std::istream &is, Fraction &f);

#endif