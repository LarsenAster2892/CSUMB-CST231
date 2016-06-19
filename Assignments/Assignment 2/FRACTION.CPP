//********************************************************
// File Name   : Fraction.ccp 
// Author      : Clarence Mitchell
// Assignment  : Number 2
// Date Due    : July 10, 2003 (11:59 PM)
// Description : Class non inline members
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "FRACTION.H"
//
// ------  Class Methods ------
// Method definitions for the Fraction class
//
// ------  Constructors  ---
//
Fraction::Fraction()
{
	numerator_ = 0;
	denominator_ = 1;
}

Fraction::Fraction(int numerator)
{
	numerator_ = numerator;
	denominator_ = 1;

}


Fraction::Fraction(int numerator, int denominator)
{

	numerator_ = numerator;
	denominator_ = denominator;
	normalize();

}


// --- Mutators -----
void Fraction::num(int new_num)
{
	numerator_ = new_num;
	normalize();

}

void Fraction::den(int new_den)
{
	denominator_ = new_den;
	normalize();
}




void Fraction::normalize(void)
{
	if (denominator_ == 0) {
		std::cerr << " Error!! Attempt to set denominator to zero. " << std::endl;
		std::cerr << "    Fraction reset to zero. " << std::endl;
		numerator_ = 0;
		denominator_ = 1;
	}
	else{
		if (numerator_ == 0) {
			denominator_ = 1;
		}
		else{
			if (denominator_ < 0) {
				denominator_ = denominator_ * -1;
    			numerator_ = numerator_  * -1;
			}
			Convert2Lowest();
		}
	} 
}


// ----------------------------------------------
//  In order find the lowest term, the Greatest Common Divisor (GCD)
//  must be found.
//
void Fraction::Convert2Lowest(void)
{	
	int minvalue, maxvalue;
	int tmpnum = (numerator_ < 0 ? numerator_ * -1 : numerator_);
	int tmpden = (denominator_ < 0 ? denominator_ * -1 : denominator_);
	
	minvalue = (tmpnum < tmpden ? tmpnum : tmpden);
	maxvalue = (tmpnum + tmpden) - minvalue;
	int gcdvalue = GCD(minvalue, maxvalue);

	numerator_ = numerator_ / gcdvalue;
	denominator_ = denominator_ / gcdvalue;

}



int Fraction::GCD( int numerator, int denominator )

{
	
	int remainder = denominator % numerator;
	
	if ( remainder != 0 )
		return GCD( remainder,numerator );
	
	return numerator;
}

Fraction Fraction::invert(void)
{
	Fraction temp(denominator_,numerator_);
	return temp;
}
//
// --- STREAM OVERLOAD OPERATORS ---
std::ostream & operator<<(std::ostream &os, const Fraction &f)
{

    os <<  f.numerator_ << "/"  << f.denominator_;

	return os;
}
std::istream & operator>>(std::istream &is, Fraction &f)
{
	int tempNum = 0, tempDem = 1, tempSign = 1;
	char first_char, next_char;

	is >> first_char;
	next_char = is.peek();
	is.putback(first_char);

	if ((first_char < '0' || first_char >'9') && 
		((first_char == '-' || first_char != '+') &&
		(next_char < '0' || next_char > '9')))
	{
		is.setf( std::ios::failbit);
	}
	else {
		bool success;
		success = ((is >> tempNum) ? true : false);
		success = success && (bool)(is.peek() == '/') && is.ignore();
		success = success && (next_char = is.peek()) && ((isdigit(next_char) || (next_char == '-' || next_char == '+')));
		success = success && (is >> tempDem);
		f = Fraction(tempNum, tempDem);
	}
	return is;
}
//
// --- General Fraction Compare Function
//

int Fraction::FracCmp(const Fraction &f1) const
{
	int tmpNum1, tmpNum2;
	tmpNum1 = num() * f1.den();
	tmpNum2 = f1.num() * den();

	return (tmpNum1 - tmpNum2);	 

}
//
// ------  (+) operator unary ---
//

Fraction operator+(const Fraction &f)
{

	return Fraction(f.num(), f.den());	 
}

//
// ------  (-) operator unary  ---
//

Fraction operator-(const Fraction &f)
{
	return Fraction(f.num() * -1, f.den());	 

}


//
// ------  (+) operator function binary  ---
//

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
	int commTerm, tmpNum1, tmpNum2;
	commTerm = f1.den() * f2.den();
	tmpNum1 = f1.num() * f2.den();
	tmpNum2 = f2.num() * f1.den();

	return Fraction(tmpNum1 + tmpNum2, commTerm);	 
}

//
// ------  (-) operator function binary  ---
//

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
	int commTerm, tmpNum1, tmpNum2;
	commTerm = f1.den() * f2.den();
	tmpNum1 = f1.num() * f2.den();
	tmpNum2 = f2.num() * f1.den();

	return Fraction(tmpNum1 - tmpNum2, commTerm);	 
}


//
// ------  (*) operator function  ---
//

Fraction operator*(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.num() * f2.num(), f1.den() * f2.den());	 
}

//
// ------  (*) operator function  ---
//

Fraction operator/(const Fraction &f1, const Fraction &f2)
{
	return Fraction(f1.num() * f2.den(), f1.den() * f2.num());	 
}


//
// ------  (++) operator function (prefix)  ---
//
Fraction Fraction::operator++()
{
	numerator_ +=  denominator_;
	normalize();
	return *this;
}

//
// ------  (++) operator function (postfix)  ---
//

Fraction Fraction::operator++(int)
{
	Fraction temp(numerator_, denominator_);
	numerator_ += 	denominator_;
	normalize();
	return temp;
}

//
// ------  (--) operator function (prefix)  ---
//

Fraction Fraction::operator--()
{
	numerator_ -= 	denominator_;
	normalize();
	return *this;
}


//
// ------  (--) operator function (postfix)  ---
//

Fraction Fraction::operator--(int)
{
	Fraction temp(numerator_, denominator_);
	numerator_ -= 	denominator_;
	normalize();
	return temp;
}

bool Fraction::operator<(const Fraction &f) const
{
  return  (FracCmp(f) < 0 ) ;
}

bool Fraction::operator>(const Fraction &f) const
{
  return (FracCmp(f) > 0 );
}

bool Fraction::operator==(const Fraction &f) const
{
  return (FracCmp(f) == 0 );
}

bool Fraction::operator<=(const Fraction &f) const
{
  return (FracCmp(f) <= 0 );
}

bool Fraction::operator>=(const Fraction &f) const
{
  return (FracCmp(f) >= 0 );
}

bool Fraction::operator!=(const Fraction &f) const
{
  return (FracCmp(f) != 0 );
}
