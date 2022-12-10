#pragma once
#ifndef DisplayClass_HEADER
#define DisplayClass_HEADER
#include "Header.h"
#include "Flight.h"
#include "Customer.h"
class DisplayClass
{
protected:
	virtual void displayRegisteredUsersForAllFlight() = 0;
	virtual void displayRegisteredUsersForASpecificFlight(string flightNum) = 0;
	virtual void displayHeaderForUsers(Flight flight, vector<Customer> c) = 0;
	virtual void displayFlightsRegisteredByOneUser(string userID) = 0;
	virtual void displayArtWork(int options) = 0;
};
#endif // !DisplayClass_HEADER

