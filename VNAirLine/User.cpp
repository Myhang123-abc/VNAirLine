#include "User.h"

vector<Customer> User::customerCollection = {};

vector<Customer> User::getCustomerCollection()
{
	return customerCollection;
}
