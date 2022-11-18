#pragma once
#include "User.h"
#include "Address.h"
#include "Coupon.h"

class Buyer : public User
{
private :
	Address addresses[3];
	std::vector<unsigned int> IndexList;
	std::vector<Coupon> its_coupon_list;
public :
	void add_new_address();
	void dilete_address();
	void display_addresses() const;
	void get_address(const unsigned int& order_id) const;
	void add_order_list(const unsigned int& order_id) const;
	void add_coupon(const Coupon& new_coupon) const;
	void delete_coupon(const unsigned int& address_number) const;
};