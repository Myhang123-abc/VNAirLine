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

void Customer::displayHeader()
{
	cout << endl;
	printf("%10s+------------+------------+----------------------------------+---------+-----------------------------+-------------------------------------+-------------------------+\n", "");
	printf("%10s| SerialNum  |   UserID   | Passenger Names                  | Age     | EmailID\t\t       | Home Address\t\t\t     | Phone Number\t       |%n", "","");
	printf("%10s+------------+------------+----------------------------------+---------+-----------------------------+-------------------------------------+-------------------------+\n", "");
	cout << endl;
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
