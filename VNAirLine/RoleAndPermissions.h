#pragma once
#ifndef RoleAndPermissions_HEADER
#define RoleAndPermissions_HEADER
#include "Header.h"
#include "User.h"
class RoleAndPermissions : public User 
{
public:
	int isPrivilegedUserOrNot(string username, string password);
	string isPassengerRegistered(string email, string password);
};
#endif // !RoleAndPermissions_HEADER

