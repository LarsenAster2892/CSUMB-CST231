//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 1A - Problem 4
// *******************************************************
//
// ------  Includes -----
#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <iomanip>
#include <string>
using std::string;

const int cMax_Words = 10;

void ReadWords(string[]);
void SortByOrder(string[]);
void SortByLength(string[]);
void Swap(string &, string &);
void DisplayWords(string[]);


int main()
{
  string words[10];		// Array of words

  // Read the the strings
  ReadWords(words);
 
  cout << "-------------------------------" << endl;
  cout << "THE WORDS YOU ENTERED ARE: " << endl;
  cout << "-------------------------------" << endl;

  DisplayWords(words);

  
  SortByOrder(words);
  cout << endl;
  cout << "-------------------------------" << endl;
  cout << "THE WORDS SORTED BY ORDER ARE: " << endl;
  cout << "-------------------------------" << endl;
  cout << endl;

  DisplayWords(words);

  SortByLength(words);
  cout << endl;
  cout << "-------------------------------" << endl;
  cout << "THE WORDS SORTED BY LENGTH ARE:" << endl;
  cout << "-------------------------------" << endl;
  cout << endl;

  DisplayWords(words);



  return 0;
}

void ReadWords(string in_words[])
{
  for (int intLoop = 0; intLoop < cMax_Words; intLoop++) {
	  cout << "Enter Word Number " << intLoop + 1 << " : " ;
      cin >> in_words[intLoop]; 

	}
}

void SortByOrder(string in_words[])
{	
	for (int OutLoop = 0; OutLoop < cMax_Words; OutLoop++) 		
		for (int InLoop = OutLoop; InLoop < cMax_Words; InLoop++) {
			if (in_words[OutLoop] > in_words[InLoop]) 
				Swap(in_words[OutLoop], in_words[InLoop]);
		}	

}

void SortByLength(string in_words[])
{
	for (int OutLoop = 0; OutLoop < cMax_Words; OutLoop++) 		
		for (int InLoop = OutLoop; InLoop < cMax_Words; InLoop++) {
			if (in_words[OutLoop].length() > in_words[InLoop].length()) 
				Swap(in_words[OutLoop], in_words[InLoop]);
		}	

}

void Swap(string &word1, string &word2)
{
	string tempword;
	tempword = word1;
	word1 = word2;
	word2 = tempword;
}


void DisplayWords(string in_words[])
{
	cout << endl;
	for(int Loop = 0; Loop < cMax_Words; Loop++)
			cout << "Word " << Loop << ": " << in_words[Loop] << endl;
	cout << endl;
}