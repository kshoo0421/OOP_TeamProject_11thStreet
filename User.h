#pragma once
#include <string>
#include <vector>

class User
{
protected :
	unsigned int user_id;
	std::string email;
	std::string password;
	std::string user_name;
	unsigned int balance;
public :
	User();
	~User();
	std::string get_user_name() const;
	unsigned int get_id() const;
	bool compare_email(const std::string& input_email) const;
	bool compare_password(const std::string& input_password) const;
	void display_account_information() const;
	void modify_account_information();
};