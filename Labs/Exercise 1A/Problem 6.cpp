//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 1A - Problem 6
// *******************************************************
//
// ------  Includes ------
#include <iostream>
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

// -- Constants
const string cNot = "NOT ";    // Word Not

//
// --- Functions signitures -----

// -- Get string from User
string ReadString (void);
//
// -- Check for Panidrome --
bool IsPalindrome(string);

int main()
{
  string user_input;		// Input from user

  // Read the the strings
  user_input = ReadString();
  string not_word("");
  
  if (!(IsPalindrome(user_input) ))
	  not_word = cNot;

  cout << "-------------------------------" << endl;
  cout << "The string you entered, " 
	   << user_input 
	   << ", is "
	   << not_word
	   << "a palindrome "
	   << endl;

  return 0;
}

string ReadString(void)
{
	string return_string;							// Temporary string to return
	cout << "      Please enter a Palindrome : ";	// Prompt user for input
	//cin.get();										// Used to get carriage
	getline(cin,return_string);
	return return_string;
}

bool IsPalindrome(string in_userinput)
{	
	string conv_input;
	size_t iStart = 0;
	size_t iEnd = in_userinput.length() - 1;
	long iPos = 0;
	char tmp;

	for (size_t intLoop =0; intLoop <= iEnd; intLoop++){
		tmp = in_userinput[intLoop];

		if (isalpha(tmp)) {
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

