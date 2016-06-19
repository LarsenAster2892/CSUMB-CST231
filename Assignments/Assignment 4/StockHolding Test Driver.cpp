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
using std::endl;
using std::string;

#include "stockholding.h"


int main(void)
{
  StockHolding dell("Dell Computer", 5000, 31.63);
  StockHolding imclone("Imclone", 10000, 37.58);
  double amount;

  dell.show();
  imclone.show();

  amount = dell.buy(7000, 31.65);

  std::cout << "$" << amount << " worth of " << dell.company()
    << " stock purchased..." << std::endl;
  dell.show();

  dell.price(31.92);
  amount = dell;

  std::cout << "$" << amount << " worth of " << dell.company()
    << " stock purchased..." << std::endl;
  std::cout << dell << std::endl;

  
 
  StockHolding max = dell.max_value(imclone);
  std::cout << "Maximum valued holding:" << std::endl;
  max.show();

  amount = dell.sell(5000, 31.94);
  std::cout << "$" << amount << " worth of " << dell.company()
    << " stock sold..." << std::endl;
  dell.show();

  return 0;
}


