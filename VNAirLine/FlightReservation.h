#pragma once
#ifndef FlightReservation_Header
#define FlightReservation_Header
#include "Header.h"
#include "Customer.h"
class FlightReservation
{
public:
	/*Properties*/
	Flight flight;
	Customer customer;
	int flightIndexInFlightList;

	/*Method*/
	string toString(int i, Flight flight, Customer customer);
	void bookFlight(string flightNo, int numOfTickets, string userID);
	void cancelFlight(string userID);
	bool isFlightAlreadyAddedToCustomerList(vector<Flight> flightList, Flight flight);
	string flightStatus(Flight flight);
	void displayFlightsRegisteredByOneUser(string userID);
};
#endif // !FlightReservation_Header

