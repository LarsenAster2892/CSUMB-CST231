//********************************************************
// Name      : Clarence Mitchell
// Class     : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor: Krofchok
// ********************************************************
//  HOMEWORK - Exercise 1B - Problem 4
// *******************************************************
//
// ------  Includes -----
#include <iostream>
using std::cin; using std::cout; using std::endl;

#include <iomanip>
#include <string>
using std::string;

const int cMax_Scores = 10;

int ReadScores(int[]);
int AverageScore(int[],int);
void DisplayScores(int[],int);


int main()
{
  int Scores[10], Num_Scores;		// Array of Golf Scores

  // Read the the strings
  Num_Scores = ReadScores(Scores);
 
  cout << endl;	
  cout << "Your Golf Scores entered and Average: " << endl;
  cout << "--------------------------------------" << endl;

  if (Num_Scores > 0) 
  {
	DisplayScores(Scores, Num_Scores);
    cout << "Average = " << AverageScore(Scores, Num_Scores) << endl;  

  }
  else
   cout << "No Scores Entered" << endl;
  
  cout << "-------------------------------------" << endl;
  cout << endl;


  return 0;
}

int ReadScores(int scores[])
{
  int intLoop = 0;
   cout << "You may enter up to 10 scores <q to terminate>" << endl;
   cout << "Enter Score Number 1  :" ;	
	  while (intLoop < cMax_Scores && cin >> scores[intLoop])
	  {
		  intLoop += 1;
		  if (intLoop < cMax_Scores) 
		      cout << "Enter Score Number " << intLoop + 1 << " : " ;
	  }
	return (intLoop);
}

int AverageScore(int scores[], int num_scores)
{	
	int totalscores = 0, intLoop;

	for (intLoop = 0; intLoop < num_scores; intLoop++) 		
		totalscores += scores[intLoop];

	return (totalscores / intLoop) ;

}


void DisplayScores(int scores[], int num_scores)
{
	
	for(int intLoop = 0; intLoop < num_scores; intLoop++)
			cout << scores[intLoop] << " " ;
	cout << endl;
}