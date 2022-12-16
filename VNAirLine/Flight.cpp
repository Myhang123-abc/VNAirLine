#include "Flight.h"

int Flight::nextFlightDay = 0;
vector<Flight> Flight::flightList = {};


//Getters & Setters
int Flight::getNoOfSeats() {
    return numOfSeatsInTheFlight;
}
string Flight::getFlightNumber() {
    return flightNumber;
}
void Flight::setNoOfSeatsInTheFlight(int numOfSeatsInTheFlight) {
    this->numOfSeatsInTheFlight = numOfSeatsInTheFlight;
}
string Flight::getFlightTime() {
    return flightTime;
}
vector<Flight> Flight::getFlightList() {
    return flightList;
}
vector<Customer> Flight::getListOfRegisteredCustomersInAFlight() {
    return listOfRegisteredCustomersInAFlight;
}
string Flight::getFlightSchedule() {
    return flightSchedule;
}
string Flight::getFromWhichCity() {
    return fromWhichCity;
}
string Flight::getGate() {
    return gate;
}
string Flight::getToWhichCity() {
    return toWhichCity;
}

//Constructors
Flight::Flight()
{
    this->flightSchedule = nullptr;
    this->flightNumber = nullptr;
    this->numOfSeatsInTheFlight = 0;
    toWhichCity = nullptr;
    fromWhichCity = nullptr;
    this->gate = nullptr;
}
Flight::Flight(string flightSchedule, string flightNumber, int numOfSeatsInTheFlight, string** chosenDestinations, string* distanceBetweenTheCities, string gate)
{
    this->flightSchedule = flightSchedule;
    this->flightNumber = flightNumber;
    this->numOfSeatsInTheFlight = numOfSeatsInTheFlight;
    this->fromWhichCity = chosenDestinations[0][0];
    this->toWhichCity = chosenDestinations[1][0];
    this->distanceInMiles = stod(distanceBetweenTheCities[0]);
    this->distanceInKm = stod(distanceBetweenTheCities[1]);
    this->flightTime = calculateFlightTime(distanceInMiles);
    this->listOfRegisteredCustomersInAFlight = {};
    this->gate = gate;
}

//Method
void Flight::flightScheduler()
{
    int numOfFlights = 15;
    RandomGenerator random;
    string** chosenDestinations;
    string* distanceBetweenTheCities;
    for (int i = 0; i < numOfFlights; i++)
    {
        chosenDestinations = random.randomDestinations();
        distanceBetweenTheCities = calculateDistance(stod(chosenDestinations[0][1]), stod(chosenDestinations[0][2]), stod(chosenDestinations[1][1]), stod(chosenDestinations[1][2]));
        string flightSchedule = createNewFlightsAndTime();
        string flightNumber = random.randomFlightNumGen(2, 1);
        int numOfSeatsInTheFlight = random.randomOfNumSeat();
        string gate = random.randomFlightNumGen(1, 30);
        flightList.push_back(Flight(flightSchedule, flightNumber, numOfSeatsInTheFlight, chosenDestinations, distanceBetweenTheCities, gate));
    }
}

void Flight::addNewCustomerToFlight(Customer customer)
{
    this->listOfRegisteredCustomersInAFlight.push_back(customer);
}

void Flight::addTicketsToExistingCustomer(Customer customer, int numOfTickets)
{
    customer.addExistingFlightToCustomerList(customerIndex, numOfTickets);
}

bool Flight::isCustomerAlreadyAdded(vector<Customer> customersList, Customer customer)
{
    bool isAdded = false;
    for (Customer customer1 : customersList)
    {
        if (customer1.getUserID() == customer.getUserID())
        {
            isAdded = true;
            vector<Customer>::iterator itr = find(customersList.begin(),customersList.end(),customer1);
            customerIndex = distance(customersList.begin(), itr);
            break;
        }
    }
    return isAdded;
}

void Flight::deleteFlight(string flightNumer)
{
    bool isFound = false;
    for (Flight f : flightList)
    {
        if (flightNumber == f.getFlightNumber())
        {
            isFound = true;
            vector<Flight>::iterator itr = remove(flightList.begin(), flightList.end(), f);
            break;
        }
    }
    if (!isFound) cout << "Flight with given number not found!";
}

string Flight::calculateFlightTime(double distanceBetweenTheCities)
{
    double groundSpeed = 450;
    double time = (distanceBetweenTheCities / groundSpeed);
    stringstream sstream;
    sstream.setf(ios::fixed);
    sstream.precision(2);
    sstream << time;
    string timeInString = to_string(time);
    string hourString;
    string minuteString;
    for (int i = 0; i < timeInString.length(); i++)
    {
        if (timeInString[i] == '.')
        {
            timeInString.replace(i, 1, ":");
            hourString = timeInString.substr(0, i - 1);
            minuteString = timeInString.substr(i);
        }
    }
    int hour = stoi(hourString);
    int minute = stoi(minuteString);
    int modulus = minute % 5;
    if (modulus < 3) minute -= modulus;
    else minute += 5 - modulus;
    if (minute >= 60)
    {
        minute -= 60;
        hour++;
    }
    if (hour <= 9 and minute <= 9) return "0" + to_string(hour) + ":" + "0" + to_string(minute);
    else if (hour <= 9 and minute > 9) return "0" + to_string(hour) + ":" + to_string(minute);
    else if (hour >9 and minute <=9) return to_string(hour) + ":" + "0" + to_string(minute);
    else return to_string(hour) + ":" + to_string(minute);

}
