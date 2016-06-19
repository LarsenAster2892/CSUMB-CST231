//********************************************************
// File Name   : Compare Test Driver.h  
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : July 24, 2003 (11:59 PM)
// Description : (Compare Test Driver.cpp) Test Driver for
//                 gmax and gmin template function
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::endl;
using std::string;

#include "compare.H"
 

// ------  Main (Driver) ------
int main(void)
{

	int ia = 20;
	int ib = 30;
	int iarr[4] = {4,10,30,3};

	double da = 3.45;
	double db = 2.45;
	double darr[5] = {100.5,50.57,75.5,10.9,1.0};

	string sa = "aa";
	string sb = "bb";
	string sarr[5] = {"aa","zz","bb","AA","ZZ"};

	cout << "The greater of " << ia << " and " << ib << " is " << gmax(ia,ib) << endl;
	cout << "The greater of " << da << " and " << db << " is " << gmax(da,db) << endl;
	cout << "The greater of " << sa << " and " << sb << " is " << gmax(sa,sb) << endl;
	cout << endl;

	cout << "The Lesser of " << ia << " and " << ib << " is " << gmin(ia,ib) << endl;
	cout << "The Lesser of " << da << " and " << db << " is " << gmin(da,db) << endl;
	cout << "The Lesser of " << sa << " and " << sb << " is " << gmin(sa,sb) << endl;
	cout << endl;

	cout << "The greatest value is " << gmax(iarr,4) << endl;
	cout << "The greatest value is " << gmax(darr,5) << endl;
	cout << "The greatest value is " << gmax(sarr,5) << endl;
	cout << endl;

	cout << "The least value is " << gmin(iarr,4) << endl;
	cout << "The least value is " << gmin(darr,5) << endl;
	cout << "The least value is " << gmin(sarr,5) << endl;
	cout << endl;

  return 0;
}

