//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 1B - Problem 1
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
//
// --- Structures
//
struct CandyBar
{
	string	BrandName;		// Name of Candybar
	double	Weight;			// Weight of Candybar
	int		Calories;		// Calories of Candybar
};


//
// --- Functions signitures -----
//
//
// -- Initialize the structure
//
void InitializeCandyBar (CandyBar & , 
						 string = "millennium munch", 
						 double = 2.85,
						 int = 350);				 

//
// -- Print the Structure --
//
void PrintCandyBar (CandyBar & );   

int main()
{
	CandyBar Snickers;

  InitializeCandyBar(Snickers );
  PrintCandyBar(Snickers);
  return 0;
}
//-----------------------------------------------------
//
//  
//
//-----------------------------------------------------
void InitializeCandyBar (CandyBar & in_struct_CandyBar,
						 string in_str_Name , 
						 double in_dbl_weight,
						 int in_int_calories)
{
	
	in_struct_CandyBar.BrandName = in_str_Name;
	in_struct_CandyBar.Weight = in_dbl_weight;
	in_struct_CandyBar.Calories = in_int_calories;
	
	return;

}
//-----------------------------------------------------
//
//  
//
//-----------------------------------------------------
void PrintCandyBar (CandyBar & in_struct_CandyBar)
{
	cout << endl;
	cout << "The current values of CandyBar are : " << endl;
	cout << "  BrandName = " << in_struct_CandyBar.BrandName << endl;
	cout << "  Weight    = " << in_struct_CandyBar.Weight << endl;
	cout << "  Calories  = " << in_struct_CandyBar.Calories << endl;
	cout << endl;
	return;

}