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