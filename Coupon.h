#pragma once
#include <iostream>
#include <ctime>

class Coupon
{
private :
	unsigned int coupon_id;
	unsigned int product_id;
	unsigned int discounting;
	time_t expiration_date;
public :
	Coupon();
	~Coupon();
	unsigned int get_coupon_id() const;
	unsigned int get_product_id() const;
	void display_coupon_information() const;
	unsigned int get_discounting() const;
};