//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 1B - Problem 3
// *******************************************************
//
// ------  Includes ------
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include <cctype>
//
// --- Using for easy of use -----
//
using std::cin; 
using std::cout;
using std::endl;
using std::string;
using std::getline;
using std::ifstream;

// -- Constants
const string cNot = "NOT ";    // Word Not
const char *  pFileLocation = "E:\\CISP400\\HOMEWORK\\DATAFILES\\palindromes.txt";   // Location of datafile

//
// --- Functions signitures -----

//
// -- Check for Panidrome --
bool IsPalindrome(string);

int main()
{
   //
   // ---- File object
   //
   ifstream fin;

   fin.open(pFileLocation);


	cout << "The contents of " << pFileLocation << " is :" << endl;
	cout << string(60,'-') << endl;

	string file_input;

  
  while (getline(fin,file_input)) {
	 
	
	 

	  cout << file_input 
		   << "   " ;
	  cout.width(45 - file_input.length());	 
	  cout <<(IsPalindrome(file_input) ? "   " : cNot)
		   << "a palindrome "
     	   << endl;
  }
  fin.close();

  return 0;
}


bool IsPalindrome(string in_string)
{	
	string conv_input;
	size_t iStart = 0;
	size_t iEnd = in_string.length() - 1;
	long iPos = 0;
	char tmp;

	for (size_t intLoop =0; intLoop <= iEnd; intLoop++){
		tmp = in_string[intLoop];

		if (isalnum(tmp)) {
		   tmp = tolower(tmp);
		   conv_input += tmp;
		}   
	}
	
	iEnd = conv_input.length() -1;

	for ( ;
		  (iStart < iEnd) && (conv_input[iStart] == conv_input[iEnd]);
		  iEnd--, iStart++) ;	

	return (iStart >= iEnd);
}

