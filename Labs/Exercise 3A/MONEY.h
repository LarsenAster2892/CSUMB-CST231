//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 3A - Problem 1
//  (CLASS HEADER FILE)
// *******************************************************
#ifndef MONEY_H
#define MONEY_H

class Money
{
  private:
    enum Sign { NEGATIVE = -1, POSITIVE = 1 };
    Sign sign_;

	bool acct_style_ ;
    
	int dollars_;
    int cents_;
    void zero();
    void normalize();
	void convert_double(double amount);

  public:
    Money(int dollars = 0, int cents = 0);
    Money(double amount);
	double amount() const { return (sign_ * (dollars_ + (cents_ / 100.00))); }
	double amount(double amount);
    int dollars() const { return sign_ * dollars_; }
    int dollars(int dollars);
    int cents() const { return cents_; }
    int cents(int cents);
	const Money & max(const Money &) const;
	const Money & min(const Money &) const;
	
	Money operator+(const Money &) const;
	Money operator-(const Money &) const;

	Money operator/(double ) const;

	void use_sign();
	void use_parens();

	void show() const;
};
	Money operator*(double factor, const Money &m);
	Money operator*(const Money &m, double factor);
#endif

