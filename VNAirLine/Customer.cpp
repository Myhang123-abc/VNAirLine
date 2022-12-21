#include "Customer.h"
/*Static Properties*/
vector<Customer> Customer::customerCollection = {};

/*Constructors*/
Customer::Customer()
{
	this->userID = "";
	this->email = "";
	this->name = "";
	this->phone = "";
	this->password = "";
	this->address = "";
	this->age = 0;
}
Customer::Customer(string name, string email, string password, string phone, string address, int age)
{
	RandomGenerator random;
	random.randomIDGen();
	this->userID = random.getRandomNumber();
	this->name = name;
	this->email = email;
	this->password = password;
	this->phone = phone;
	this->address = address;
	this->age = age;
}

/*Overloading Operator*/
bool Customer::operator==(const Customer& customer)
{
	if (userID == customer.userID) return true;
	return false;
}

/*Getters & Setters*/
string Customer::getEmail()
{
	return email;
}
string Customer::getPassword()
{
	return password;
}
string Customer::getUserID()
{
	return userID;
}
string Customer::getPhone()
{
	return phone;
}
string Customer::getAddress()
{
	return address;
}
int Customer::getAge()
{
	return age;
}
string Customer::getName()
{
	return name;
}
vector<int> Customer::getNumOfTicketsBookedByUser()
{
	return numOfTicketsBookedByUser;
}
vector<Flight> Customer::getFlightsRegisteredByUser()
{
	return flightsRegisteredByUser;
}
void Customer::setName(string name)
{
	this->name = name;
}
void Customer::setAge(int age)
{
	this->age = age;
}
void Customer::setEmail(string email)
{
	this->email = email;
}
void Customer::setAddress(string address)
{
	this->address = address;
}
void Customer::setPhone(string phone)
{
	this->phone = phone;
}
void Customer::setPassword(string password)
{
	this->password = password;
}

/*Methods*/
void Customer::addNewCustomer()
{
	printf("\nEnter your name: \t");
	string name; cin >> name;
	printf("Enter your email address: \t");
	string email; cin >> email;
	while (isUniqueData(email)) 
	{
		printf("ERROR!!! User with the same email already exists... Use new email or login using the previous credentials....");
		printf("Enter your email address :\t");
		cin >> email;
	}
	printf("Enter your password: \t");
	string password; cin >> password;
	printf("Enter your phone number :\t");
	string phone; cin >> phone;
	printf("Enter your address :\t");
	string address; cin >> address;
	printf("Enter your age :\t");
	int age; cin >> age;
	customerCollection.push_back(Customer(name, email, password, phone, address, age));
}
bool Customer::isUniqueData(string emailID)
{
	bool isUnique = false;
	for (int i = 0; i < customerCollection.size(); i++)
	{
		Customer c = customerCollection[i];
		if (emailID == c.getEmail())
		{
			isUnique = true;
			break;
		}
	}
	return isUnique;
}
void Customer::searchUser(string ID)
{
	bool isFound = false;
	Customer customer;
	for (int i = 0; i < customerCollection.size();i++)
	{
		if (customerCollection[i].getUserID() == ID)
		{
			isFound = true;
			customer = customerCollection[i];
			break;
		}
	}
	if (isFound)
	{
		cout << "Customer found! Here is full record: \n";
		displayHeader();
		printf("%10s", " ");
		cout << customer.toString(1);
		printf("%10s+-----------------------------------------------------------------------------------------------------------+\n", " ");
	}
	else cout << "No customer with the ID " + ID + " found!";
}
void Customer::editUserInfo(string id)
{
	bool isFound = false;
	for (int i = 0; i < customerCollection.size(); i++)
	{
		if (customerCollection[i].getUserID() == id)
		{
			isFound = true;
			string name;
			string temp;
			int tmp;
			cout << "\nEnter the new name of the Passenger:\t";
			cin >> name;
			customerCollection[i].setName(name);
			cout << "Enter the new email address of Passenger " + name + ":\t";
			cin >> temp;
			customerCollection[i].setEmail(temp);
			cout << "Enter the new Phone number of Passenger " + name + ":\t";
			cin >> temp;
			customerCollection[i].setPhone(temp);
			cout << "Enter the new address of Passenger " + name + ":\t";
			cin >> temp;
			customerCollection[i].setAddress(temp);
			cout << "Enter the new age of Passenger " + name + ":\t";
			cin >> tmp;
			customerCollection[i].setAge(tmp);
			break;
		}
	}
	if (!isFound) cout << "No customer with the ID " + id << endl;
	displayCustomersData();
}
void Customer::deleteUser(string id)
{
	bool isFound = false;
	for (int i = 0; i < customerCollection.size(); i++)
	{
		if (id == customerCollection[i].getUserID())
		{
			isFound = true;
			customerCollection.erase(remove(customerCollection.begin(), customerCollection.end(), customerCollection[i]), customerCollection.end());
			break;
		}
	}
	if (!isFound) cout << "No customer with the id " + id + " found!";
	displayCustomersData();
}
void Customer::displayCustomersData()
{
	displayHeader();
	int length = customerCollection.size();
	for (int i = 0; i < length; i++)
	{
		printf("%10s", " ");
		cout << customerCollection[i].toString(i);
		printf("%10s+-----------------------------------------------------------------------------------------------------------+\n", " ");
	}
}
void Customer::displayHeader()
{
	cout << endl;
	printf("%10s+-----------------------------------------------------------------------------------------------------------+\n", " ");
	printf("%10s| Num \t| User Id \t| Name\t\t | Email \t\t| Age \t| Address | Phone             |\n"," ");
	printf("%10s+-----------------------------------------------------------------------------------------------------------+\n", " ");
}
string Customer::toString(int i)
{
	string display;
	display = "| " + to_string(i) + " \t\t| " + getUserID() + " \t| " + getName() + "\t\t | " + getEmail() + " \t\t| " + to_string(getAge()) + " \t| " + getAddress() + "      | " + getPhone() + "        |\n";
	return display;
}
void Customer::addNewFlightToCustomerList(Flight f)
{
	this->flightsRegisteredByUser.push_back(f);
}
void Customer::addExistingFlightToCustomerList(int index, int numOfTickets)
{
	int newNumOfTickets = numOfTicketsBookedByUser.at(index) + numOfTickets;
	this->numOfTicketsBookedByUser.at(index) = newNumOfTickets;
}
void Customer::displayFlightsBookedByUser(string id)
{
	bool isFound = false;
	for (int j = 0; j < customerCollection.size(); j++)
	{
		if (customerCollection[j].getUserID() == id)
		{
			isFound = true;
			cout << endl;
			printf("%5s+--------------------------------------------------------------------------------------------------------------------------------------------------+\n", " ");
			printf("%5s| Num | Flight Schedule \t\t| Flight No | Available Seats | From\t\t\t| To\t\t\t| Time  | Gate | Distance        |\n", " ");
			printf("%5s+--------------------------------------------------------------------------------------------------------------------------------------------------+\n", " ");
			for (int i = 0; i < customerCollection[j].flightsRegisteredByUser.size(); i++)
			{
				printf("%5s", " ");
				cout << customerCollection[j].flightsRegisteredByUser[i].toString(i) << endl;
				printf("%5s+--------------------------------------------------------------------------------------------------------------------------------------------------+\n", " ");
			}
		}
	}
	if (!isFound) cout << "No customer with the id found!\n";
}