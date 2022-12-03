#pragma once
#include <iostream>
#include "User.h"
#include "Address.h"
#include "Coupon.h"

class Buyer : public User
{
private:
	vector<Address> addresses;
	std::vector<unsigned int> its_order_index_list;
	std::vector<Coupon> its_coupon_list;
public:
	void add_new_address();
	void delete_address();
	void display_addresses() const;
	std::string get_address(const unsigned int& order_id) const;
	void add_order_list(const unsigned int& order_id);
	void add_coupon(const Coupon& new_coupon);
	void delete_coupon(const unsigned int& coupon_id);
};