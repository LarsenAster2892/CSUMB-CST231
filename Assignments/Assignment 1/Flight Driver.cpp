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

//---- Using statements ---
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::getline;
//using std::get;

// ------ Functions -------
void WelcomeMessage(void);
void DisplayMenu(void);
void DisplayFlightHeader(void);
void DisplayFlights(Flight pFlights[],int numFlights);
int GetFlight(Flight pFlights[],int numFlights);

//void DisplayFlights();
// ------  Main (Driver) ------
int main(void)
{


  
  //Flight AirAlaska;
  //Flight AirParis(1100,"Emile ErHardt");
 
  WelcomeMessage();  
  

  cout << "How many flight are you working with Today?" << endl;
  //cout << "Number of Flights: ";
  int NumberFlights;
  

  while ((cout << "Number of Flights: ") && (!(cin >> NumberFlights) || (NumberFlights < 1))){
	  cout << endl;
	  cout << "Invalid entry.  Please try again" << endl;
	  cout << endl;
		}
  
  
  Flight *pFlights = new Flight[NumberFlights];
  int fnumber;
  string pname;

  for(int Loop = 0; Loop < NumberFlights; Loop++){
	  
	  cout << "Flight #" << Loop + 1 << endl;

	  cout << "  Please enter the Flight Number:";
	  cin  >>  fnumber;
	  
	  cin.get();

	  cout << "  Please enter Pilot's Name:";
	  getline(cin,pname);
	  
	  pFlights[Loop] = Flight(fnumber,pname);	
	}

  cout << endl;
  DisplayMenu();

  int selection = 0;

  while (selection != 9) {
	    
	    bool valid_option = false;
		int cFlight = 0;

		while (!(valid_option)){

			cout << "Enter option:";
			cin >> selection;

			
			switch(selection){
				case 1: 
					DisplayFlightHeader();
					DisplayFlights(pFlights, NumberFlights);  
					cFlight = GetFlight(pFlights, NumberFlights);
					pFlights[cFlight].AddPassenger();
					break;
						
				case 2:
					DisplayFlightHeader();
					DisplayFlights(pFlights, NumberFlights);  
					cFlight = GetFlight(pFlights, NumberFlights);
					pFlights[cFlight].RemovePassenger();
					break;


				case 3:
					DisplayFlightHeader();
					DisplayFlights(pFlights, NumberFlights);  
					cFlight = GetFlight(pFlights, NumberFlights);
					pFlights[cFlight].CancelFlight();
					break;

				case 4:
					DisplayFlightHeader();
					DisplayFlights(pFlights, NumberFlights);  
					break;

				case 9:
					   valid_option = true;
						break;
				default:
						cout << endl;
						cout << "Invalid Option. Please re enter" << endl;
						cout << endl;

						DisplayMenu();
						break;
			}
			DisplayMenu();

		}

		
  }

 
  //AirAlaska.DisplayInfo();	
  //AirParis.DisplayInfo();
 


  delete [] pFlights;

  return 0;
}

void WelcomeMessage(void)
{
	cout << endl;
	cout << endl;
	cout << "            ====== Welcome to Yeager X-1A Airlines ======== ";
	cout << endl;
	cout << endl;

}


void DisplayMenu(void)
{
	cout << endl;
	cout << "Select Option:" << endl;
	cout << "==============================" << endl;
	cout << " 1. Add Passenger. " << endl;
	cout << " 2. Remove Passgenger. " << endl;
	cout << " 3. Cancel Flight. " << endl;
	cout << " 4. Display Flight Data. " << endl;
	cout << " 9. Exit. " << endl;
	cout << endl;
}


void DisplayFlights(Flight pFlights[], int numFlights){
	
	for(int Loop = 0; Loop < numFlights; Loop++){
		pFlights[Loop].DisplayInfo();
	}

}


void DisplayFlightHeader(void)
{

  cout << " Flights are as follows:"       << endl;
  cout << endl;

  cout 
	  << std::right  <<  std::setfill(' ') <<  std::setw(06)
 	 << "Flight" << ' '
	 <<  std::left   <<  std::setfill(' ') <<  std::setw(19)
	 << " " << ' '
	 <<  std::right  <<  std::setw(10)
	 << "Number" 
	 <<  std::setw(25)
	 << " "
	 << endl;

  cout 
     <<  std::right  <<  std::setfill(' ') <<  std::setw(06)
 	 << "Number" << "  "
	 <<  std::left   <<  std::setfill(' ') <<  std::setw(20)
	 << "Pilot's Name" << ' '
	 <<  std::right  <<  std::setw(10)
	 << "Passengers" 
	 <<  std::setw(22)
	 << "Cancellation Status"
	 << endl;

  cout 
     <<  std::right <<  std::setfill('_') <<  std::setw(07)
	 << " " 
	 <<  std::setw(21)
	 << " " <<  std::setfill(' ') << " " <<  std::setfill('_')
	 <<  std::right
	 <<   std::setw(11)
	 << " " 
	 <<  std::setw(22)
	 << " "
	 << endl
	 <<  std::setfill(' ');



}

int GetFlight(Flight pFlights[], int numFlights)
{
	int check_flight;
	int Loop;
	bool flight_found = false;


	while (!(flight_found)){

		cout << endl;
		cout << "Enter Flight Number to process:" << endl;
		cin  >> check_flight;
		
		for(Loop = 0; (!(flight_found) && (Loop < numFlights)); Loop++){

			if (check_flight == pFlights[Loop].FlightNumber()) {
				flight_found = true;
			}

		}

		if (!(flight_found)) {
			cout << " Invalid Flight Number. Re-enter." << endl;
			cout << endl;
		}

	}
	return (Loop - 1);
}
