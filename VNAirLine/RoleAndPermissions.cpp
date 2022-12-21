#include "RoleAndPermission.h"

int RoleAndPermission::isPrivilegedUserOrNot(string username, string password)
{
	int length = sizeof(adminUserNameAndPassword) / sizeof(adminUserNameAndPassword[0]);
	int isFound = -1;
	for (int i = 0; i < length; i++)
	{
		if (username == adminUserNameAndPassword[i][0])
			if (password == adminUserNameAndPassword[i][1])
			{
				isFound = i;
				break;
			}
	}
	return isFound;
}

string RoleAndPermission::isPassengerRegistered(string email, string password)
{
	string isFound = "0";
	Customer customer;
	for (Customer c : customer.customerCollection)
	{
		if(email == c.getEmail())
			if (password == c.getPassword())
			{
				isFound = "1-" + c.getUserID();
				break;
			}
	}
	return isFound;
}