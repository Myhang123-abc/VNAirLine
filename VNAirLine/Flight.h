#pragma once
#ifndef Flight_HEADER
#define Flight_HEADER
#include "Header.h";
#include "Customer.h"
#include "FlightDistance.h"
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

    double degreeToRadian(double deg);
    double radianToDegree(double rad);
public:
    // Getters & Setters
    int getNoOfSeats();
    string getFlightNumber();
    void setNoOfSeatsInTheFlight(int numOfSeatsInTheFlight);
    string getFlightTime();
    vector<Flight> getFlightList();
    vector<Customer> getListOfRegisteredCustomersInAFlight();
    string getFlightSchedule();
    string getFromWhichCity();
    string getGate();
    string getToWhichCity();
    // Constructors
    Flight();
    Flight(string flightSchedule, string flightNumber, int numOfSeatsInTheFlight, string** chosenDestinations, string* distanceBetweenTheCities, string gate);
    //Methods
    string tostring(int);
    void flightScheduler();
    string calculateFlightTime(double distanceBetweenTheCities);
    string fetchArrivalTime();
    void displayFlightSchedule();
    string* calculateDistance(double lat1, double lon1, double lat2, double lon2);
    string createNewFlightsAndTime();

    void addNewCustomerToFlight(Customer customer);
    void addTicketsToExistingCustomer(Customer customer, int numOfTickets);
    bool isCustomerAlreadyAdded(vector<Customer> customersList, Customer customer);
    void deleteFlight(string flightNumber);
};
#endif // !Flight_HEADER

