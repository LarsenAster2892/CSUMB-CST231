//********************************************************
// File Name   : Test Driver.h  
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : July 1, 2003 (11:59 PM)
// Description : Test Driver for Flight Class
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
//
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "FLIGHT.H"
// ------ Functions -------
void WelcomeMessage(void);
void DisplayFlights();
// ------  Main (Driver) ------
int main(void)
{


  
  Flight AirAlaska;
  Flight AirParis(1100,"Emile ErHardt");
 
  WelcomeMessage;  

  std::cout << " Flights are as follows:"       << std::endl;
  std::cout << std::endl;

  std::cout 
     << std::right  << std::setfill(' ') << std::setw(06)
 	 << "Flight" << ' '
	 << std::left   << std::setfill(' ') << std::setw(19)
	 << " " << ' '
	 << std::right  << std::setw(10)
	 << "Number" 
	 << std::setw(25)
	 << " "
	 << std::endl;

  std::cout 
     << std::right  << std::setfill(' ') << std::setw(06)
 	 << "Number" << "  "
	 << std::left   << std::setfill(' ') << std::setw(20)
	 << "Pilot's Name" << ' '
	 << std::right  << std::setw(10)
	 << "Passengers" 
	 << std::setw(22)
	 << "Cancellation Status"
	 << std::endl;

  std::cout 
     << std::right << std::setfill('_') << std::setw(07)
	 << " " 
	 << std::setw(21)
	 << " " << std::setfill(' ') << " " << std::setfill('_')
	 << std::right
	 <<  std::setw(11)
	 << " " 

	 << std::setw(22)
	 << " "
	 << std::endl
	 << std::setfill(' ');


 
  AirAlaska.DisplayInfo();	
  AirParis.DisplayInfo();
 




  return 0;
}

void WelcomeMessage(void)
{
	std::cout << std::endl;
	std::cout << std::endl;
	std::cout << "            ====== Welcome to Yeager X-1A Airlines ======== ";
	std::cout << std::endl;
	std::cout << std::endl;

}
