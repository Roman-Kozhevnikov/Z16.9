// This is an independent project of an individual developer. Dear PVS-Studio, please check it.

// PVS-Studio Static Code Analyzer for C, C++ and C#: http://www.viva64.com

#include "User.h"

User::User() = default;

User::User(const std::string& name, const std::string& login, const std::string& password): 
	        _name (name), _login(login), _password(password) {}

std::ostream& operator<< (std::ostream& os, const User& us)
{
	os << us._name;
	return os;
}