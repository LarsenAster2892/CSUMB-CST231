//********************************************************
// File Name   : StockHolding Test Driver.cpp 
// Author      : Clarence Mitchell
// Assignment  : Number 4
// Date Due    : July 24, 2003 (11:59 PM)
// Description : (StockHolding Test Driver.cpp) Driver for 
//                StockHolding class
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
#include "stockholding.h"


int main(void)
{
  StockPortfolio msStkP("Martha Stewart");
  StockPortfolio bgStkP("Bill Gates");

  msStkP[0].company("Microsoft");
  msStkP[0].buy(100,30.00);

  msStkP[1].company("Enclone");
  msStkP[1].buy(110,31.10);

  msStkP[2].company("Exon");
  msStkP[2].buy(120,32.20);

  msStkP[3].company("Xerox");
  msStkP[3].buy(130,33.30);

  msStkP[4].company("Intuit");
  msStkP[4].buy(140,34.40);

  msStkP[5].company("Computer Associates");
  msStkP[5].buy(150,35.50);

  msStkP[6].company("Hewlett Packard");
  msStkP[6].buy(160,36.60);

  msStkP[7].company("Dell");
  msStkP[7].buy(170,37.70);

  msStkP[8].company("Sun");
  msStkP[8].buy(180,38.80);

  msStkP[9].company("RedHat");
  msStkP[9].buy(190,39.90);
 
  cout << "Martha is holding:" << endl;
  cout << msStkP << endl;

  return 0;
}


