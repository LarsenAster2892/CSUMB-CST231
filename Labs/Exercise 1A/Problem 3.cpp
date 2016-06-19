//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 1A - Problem 3
// *******************************************************
//
// ------  Includes -----

#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <iomanip>
#include <string>
using std::string;
int main()
{
  string Fname;		// user's first name
  char BorderChar;  // Characther for Border
  long PaddingSize;  // Padding size

  // Read the user's name
  cout << "Enter your first name   : ";
  cin >> Fname; 

   // Read the Border Character
  cout << "Enter a border character: ";
  cin >> BorderChar;

   // Read the Padding Size
  cout << "Enter a padding size    : ";
  cin >> PaddingSize;




  // Create the greeting
  string greeting = "Hello, " + Fname + '!';
  string padding(PaddingSize, ' ');
  string greetingline = padding + greeting + padding;	
  // Create display lines
  string spacer(greetingline.length(), ' ');
  string paddingLine = BorderChar + spacer + BorderChar;
  string borderline(paddingLine.length(), '*');

  // Display greeting
  cout << endl;
  cout << borderline << endl;
  for (int intLoop = 1; intLoop <= PaddingSize; intLoop++)
	cout << paddingLine << endl;
  cout << BorderChar << greetingline << BorderChar << endl;
  for (int intLoop = 1; intLoop <= PaddingSize; intLoop++)
	  cout << paddingLine << endl;
  cout << borderline << endl;

  return 0;
}
