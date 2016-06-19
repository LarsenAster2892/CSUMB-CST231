//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 2C - Problem 2
//  (DRIVER)
// *******************************************************
//
// ------  Includes ------
#include <iostream>

#include "MONEY.h"
using std::cin; using std::cout; using std::endl;

//
// ------  Main (Driver) ------
int main(void)
{
	Money Giveme(10,12);
	Money IWant(11.20);
	Money GotNone;
	

	cout << " I gave you " <<	Giveme.amount() <<	 endl;
	cout << " You Wanted " <<	IWant.amount() << 	 endl;
	cout << " you got nothing " << GotNone.amount() << endl;

	cout << " Giving you more from " << Giveme.amount(20.35);
	cout <<  " To " << Giveme.amount() << endl;

    Money MaxMoney = Giveme.max(IWant), MinMoney = IWant.min(Giveme);

	cout << " The Max Money is " << MaxMoney.amount() << endl;
	cout << " The Min Money is " << MinMoney.amount() << endl;
	
    Giveme.add(IWant);

	cout << " The Add Money is " ;
	Giveme.show(); 
	cout << endl;

	IWant.sub(Giveme);

	cout << " The Sub Money is " ;
	IWant.show() ;
	cout << endl;

	IWant.use_parens();

	cout << " The account style Money is " ;
	IWant.show() ;
	cout << endl;

    Giveme.mul(2.0);

	cout << " The Mul Money is " ;
	Giveme.show(); 
	cout << endl;

	IWant.div(-1.0);

	cout << " The div Money is " ;
	IWant.show() ;
	cout << endl;

	return 0;
}

