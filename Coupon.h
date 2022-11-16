#pragma once

class Coupon
{
private :
	unsigned int coupon_id;
	unsigned int product_id;
	unsigned int discounting;
	unsigned int expiration_date;	// time 대신 unsigned int로 대체
public :
	Coupon();
	~Coupon();
	unsigned int get_coupon_id() const;
	unsigned int get_product_id() const;
	void apply_coupon() const;
	void display_coupon_information() const;
};