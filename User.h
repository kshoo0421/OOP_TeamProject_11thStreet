#pragma once
#include <string>
#include <vector>

class User
{
protected :
	unsigned int user_id;
	std::string emails;
	std::string password;
	std::string user_name;
	std::vector<unsigned int> its_order_index; // IndexList* ¥Î√º
	unsigned int balance;
public :
	User();
	~User();
	std::string get_user_name() const;
	bool compare_email(const std::string& input_email) const;
	bool compare_password(const std::string& input_password) const;
	void modify_user_name();
	void modify_password();
};