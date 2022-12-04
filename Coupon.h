#pragma once
#include <iostream>
#include <ctime>

class Coupon
{
private :
	unsigned int coupon_id;
	unsigned int product_id;
	unsigned int discounting;
	tm expiration_date;
public :
	Coupon();
	Coupon(const unsigned int& p_id, const unsigned int& discount);
	~Coupon();
	unsigned int get_coupon_id() const;
	unsigned int get_product_id() const;
	void display_coupon_information() const;
	unsigned int get_discounting() const;
};