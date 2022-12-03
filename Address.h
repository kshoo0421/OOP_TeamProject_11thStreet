#pragma once
#include <iostream>
#include <string>

class Address
{
private:
	std::string address_name;
	std::string name;
	std::string address;
	std::string phone_number;
public:
	Address();
	~Address();
	void init_address();
	std::string get_address_name() const;
	std::string get_name() const;
	std::string get_address() const;
	std::string get_phone_number() const;
};