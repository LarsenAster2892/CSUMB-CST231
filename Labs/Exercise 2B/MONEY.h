//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 2B - Problem 2
//  (CLASS HEADER FILE)
// *******************************************************
#ifndef MONEY_H
#define MONEY_H

class Money
{
  private:
    enum Sign { NEGATIVE = -1, POSITIVE = 1 };
    Sign sign_;
    int dollars_;
    int cents_;
    void zero();
    void normalize();

  public:
    Money(int dollars = 0, int cents = 0);
    Money(double amount);
    int dollars() const { return sign_ * dollars_; }
    int dollars(int dollars);
    int cents() const { return cents_; }
    int cents(int cents);
    void show() const;
};

#endif

