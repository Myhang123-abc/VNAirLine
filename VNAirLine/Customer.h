#pragma once
#ifndef Customer_Header
#define Customer_Header
#include "Header.h"
#include "RandomGenerator.h"
#include "Flight.h"
class Customer
{
private:
	/*Properties*/
	string userID;
	string name;
	string email;
	string password;
	string phone;
	string address;
	int age;

	/*Methods*/
	string toString(int i);
public:
	/*Properties*/
	vector<int> numOfTicketsBookedByUser;
	static vector<Customer> customerCollection;
	vector<Flight> flightsRegisteredByUser;

	/*Constructors*/
	Customer();
	Customer(string name, string email, string password, string phone, string address, int age);

	/*Overloading Operator*/
	bool operator==(const Customer& customer);

	/*Getters & Setters*/
	string getUserID();
	string getName();
	string getEmail();
	string getPassword();
	string getPhone();
	string getAddress();
	int getAge();
	vector<int> getNumOfTicketsBookedByUser();
	vector<Flight> getFlightsRegisteredByUser();
	void setName(string name);
	void setEmail(string email);
	void setPassword(string password);
	void setPhone(string phone);
	void setAddress(string address);
	void setAge(int age);

	/*Methods*/
	void addNewCustomer();
	bool isUniqueData(string email);
	void searchUser(string id);
	void editUserInfo(string id);
	void deleteUser(string id);
	void displayCustomersData();
	void displayHeader();
	void addNewFlightToCustomerList(Flight f);
	void addExistingFlightToCustomerList(int index, int numOfTickets);
	void displayFlightsBookedByUser(string id);
};
#endif // !Customer_Header

