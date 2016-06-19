//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 3B - Problem 3
//  (CLASS METHODS)
// *******************************************************
//
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include "MONEY2.h"
//
// ------  Class Methods ------
// Method definitions for the Money class
//
// ------  zero initialize function ---
//
void Money::zero()
{
  sign_ = POSITIVE;
  dollars_ = cents_ = 0;
  acct_style_ = false;
}
//
// ------  dollar cents constructor ---
//

Money::Money(int dollars, int cents)
{
  zero();
  (*this).dollars(dollars);
  (*this).cents(cents);
}
//
// ------  double constructor  ---
//

Money::Money(double amount)
{

  convert_double(amount);	
}
//
// ------  conversion function ---
//

void Money::convert_double(double amount)
{  
  zero();
  amount += (amount < 0 ? -0.005 : 0.005);
  cents(int(amount * 100));
}

//
// ------  amount accessor ---
//
double Money::amount(double new_amount)
{
	double temp = (*this).amount();
	convert_double(new_amount);
	return temp;
}
//
// ------  dollars accessor ---
//
int Money::dollars(int dollars)
{
  int temp = (*this).dollars();
  if (dollars < 0) {
    sign_ = NEGATIVE;
    dollars_ = -dollars;
  }
  else {
    sign_ = POSITIVE;
    dollars_ = dollars;
  }
  return temp;
}
//
// ------  cents accessor ---
//
int Money::cents(int cents)
{
  int temp = (*this).cents();
  cents_ = cents;
  normalize();
  return temp;
}

//
// ------  normalize balance function ---
//
void Money::normalize()
{
  int total = sign_ * (100 * dollars_ + cents_);
  if (total < 0) {
    sign_ = NEGATIVE;
    total *= -1;
  }
  else {
    sign_ = POSITIVE;
  }
  dollars_ = total / 100;
  cents_ = total % 100;
}


//
// ------  max method  ---
//
const Money & Money::max(const Money & m) const
{
	
	return (amount() < m.amount() ?  m : (*this)); 
}

//
// ------  min method  ---
//
const Money & Money::min(const Money & m) const
{
	
	return (amount() > m.amount() ? m : (*this)); 
}



//
// ------  show method ---
//
void Money::show() const
{
  if (acct_style_) 
	std::cout << (sign_ == NEGATIVE ? "(" : "") << '$' << dollars_
       << '.' << (cents_ < 10 ? "0" : "") << cents_
	    << (sign_ == NEGATIVE ? ")" : "") ;
  else
	std::cout << (sign_ == NEGATIVE ? "-" : "") << '$' << dollars_
       << '.' << (cents_ < 10 ? "0" : "") << cents_;
}

//
// ------  use sign method ---
//
void Money::use_sign()
{
 	acct_style_ = false;
}

//
// ------  use parens method ---
//

void Money::use_parens()
{
	acct_style_ = true;
}


//
// ------  (+) operator  ---
//

Money Money::operator+(const Money & m) const
{
	return Money(m.amount() + amount());	 
}

//
// ------  (-) operator  ---
//

Money Money::operator-(const Money & m) const
{
	 return Money(amount() - m.amount());
}

//
// ------  (*) operator function 1 ---
//

Money operator*(double factor, const Money &m)
{
	return Money(m.amount() * factor);	 
}

//
// ------  (*) operator function 2 ---
//

Money operator*(const Money &m, double factor)
{
	return Money(m.amount() * factor);	 
}

//
// ------  (/) operator  ---
//
Money Money::operator/(double value) const
{
	Money temp;
	if (value != 0) 
	  temp.amount(amount() / value);
	return temp;
}


std::ostream & operator<<(std::ostream &os, const Money &m)
{
//	os << m.dollars() << " dollars "
//	   << (m.cents() < 10 ? "0" : "")
//	   << m.cents() << " cents";

 	 if (m.acct_style_) 
		os << ((m.sign_ == m.NEGATIVE) ? "(" : "") << '$' << m.dollars_
		   << '.' << (m.cents_ < 10 ? "0" : "") << m.cents_
	       << ((m.sign_ == m.NEGATIVE) ? ")" : "") ;
     else
    	    os << (m.sign_ == m.NEGATIVE ? "-" : "") << '$' << m.dollars_
            << '.' << (m.cents_ < 10 ? "0" : "") << m.cents_;
	
	return os;
}

std::istream & operator>>(std::istream &is, Money &m)
{
	int dollars = 0, cents = 0;
	char first_char;

	is >> first_char;
	is.putback(first_char);

	if (first_char < '0' || first_char >'9') 
	{
		is.setf( std::ios::failbit);
	}
	else {
		bool success = (bool)(is >> dollars);
		success = success && (is.peek() == 'd') && is.ignore();
		success = success && isdigit(is.peek()) && (is >> cents);
		success = success && (is.peek() == 'c') && is.ignore();
		m = Money(dollars,cents);
	}
	return is;
}