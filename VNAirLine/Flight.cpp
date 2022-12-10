#include "Flight.h"

int Flight::nextFlightDay = 0;
vector<Flight> Flight::flightList = {};

Flight::Flight(){
    this->flightSchedule = "";
    this->flightNumber = "";
    this->numOfSeatsInTheFlight = 0;
    toWhichCity = "";
    fromWhichCity = "";
    this->gate = "";
}
Flight::Flight(string flightSchedule, string flightNumber, int numOfSeatsInTheFlight, string chosenDestinations[][], string distanceBetweenTheCities[], string gate) {
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
void Flight::flightScheduler() {
    int numOfFlights = 15;              // decides how many unique flights to be included/display in scheduler
    RandomGenerator r1;
    for (int i = 0; i < numOfFlights; i++) {
        string chosenDestinations[2][3] = r1.randomDestinations();
        string distanceBetweenTheCities[MAX] = calculateDistance(stod(chosenDestinations[0][1]), stod(chosenDestinations[0][2]), stod(chosenDestinations[1][1]), stod(chosenDestinations[1][2]));
        string flightSchedule = createNewFlightsAndTime();
        string flightNumber = r1.randomFlightNumbGen(2, 1);
        int numOfSeatsInTheFlight = r1.randomNumOfSeats();
        string gate = r1.randomFlightNumbGen(1, 30);
        flightList.push_back(Flight(flightSchedule, flightNumber, numOfSeatsInTheFlight, chosenDestinations, distanceBetweenTheCities, toupper(gate)));
    }
}
void  Flight::addNewCustomerToFlight(Customer customer) {
    this->listOfRegisteredCustomersInAFlight.push_back(customer);
}
void Flight::addTicketsToExistingCustomer(Customer customer, int numOfTickets) {
    customer.addExistingFlightToCustomerList(customerIndex, numOfTickets);
}
bool Flight::isCustomerAlreadyAdded(vector<Customer> customersList, Customer customer) {
    bool isAdded = false;
    for (Customer customer1 : customersList) {
        if (customer1.getUserID()==customer.getUserID()) {
            isAdded = true;
            customerIndex = customersList.indexOf(customer1);
            break;
        }
    }
    return isAdded;
}
double Flight::degreeToRadian(double deg) {
    return (deg * Math.PI / 180.0);
}
double Flight::radianToDegree(double rad) {
    return (rad * 180.0 / Math.PI);
}
void Flight::displayFlightSchedule() {

    Iterator<Flight> flightIterator = flightList.iterator();
    cout<<endl;
    printf("+------+-------------------------------------------+-----------+------------------+-----------------------+------------------------+---------------------------+-------------+--------+------------------------+\n");
    printf("| Num  | FLIGHT SCHEDULE\t\t\t   | FLIGHT NO | Available Seats  | \tFROM ====>>       | \t====>> TO\t   | \t    ARRIVAL TIME       | FLIGHT TIME |  GATE  |   DISTANCE(MILES/KMS)  |%n");
    print("+------+-------------------------------------------+-----------+------------------+-----------------------+------------------------+---------------------------+-------------+--------+------------------------+\n");
    int i = 0;
    while (flightIterator->hasNext()) {
        i++;
        <Flight> f1 = flightIterator->next();
        cout << f1->toString(i) << endl;
        printf("+------+-------------------------------------------+-----------+------------------+-----------------------+------------------------+---------------------------+-------------+--------+------------------------+\n");
    }
}
string Flight::createNewFlightsAndTime()
{
	   std::shared_ptr<Calendar> c = Calendar::getInstance();
	   // Incrementing nextFlightDay, so that next scheduled flight would be in the future, not in the present
	   nextFlightDay += Math::random() * 7;
	   c->add(Calendar::DATE, nextFlightDay);
	   c->add(Calendar::HOUR, nextFlightDay);
	   c->set(Calendar::MINUTE, ((c->get(Calendar::MINUTE) * 3) - static_cast<int>(Math::random() * 45)));
	   Date myDateObj = c->getTime();
	   LocalDateTime date = Instant::ofEpochMilli(myDateObj.getTime()).atZone(ZoneId::systemDefault()).toLocalDateTime();
	   date = getNearestHourQuarter(date);
	   return date.format(DateTimeFormatter::ofPattern(L"EEEE, dd MMMM yyyy, HH:mm a "));
}

LocalDateTime Flight::getNearestHourQuarter(LocalDateTime datetime)
{
	 int minutes = datetime.getMinute();
	 int mod = minutes % 15;
	 LocalDateTime newDatetime;
	 if (mod < 8)
	 {
		 newDatetime = datetime.minusMinutes(mod);
	 }
	 else
	 {
		 newDatetime = datetime.plusMinutes(15 - mod);
	 }
	 newDatetime = newDatetime.truncatedTo(ChronoUnit::MINUTES);
	 return newDatetime;
}

int Flight::getNoOfSeats()
{
	   return numOfSeatsInTheFlight;
}

string Flight::getFlightNumber()
{
	return flightNumber;
}

void Flight::setNoOfSeatsInTheFlight(int numOfSeatsInTheFlight)
{
	this->numOfSeatsInTheFlight = numOfSeatsInTheFlight;
}

string Flight::getFlightTime()
{
	return flightTime;
}

vector<Flight> Flight::getFlightList()
{
	return flightList;
}

vector<Customer> Flight::getListOfRegisteredCustomersInAFlight()
{
	return listOfRegisteredCustomersInAFlight;
}

string Flight::getFlightSchedule()
{
	return flightSchedule;
}

string Flight::getFromWhichCity()
{
	return fromWhichCity;
}
string Flight::getGate()
{
	return gate;
}
string Flight::getToWhichCity()
{
	return toWhichCity;
}
