#pragma once
#include <iostream>
#include "User.h"
#include "Address.h"

class Buyer : public User
{
private:
	std::vector<Address> addresses;
	std::vector<unsigned int> its_order_index_list;
public:
	void add_new_address();
	void delete_address();
	void display_addresses() const;
	Address get_full_address(const unsigned int& order_id) const;
	std::string get_address(const unsigned int& order_id) const;
	void add_order_list(const unsigned int& order_id);
};