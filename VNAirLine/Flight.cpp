#include "Flight.h"

/*Static Properties*/
int Flight::nextFlightDay = 0;
vector<Flight> Flight::flightList = {};

/*Constructors*/
Flight::Flight()
{
    this->flightSchedule = "";
    this->flightNumber = "";
    this->numOfSeatsInTheFlight = 0;
    toWhichCity = "";
    fromWhichCity = "";
    this->gate = "";
}
Flight::Flight(string flightSchedule, string flightNumber, int numOfSeatsInTheFlight, string** chosenDestinations, string distanceBetweenTheCities, string gate)
{
    this->flightSchedule = flightSchedule;
    this->flightNumber = flightNumber;
    this->numOfSeatsInTheFlight = numOfSeatsInTheFlight;
    this->fromWhichCity = chosenDestinations[0][0];
    this->toWhichCity = chosenDestinations[1][0];
    this->distanceInMiles = stod(distanceBetweenTheCities);
    this->flightTime = calculateFlightTime(distanceInMiles);
    this->gate = gate;
}

/*Overloading Operator*/
bool Flight::operator==(const Flight& flight)
{
    if (flightNumber == flight.flightNumber) return true;
    return false;
}

/*Getters & Setters*/
string Flight::getFlightSchedule()
{
    return flightSchedule;
}
string Flight::getFlightNumber()
{
    return flightNumber;
}
string Flight::getFromWhichCity()
{
    return fromWhichCity;
}
string Flight::getToWhichCity()
{
    return toWhichCity;
}
string Flight::getGate()
{
    return gate;
}
string Flight::getFlightTime()
{
    return flightTime;
}
int Flight::getNumOfSeats()
{
    return numOfSeatsInTheFlight;
}
vector<Flight> Flight::getFlightList()
{
    return flightList;
}
void Flight::setNumOfSeats(int numOfSeats)
{
    this->numOfSeatsInTheFlight = numOfSeats;
}

/*Methods*/
void Flight::flightScheduler()
{
    int numOfFlights = 15;
    RandomGenerator random;
    for (int i = 0; i < numOfFlights; i++)
    {
        string** chosenDestinations = random.randomDestinations();
        string distanceBetweenTheCities = calculateDistance(stod(chosenDestinations[0][1]), stod(chosenDestinations[0][2]), stod(chosenDestinations[1][1]), stod(chosenDestinations[1][2]));
        string flightSchedule = createNewFlightsAndTime();
        string flightNumber = random.randomFlightNumGen(3, 1);
        int numOfSeatsInTheFlight = random.randomOfNumSeat();
        string gate = random.randomGateGen();
        flightList.push_back(Flight(flightSchedule, flightNumber, numOfSeatsInTheFlight, chosenDestinations, distanceBetweenTheCities, gate));
    }
}
string Flight::calculateFlightTime(double distanceBetweenTheCities)
{
    double groundSpeed = 450;
    double time = (distanceBetweenTheCities / groundSpeed);
    stringstream sstream;
    sstream.setf(ios::fixed);
    sstream.precision(2);
    sstream << time;
    string timeInString = sstream.str();
    string hourString;
    string minuteString;
    for (int i = 0; i < timeInString.length(); i++)
    {
        if (timeInString[i] == '.')
        {
            timeInString[i] = ':';
            hourString = timeInString.substr(0, i + 1);
            minuteString = timeInString.substr(i + 1);
            break;
        }
    }
    const char* temp = hourString.c_str();
    int hour = atoi(temp);
    temp = minuteString.c_str();
    int minute = atoi(temp);
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
    else if (hour > 9 and minute <= 9) return to_string(hour) + ":" + "0" + to_string(minute);
    else return to_string(hour) + ":" + to_string(minute);
}
void Flight::deleteFlight(string flightNumber)
{
    bool isFound = false;
    for (int i = 0; i < flightList.size(); i++)
    {
        if (flightNumber == flightList[i].flightNumber)
        {
            isFound = true;
            flightList.erase(remove(flightList.begin(), flightList.end(), flightList[i]), flightList.end());
            break;
        }
    }
    if (!isFound) cout << "Flight with given Number not found...";
    displayFlightSchedule();
}
string Flight::calculateDistance(double lat1, double lon1, double lat2, double lon2)
{
    double theta = lon1 - lon2;
    double distance = sin(degreeToRadian(lat1)) * sin(degreeToRadian(lat2)) + cos(degreeToRadian(lat1)) * cos(degreeToRadian(lat2)) * cos(degreeToRadian(theta));
    distance = acos(distance);
    distance = radianToDegree(distance);
    distance = distance * 60 * 1.1515;
    distance = distance * 1.609344;
    stringstream sstream;
    sstream.setf(ios::fixed);
    sstream.precision(3);
    sstream << distance;
    string distanceInString = sstream.str();
    return distanceInString;
}
double Flight::degreeToRadian(double deg)
{
    return (deg * M_PI / 180.0);
}
double Flight::radianToDegree(double rad)
{
    return (rad * 180.0 / M_PI);
}
void Flight::randomTime(tm*& t)
{
    RandomGenerator random;
    t->tm_mon = random.getRandom(0, 11);
    t->tm_mday = random.getRandom(1, 31);
    t->tm_hour = random.getRandom(0, 23);
    t->tm_min = random.getRandom(0, 59);
    t->tm_sec = random.getRandom(0, 59);
    t->tm_year = 2023 - 1900;
    mktime(t);
}
string Flight::createNewFlightsAndTime()
{
    time_t now = time(NULL);
    tm* t = localtime(&now);
    char* ch;
    string dateInString;
    randomTime(t);
    ch = asctime(t);
    dateInString = ch;
    for (int i = 0; i < dateInString.length(); i++)
    {
        if (dateInString[i] == '\n') dateInString[i] = ' ';
    }
    return dateInString;
}
void Flight::displayFlightSchedule()
{
    cout << endl;
    printf("%5s+--------------------------------------------------------------------------------------------------------------------------------------------------+\n", " ");
    printf("%5s| Num | Flight Schedule \t\t| Flight No | Available Seats | From\t\t\t| To\t\t\t| Time  | Gate | Distance        |\n", " ");
    printf("%5s+--------------------------------------------------------------------------------------------------------------------------------------------------+\n", " ");
    for (int i = 0; i < flightList.size();i++)
    {
        printf("%5s", " ");
        cout << flightList[i].toString(i) << endl;
        printf("%5s+--------------------------------------------------------------------------------------------------------------------------------------------------+\n", " ");
    }
}
string Flight::toString(int i)
{
    string numInString;
    if (i < 10)
    {
        numInString = "0" + to_string(i);
    }
    else numInString = to_string(i);
    string distanceInString = to_string(distanceInMiles);
    stringstream sstream;
    sstream.setf(ios::fixed);
    int count = 0;
    for (int i = 0; i < distanceInString.length(); i++)
    {
        if (distanceInString[i] != '.') count++;
        else break;
    }
    if (count == 2) sstream.precision(3);
    else if (count == 3) sstream.precision(2);
    else if (count == 4) sstream.precision(1);
    sstream << distanceInMiles;
    distanceInString = sstream.str();
    string display;
    display = "| " + numInString + "  | " + flightSchedule + "\t| " + flightNumber + "   | " + to_string(numOfSeatsInTheFlight) + "\t      | " + fromWhichCity + "  \t\t| " + toWhichCity + "  \t\t| " + flightTime + " | " + gate + "  | " + distanceInString + "      Km  |";
    return display;
}
