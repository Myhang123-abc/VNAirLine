#pragma once
#ifndef Flight_HEADER
#define Flight_HEADER
#include "Header.h"
#include "FlightDistance.h"
class Flight : public FlightDistance
{
private:
	static int nextFlightDay;
	static vector<Flight> flightList;
public:
	
};
#endif // !Flight_HEADER


