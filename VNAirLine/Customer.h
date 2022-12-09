#pragma once
#ifndef Customer_HEADER
#define Customer_HEADER
#include "Header.h"
#include "RandomGenerator.h"
#include "Flight.h"
class Customer
{
private:
	string userID;
	string email;
	string name;
	string phone;
	string password;
	string address;
	int age;
	
public:
	vector<Flight> flightsRegisteredByUser;
	vector<int> numOfTicketBookedByUser;
	static vector<Customer> customerCollection;
	Customer();
	Customer(string name, string email, string password, string phone, string address, int age);
	void addNewCustomer();
	bool isUniqueData(string emailID);
	string getEmail();
	string getPassword();
	string getUserID();
	void displayHeader();
	string getPhone();
	string getAddress();
	int getAge();
	string getName();
	vector<int> getNumofTicketsBookedByUser();
	vector<Flight> getFlightsRegistereByUser();
	void setName(string name);
	void setAge(int age);
	void setEmail(string email);
	void setPhone(string phone);		
	void setAddress(string address);
};
#endif // !Class

