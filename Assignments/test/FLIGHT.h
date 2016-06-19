//********************************************************
// File Name   : Flight.h  
// Author      : Clarence Mitchell
// Assignment  : Number 1
// Date Due    : July 1, 2003 (11:59 PM)
// Description : Header file for flight class
// -----------------------------------------------------------             
// Class       : CISP400 - SUMMER 2003 MW 5:30PM
// Instructor  : Krofchok
// ********************************************************

#ifndef FLIGHT_H
#define FLIGHT_H

class Flight
{
  private:
	//static const int MAX_PASSENGERS = 5;  // Maximum number of passengers per flight
	bool CancelStatus_;
    
	int FlightNumber_;
    int NumberPassengers_;
	std::string PilotsName_;
	bool ValidFlight();

  public:
    // --- Constructors ----
	Flight();
    Flight(int flight_number, std::string pilots_name);
	
	// --- Accessors -----
	int FlightNumber() const { return (FlightNumber_); }
	int NumberPassengers() const { return (NumberPassengers_); }
	std::string PilotsName() const { return (PilotsName_); }
	bool Cancelled() const { return (CancelStatus_); }

	// ---- Mutators -------
	void FlightNumber(int flight_number);							// Assigns a Flight Number
	void PilotsName(std::string pilots_name);							// Assigns Pilot's Name
	void AddPassenger();											// Adds A passenger to a initialized flight
	void RemovePassenger();											// Removes a passenger from a initialized flight
	void CancelFlight();											// Cancels a initialized flight
	
	void const DisplayInfo();

};

#endif

