#pragma once
#pragma warning(disable : 4996)
#ifndef Flight_Header
#define Flight_Header
#include "Header.h"
#include "RandomGenerator.h"
class Flight
{
private:
    /*Properties*/
    string flightSchedule;
    string flightNumber;
    string fromWhichCity;
    string gate;
    string toWhichCity;
    double distanceInMiles;
    string flightTime;
    static int nextFlightDay;

    /*Method*/
    double degreeToRadian(double deg);
    double radianToDegree(double rad);
    void randomTime(tm*& t);
public:
    int numOfSeatsInTheFlight;
    string toString(int i);

    /*Static variable*/
    static vector<Flight> flightList;

    /*Overloading Operator*/
    bool operator==(const Flight& flight);

    /*Constructors*/
    Flight();
    Flight(string flightSchedule, string flightNumber, int numOfSeatsInTheFlight, string** chosenDestinations, string distanceBetweenTheCities, string gate);

    /*Getters & Setters*/
    string getFlightSchedule();
    string getFlightNumber();
    string getFromWhichCity();
    string getToWhichCity();
    string getGate();
    string getFlightTime();
    int getNumOfSeats();
    vector<Flight> getFlightList();
    void setNumOfSeats(int numOfSeats);

    /*Method*/
    void flightScheduler();
    string calculateFlightTime(double distanceBetweenTheCities);
    void deleteFlight(string flightNumber);
    string createNewFlightsAndTime();
    string calculateDistance(double lat1, double lon1, double lat2, double lon2);
    void displayFlightSchedule();
};
#endif // !Flight_Header
