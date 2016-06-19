//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 3B - Problem 1
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
	
    Money AddMoney = Giveme + IWant;

	cout << " The Add Money is " ;
	AddMoney.show(); 
	cout << endl;

	Money SubMoney  = IWant - Giveme;

	cout << " The Sub Money is " ;
	SubMoney.show() ;
	cout << endl;

	SubMoney.use_parens();

	cout << " The account style Money is " ;
	SubMoney.show() ;
	cout << endl;

    Money MulMoney2 = Giveme * 2.0;

	cout << " The Mul Money * 2 is " ;
	MulMoney2.show(); 
	cout << endl;

    Money MulMoney4 = 4.0 * Giveme;

	cout << " The 4 * Mul Money  is " ;
	MulMoney4.show(); 
	cout << endl;

	Money DivMoney = IWant / (2.0);


	cout << " The div Money is " ;
	DivMoney.show() ;
	cout << endl;

	return 0;
}

