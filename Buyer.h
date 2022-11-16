#pragma once
#include "User.h"
#include "Address.h"

class Buyer : public User
{
private :
	std::vector<unsigned int> its_coupon_index_list;	// IndexList* ´ëÃ¼
	Address addresses[3];
	void display_address() const;
	void get_address() const;
public :
	void display_addresses();
	void add_new_address();
	void delete_address();
};