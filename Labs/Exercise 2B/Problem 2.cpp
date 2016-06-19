//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 2B - Problem 2
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
}

Money::Money(int dollars, int cents)
{
  zero();
  (*this).dollars(dollars);
  (*this).cents(cents);
}

Money::Money(double amount)
{
  zero();
  amount += (amount < 0 ? -0.005 : 0.005);
  cents(int(amount * 100));
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

void Money::show() const
{
  std::cout << (sign_ == NEGATIVE ? "-" : "") << '$' << dollars_
    << '.' << (cents_ < 10 ? "0" : "") << cents_;
}
