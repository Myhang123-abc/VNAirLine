#include "Customer.h"
#include "User.h"
User u;
vector<Customer> Customer::customerCollection = u.getCustomerCollection();

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
void Customer::addNewCustomer()
{
	printf("\n\n\n%60s ++++++++++++++ Cong dang ki khach hang moi ++++++++++++++", "");
	printf("\nNhap ten cua ban: \t");
	string name; cin >> name;
	printf("Enter your name address: \t");
	string email; cin>> email;
	while(isUniqueData(email)){
		printf("ERROR!!! User with the same email already exists... Use new email or login using the previous credentials....");
		printf("Enter your email address :\t");
		cin>>email;
	}
	printf("Enter your Password: \t");
	string password; cin>>password;
	printf("Enter your Phone number :\t");
	string phone; cin>>phone;
	printf("Enter your address :\t");
	string address; cin>>address;
	printf("Enter your age :\t");
	int age; cin>>age;
	customerCollection.push_back(Customer(name,email,password,phone,address,age));
}

string Customer::toString(int i)
{
	string display;
	display = i + " | " + userID + " | " + name + " | " + to_string(age) + " | " + email + " | " + address + " | " + phone + " | ";
	return display;
}

void Customer::searchUser(string ID)
{
	bool isFound = false;
	Customer customerWithTheID = customerCollection.at(0);
	for (Customer c : customerCollection)
	{
		if (ID == c.getUserID())
		{
			cout << "Customer found! Here is full record:";
			isFound = true;
			displayHeader();
			customerWithTheID = c;
			break;
		}
	}
	if (isFound)
	{
		cout << toString(1);
	}
	else cout << "No customer with the ID found!";

}

void Customer::displayHeader()
{
	cout << endl;
	printf("%10s+------------+------------+----------------------------------+---------+-----------------------------+-------------------------------------+-------------------------+\n", "");
	printf("%10s| SerialNum  |   UserID   | Passenger Names                  | Age     | EmailID\t\t       | Home Address\t\t\t     | Phone Number\t       |%n", "","");
	printf("%10s+------------+------------+----------------------------------+---------+-----------------------------+-------------------------------------+-------------------------+\n", "");
	cout << endl;
}

void Customer::editUserInfo(string ID)
{
	string idNeeded;
	cin >> idNeeded;
	bool isFound = false;
	for (Customer c : customerCollection)
	{
		if (ID == c.getUserID())
		{
			string name;
			string temp;
			int temp1;
			bool isFound = true;
			cout << "\nEnter the new name of the Passenger:\t";
			cin >> name; 
			c.setName(name);
			cout << "Enter the new email address of Passenger " + name + ":\t";
			cin >> temp;
			c.setEmail(temp);
			cout << "Enter the new Phone number of Passenger " + name + ":\t";
			cin >> temp;
			c.setPhone(temp);
			cout << "Enter the new address of Passenger " + name + ":\t";
			cin >> temp;
			c.setAddress(temp);
			cout << "Enter the new age of Passenger " + name + ":\t";
			cin >> temp1;
			c.setAge(temp1);
			displayCustomersData(false);
			break;
		}
	}
	if (!isFound) cout << "No customer with the ID found!";
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

void Customer::deleteUser(string ID)
{
	bool isFound = false;
	vector<Customer>::iterator index;
	for (Customer c : customerCollection)
	{
		if (ID == c.getUserID())
		{
			isFound = true;
			index = find(customerCollection.begin(), customerCollection.end(), c);
			break;
		}
	}
	if (isFound)
	{
		customerCollection.erase(index);
		cout << "Printing all  Customer's Data after deleting Customer with the ID " + ID + ": \n";
		displayCustomersData(false);
	}
	else cout << "No customer with the ID found!";
}

void Customer::addNewFlightToCustomerList(Flight f)
{
	this->flightsRegisteredByUser.push_back(f);
}

void Customer::displayCustomersData(bool showHeader)
{
	displayHeader();
	int length = customerCollection.size();
	for (int i = 0; i < length; i++)
	{
		cout << customerCollection[i].toString(i);
	}
}

void Customer::addExistingFlightToCustomerList(int index, int numOfTickets)
{
	int newNumOfTickets = numOfTicketBookedByUser.at(index) + numOfTickets;
	this->numOfTicketBookedByUser.at(index) = newNumOfTickets;
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
vector<int> Customer::getNumofTicketsBookedByUser()
{
	return numOfTicketBookedByUser;
}
vector<Flight> Customer::getFlightsRegistereByUser()
{
	return flightsRegisteredByUser;
}
void Customer::setName(string name)
{
	this->name=name;
}
void Customer::setAge(int age)
{
	this->age=age;
}
void Customer::setEmail(string email)
{
	this->email=email;
}
void Customer::setAddress(string address)
{
	this->address=address;
}
void Customer::setPhone(string phone)
{
	this->phone=phone;
}
