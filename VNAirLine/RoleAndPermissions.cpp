#include "RoleAndPermissions.h"

int RoleAndPermissions::isPrivilegedUserOrNot(string username, string password)
{
	int isFound = -1;
	int length = sizeof(adminUserNameandPassword) / sizeof(adminUserNameandPassword[0]);
	for (int i = 0; i < length; i++) 
	{
		if(username == adminUserNameandPassword[i][0])
			if (password == adminUserNameandPassword[i][1])
			{
				isFound = 1;
				break;
			}
	}
	return isFound;
}

string RoleAndPermissions::isPassengerRegistered(string email, string password)
{
	string isFound = "0";
	Customer temp;
	for (Customer c : temp.customerCollection)
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
