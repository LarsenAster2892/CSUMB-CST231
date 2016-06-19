//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 3B - Problem 1
//  (CLASS METHODS)
// *******************************************************
//
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include "MONEY.h"
//
// ------  Class Methods ------
// Method definitions for the Money class
void Money::zero()
{
  sign_ = POSITIVE;
  dollars_ = cents_ = 0;
  acct_style_ = false;
}

Money::Money(int dollars, int cents)
{
  zero();
  (*this).dollars(dollars);
  (*this).cents(cents);
}

Money::Money(double amount)
{

  convert_double(amount);	
}

void Money::convert_double(double amount)
{  
  zero();
  amount += (amount < 0 ? -0.005 : 0.005);
  cents(int(amount * 100));
}


double Money::amount(double new_amount)
{
	double temp = (*this).amount();
	convert_double(new_amount);
	return temp;
}

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

int Money::cents(int cents)
{
  int temp = (*this).cents();
  cents_ = cents;
  normalize();
  return temp;
}

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


const Money & Money::max(const Money & m) const
{
	
	return (amount() < m.amount() ?  m : (*this)); 
}

const Money & Money::min(const Money & m) const
{
	
	return (amount() > m.amount() ? m : (*this)); 
}

Money Money::operator+(const Money & m) const
{
	return Money(m.amount() + amount());	 
}

Money Money::operator-(const Money & m) const
{
	 return Money(amount() - m.amount());
}

Money operator*(double factor, const Money &m)
{
	return Money(m.amount() * factor);	 
}

Money operator*(const Money &m, double factor)
{
	return Money(m.amount() * factor);	 
}


Money Money::operator/(double value) const
{
	Money temp;
	if (value != 0) 
	  temp.amount(amount() / value);
	return temp;
}

void Money::use_sign()
{
 	acct_style_ = false;
}

void Money::use_parens()
{
	acct_style_ = true;
}


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
