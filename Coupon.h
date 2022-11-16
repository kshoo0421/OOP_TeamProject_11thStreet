#pragma once

class Coupon
{
private :
	unsigned int coupon_id;
	unsigned int product_id;
	unsigned int discounting;
	unsigned int expiration_date;	// time ��� unsigned int�� ��ü
public :
	Coupon();
	~Coupon();
	unsigned int get_coupon_id() const;
	unsigned int get_product_id() const;
	void apply_coupon() const;
	void display_coupon_information() const;
};