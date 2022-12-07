#pragma once
#include <iostream>
#include <string>

class OrderItem
{
private :
	std::string product_name;
	unsigned int quantity;
	unsigned int price;
	unsigned int applied_coupon_id;
	unsigned int couponed_price;
public :
	OrderItem();
	~OrderItem();
	void set_quantity();
	void set_product_name(std::string& name); // 새로 추가된 함수
	//void set_couponed_price();
	void set_price(const unsigned int & product_price);
	unsigned int get_price() const;
	unsigned int get_quantity() const;
	//void set_applied_coupon_id();
	//unsigned int get_applied_coupon_id() const;
	//void get_couponed_price() const;
	void display_order_item() const;
};