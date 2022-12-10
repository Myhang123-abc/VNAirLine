#pragma once
#ifndef Flight_HEADER
#define Flight_HEADER
#include "Header.h"
#include "FlightDistance.h"
#include "Customer.h"
class Flight : public FlightDistance
{
private:
	string flightSchedule;
    string flightNumber;
    string fromWhichCity;
   	string gate;
  	string toWhichCity;
	double distanceInMiles;
    double distanceInKm;
    string flightTime;
   	int numOfSeatsInTheFlight;
    vector<Customer> listOfRegisteredCustomersInAFlight;
    int customerIndex;
	static int nextFlightDay;
	static vector<Flight> flightList;

    void addNewCustomerToFlight(Customer customer);
    void addTicketsToExistingCustomer(Customer customer, int numOfTickets);
    boolean isCustomerAlreadyAdded(vector<Customer> customersList, Customer customer);
    void deleteFlight(string flightNumber);
    double degreeToRadian(double deg);
    double radianToDegree(double rad);

    int getNoOfSeats() ;
    string getFlightNumber();
    void setNoOfSeatsInTheFlight(int numOfSeatsInTheFlight);
    string getFlightTime();
    vector<Flight> getFlightList();
    vector<Customer> getListOfRegisteredCustomersInAFlight();
    string getFlightSchedule();
    string getFromWhichCity();
    string getGate();
    string getToWhichCity();
public:
	Flight();
    Flight(string flightSchedule, string flightNumber, int numOfSeatsInTheFlight, string chosenDestinations[][], string distanceBetweenTheCities[], string gate);
    void flightScheduler();
    string calculateFlightTime(double distanceBetweenTheCities);
    string fetchArrivalTime();
    void displayFlightSchedule();
};

#endif // !Flight_HEADER


