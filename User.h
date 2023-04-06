#pragma once
#include <ostream>
#include <string>
#include <set>
class User
{
	std::string _name;
	const std::string _login;
	std::string _password;
	std::set<int> _num_mess; // ��� ����� ������� ����� ���������
public:
	User();
	User(const std::string& name, const std::string& login, const std::string& password);		
	std::string& getName() { return _name; }
	const std::string& getLogin() { return _login; }
	std::string& getPassword() { return _password; }
	friend std::ostream& operator<< (std::ostream&, const User&);
	std::set<int>& get_num_mess() { return _num_mess; }
	
	

};

