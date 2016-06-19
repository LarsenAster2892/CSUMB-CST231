//********************************************************
// File Name   : Flight.ccp 
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : July 1, 2003 (11:59 PM)
// Description : Class non inline members
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************
// ------  Includes ------
#include <iostream>
#include <iomanip>
#include <string>
#include "FLIGHT.H"
//
// ------  Class Methods ------
// Method definitions for the Money class
//
// ------  Constructors  ---
//
static const int MAX_PASSENGERS = 5;
Flight::Flight()
{
  FlightNumber_ = NumberPassengers_ = 0;
  PilotsName_ = "";	
  CancelStatus_ = true;
}

//

Flight::Flight(int flight_number, std::string pilots_name)
{
  PilotsName_ = pilots_name;
  FlightNumber_ = flight_number;
  CancelStatus_ = false;
  NumberPassengers_ = 0;
}

//
// ----- Mutators ------
//


//
// ------  non inline members functions   ---
//

void Flight::AddPassenger()
{

	if (!ValidFlight()){
		std::cerr << " Cannot Add Passengers." << std::endl;
	}
	else if (NumberPassengers_ == MAX_PASSENGERS) {
		std::cerr << "Flight is full.  Cannot Add Passengers." << std::endl;
	}
	else {
		NumberPassengers_ += 1;
	}
 
}


void Flight::RemovePassenger()
{  
	if (!ValidFlight()){
		std::cerr << " Cannot Remove Passengers." << std::endl;
	}
	else if (NumberPassengers_ == 0) {
		std::cerr << "Flight is empty.  Cannot Remove Passengers." << std::endl;
	}
	else {
		NumberPassengers_ -= 1;
	}
  

}

void Flight::CancelFlight()
{  
	if (!ValidFlight()){
		std::cerr << " Cannot Cancel Flight." << std::endl;
	}
	else {
		CancelStatus_ = true; 
		NumberPassengers_ = 0;
	}
  

}

//-----------------------------------------------------
//  Routine to check for valid flight.  
//  Valid flight defined by 
//   1) Flight has been assigned a number.
//   2) Flight has been assigned a pilot. 
//   3) Flight not already Cancelled.
//-----------------------------------------------------
bool Flight::ValidFlight()
{
	bool return_value = false;

	if (FlightNumber_ == 0){
	   std::cerr << "Flight not Assigned Number. " ;
		}
	else if (PilotsName_.length() < 1) {
	   std::cerr << "Flight not Assigned Pilot. " ;
	}
	else if (CancelStatus_) {
	   std::cerr << "Flight Cancelled. ";
	   }
	else {
		return_value = true;
	}
	return return_value;
}

//
// ------  show method ---
//
void Flight::DisplayInfo() const
{
  std::ios_base::fmtflags io_flags = std::cout.flags();
  int io_precision = std::cout.precision();
  char io_fill = std::cout.fill();



	std::cout 
	     << std::right  << std::setfill(' ') << std::setw(05)
		 << FlightNumber_ << "  "
		 << std::left   << std::setfill(' ') << std::setw(20)
		 << PilotsName_ << ' '
		 << std::right  << std::setw(07)
		 << NumberPassengers_ 
	     << std::setw(25)
		 << (CancelStatus_  ? (FlightNumber_ > 0 ? " -- CANCELLED --" : " --NOT INITIALIZED") : "")
		 << std::endl; 



  std::cout.flags(io_flags);
  std::cout.fill(io_fill);
  std::cout.precision(io_precision);
 
}


