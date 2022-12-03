#pragma once
#include "User.h"
#include "Address.h"

class Seller : public User
{
private:
	Address source_address;
	Address return_address;
	std::vector<unsigned int> its_product_index_list;
public:
	std::string get_return_address() const;
	std::string get_source_address() const;
	void modify_return_address();
	void modify_source_address();
};
