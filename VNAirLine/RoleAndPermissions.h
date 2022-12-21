#pragma once
#ifndef RoleAndPermission_Header
#define RoleAndPermission_Header
#include "Header.h"
#include "User.h"
class RoleAndPermission : public User
{
public:
	int isPrivilegedUserOrNot(string username, string password);
	string isPassengerRegistered(string email, string password);
};
#endif // !RoleAndPermission_Header

