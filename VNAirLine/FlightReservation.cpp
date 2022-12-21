#include "FlightReservation.h"

void FlightReservation::bookFlight(string flightNo, int numOfTickets, string userID)
{
	bool isFlightFound = false;
	for (int i=0; i<flight.getFlightList().size(); i++)
	{
		if (flightNo == flight.getFlightList()[i].getFlightNumber())
		{
			for (int j = 0; j < customer.customerCollection.size(); j++)
			{
				if (userID == customer.customerCollection[j].getUserID())
				{
					isFlightFound = true;					
					if (!isFlightAlreadyAddedToCustomerList(customer.customerCollection[j].flightsRegisteredByUser, flight.getFlightList()[i]))
					{
						int temp = flight.getFlightList()[i].getNumOfSeats();
						temp -= numOfTickets;
						flight.flightList[i].setNumOfSeats(temp);
						customer.customerCollection[j].addNewFlightToCustomerList(flight.getFlightList()[i]);
						customer.customerCollection[j].numOfTicketsBookedByUser.push_back(numOfTickets);
					}
					else
					{
						int temp = flight.getFlightList()[i].getNumOfSeats();
						temp -= numOfTickets;
						flight.flightList[i].setNumOfSeats(temp);
						int newNumOfTickets = customer.customerCollection[j].numOfTicketsBookedByUser.at(flightIndexInFlightList);
						newNumOfTickets += numOfTickets;
						customer.customerCollection[j].numOfTicketsBookedByUser.at(flightIndexInFlightList) = newNumOfTickets;
					}
					break;
				}
			}
		}
	}
	if (!isFlightFound) cout << "Invalid Flight Number...! No flight with the  ID \"" + flightNo + "\" was found...\n";
}
bool FlightReservation::isFlightAlreadyAddedToCustomerList(vector<Flight> flightList, Flight flight)
{
	bool isAdded = false;
	for (int i = 0; i < flightList.size(); i++)
	{
		if (flightList[i].getFlightNumber() == flight.getFlightNumber())
		{
			this->flightIndexInFlightList = i;
			isAdded = true;
		}
	}
	return isAdded;
}
void FlightReservation::displayFlightsRegisteredByOneUser(string userID)
{
	cout << endl;
	printf("%5s+----------------------------------------------------------------------------------------------------------------------------------------+\n", " ");
	printf("%5s| Num | Flight Schedule \t\t| Flight No | Tickets   | From\t\t\t| To\t\t\t| Time  | Gate | Status       |\n", " ");
	printf("%5s+----------------------------------------------------------------------------------------------------------------------------------------+\n", " ");
	for (int i = 0; i < customer.customerCollection.size(); i++)
	{
		vector<Flight> f = customer.customerCollection[i].getFlightsRegisteredByUser();
		int size = customer.customerCollection[i].getFlightsRegisteredByUser().size();
		if (userID == customer.customerCollection[i].getUserID())
		{
			for (int j = 0; j < size; j++)
			{
				printf("%5s", " ");
				cout << toString(j, f.at(j), customer.customerCollection[i]) << endl;
				printf("%5s+----------------------------------------------------------------------------------------------------------------------------------------+\n", " ");
			}
		}
	}
}
string FlightReservation::toString(int i, Flight flight, Customer customer)
{
	string numInString;
	if (i < 10)
	{
		numInString = "0" + to_string(i);
	}
	else numInString = to_string(i);
	string numOfTickets = to_string(customer.getNumOfTicketsBookedByUser().at(i));
	string display;
	display = "| " + numInString + "  | " + flight.getFlightSchedule() + "\t| " + flight.getFlightNumber() + "   | " + numOfTickets + " \t| " + flight.getFromWhichCity() + "\t\t| "
		+ flight.getToWhichCity() + "\t\t| " + flight.getFlightTime() + " | " + flight.getGate() + "  | " + flightStatus(flight) + "  |";
	return display;
}
string FlightReservation::flightStatus(Flight flight)
{
	bool isAvailable = false;
	for (int i = 0; i < flight.getFlightList().size(); i++)
	{
		if (flight.getFlightList()[i].getFlightNumber() == flight.getFlightNumber())
		{
			isAvailable = true;
			break;
		}
	}
	if (isAvailable) return "As Schedule";
	else return "Cancelled  ";
}
void FlightReservation::cancelFlight(string userID)
{
	string flightNum = "";
	int ticketsToBeReturned;
	bool isFound = false;
	for (int i = 0; i < customer.customerCollection.size(); i++)
	{
		if (userID == customer.customerCollection[i].getUserID())
		{
			if (customer.customerCollection[i].flightsRegisteredByUser.size() != 0)
			{
				printf("%50s %s Here is the list of all the Flights registered by you %s", " ", "++++++++++++++", "++++++++++++++");
				displayFlightsRegisteredByOneUser(userID);
				cout << "Enter the flight number you want to cancel: \t";
				cin >> flightNum;
				cout << "Enter number of tickets to cancel: \t";
				int numOfTickets; cin >> numOfTickets;
				int numOfTicketsForFlight;
				vector<Flight>::iterator it;
				for (int j = 0; j < customer.customerCollection[i].flightsRegisteredByUser.size(); j++)
				{
					if (flightNum == customer.customerCollection[i].flightsRegisteredByUser[j].getFlightNumber())
					{
						isFound = true;
						numOfTicketsForFlight = customer.customerCollection[i].numOfTicketsBookedByUser.at(j);
						while (numOfTickets > numOfTicketsForFlight)
						{
							cout << "Number of Tickets cannot be greater than " << numOfTicketsForFlight << " for this flight!" << endl;
							cout << "Enter number of tickets to cancel: \t";
							cin >> numOfTickets;
						}
						if (numOfTickets == numOfTicketsForFlight)
						{
							ticketsToBeReturned = numOfTicketsForFlight;
							for (int z = 0; z < customer.customerCollection[i].flightsRegisteredByUser.size(); z++)
							{
								if (flightNum == customer.customerCollection[i].flightsRegisteredByUser[z].getFlightNumber())
								{
									customer.customerCollection[i].flightsRegisteredByUser.erase(remove(customer.customerCollection[i].flightsRegisteredByUser.begin(), customer.customerCollection[i].flightsRegisteredByUser.end(), customer.customerCollection[i].flightsRegisteredByUser[z]), customer.customerCollection[i].flightsRegisteredByUser.end());
									break;
								}
							}
							customer.customerCollection[i].numOfTicketsBookedByUser.erase(customer.customerCollection[i].numOfTicketsBookedByUser.begin() + j);
						}
						else
						{
							ticketsToBeReturned = numOfTickets;
							int temp = numOfTicketsForFlight - numOfTickets;
							customer.customerCollection[i].numOfTicketsBookedByUser.at(j) = temp;
						}
						for (int k = 0; k < flight.flightList.size(); k++)
						{
							if (flight.flightList[k].getFlightNumber() == flightNum)
							{
								flight.flightList[k].numOfSeatsInTheFlight += ticketsToBeReturned;
							}
						}
						break;
					}
				}
			} 
			else cout << "No Flight Has been Registered by you with ID \"\"" << flightNum << "\"\".....";
			if (!isFound) cout << "ERROR!!! Couldn't find Flight with ID \"" << flightNum << "\".....";
		}
	}
}