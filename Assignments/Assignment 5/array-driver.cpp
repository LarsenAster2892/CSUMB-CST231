//********************************************************
// File Name   : array-driver.cpp 
// Author      : Clarence Mitchell
// Assignment  : Number 5
// Date Due    : July 31, 2003 (11:59 PM)
// Description : (array-driver.cpp) Driver for 
//                testing Array Exception class
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
#include <iostream>
#include <iomanip>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
#include "array.h"


int main(void)
{
 Array<int> TestArray1(5,10);
 Array<int> TestArray2;
 
 try {
  cout << "Average of array1 is " << TestArray1.average() << endl;
  cout << "Average of array2 is " << TestArray2.average() << endl;
 }
 catch(Array<int>::InvalidStateException & ise)
 {
	 cout << ise.what() ;
 }

  return 0;
}


