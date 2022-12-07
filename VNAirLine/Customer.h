#pragma once
#ifndef Customer_HEADER
#define Customer_HEADER
#include "Header.h"
#include "RandomGenerator.h"
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
	vector<int> numOfTicketBookedByUser;
	static vector<Customer> customerCollection;
	Customer();
	Customer(string name, string email, string password, string phone, string address, int age);
	void addNewCustomer();
	bool isUniqueData(string emailID);
	string getEmail();
	string getPassword();
	string getUserID();
};
#endif // !Class

