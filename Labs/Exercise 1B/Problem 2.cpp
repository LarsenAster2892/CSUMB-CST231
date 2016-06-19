//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 1B - Problem 2
// *******************************************************
//
// ------  Includes ------
#include <iostream>
#include <string>
#include <cstring>
//
// --- Using for easy of use -----
//
using std::cin; 
using std::cout;
using std::endl;
using std::string;
using std::getline;
//
// --- Structures
//
struct Car
{
	string	Make;	     	// Auto - Make
	int		YearBuilt;		// Auto - Year
};


//
// --- Functions signitures -----
//
//
// -- Initialize the structure
//

int main()
{
	int number_of_cars;
	string in_make;
	int in_year;

	cout << "How many cars do you wish to catalog? ";
	cin >> number_of_cars;
	
	if (number_of_cars) 
	{
		Car *pcars = new Car [number_of_cars];
		for (int tmpLoop = 0 ; tmpLoop < number_of_cars; tmpLoop++){
			cout << "Car #:" << tmpLoop + 1 << endl;
			cout << "      Please enter the make : ";
			cin.get();
			getline(cin,in_make);
			cout << "      Please enter the year made: ";
			cin >> in_year;
			cout << endl;
			pcars[tmpLoop].Make = in_make;
			pcars[tmpLoop].YearBuilt = in_year;
		}
		cout << "Here is your collection:" << endl;
		for (int tmpLoop = 0; tmpLoop < number_of_cars; tmpLoop++){
			cout << "  " 
				 << pcars[tmpLoop].YearBuilt
				 << " "
				 << pcars[tmpLoop].Make
				 << endl;
			
		}
		
		delete [] pcars;
	}

  return 0;
}
