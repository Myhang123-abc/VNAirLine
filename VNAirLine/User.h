#pragma once
#ifndef User_HEADER
#define User_HEADER
#include "Header.h"
#include "Customer.h"
class User
{
private:
	vector<Customer> customerCollection;
public:
	string adminUserNameandPassword[10][2];
	vector<Customer> getCustomerCollection();
};
#endif // !User_HEADER


