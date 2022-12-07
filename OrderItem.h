#pragma once
#include <iostream>
#include <string>
#include "Product.h"

class OrderItem
{
private :
	std::string product_name;
	unsigned int quantity;
	unsigned int total_price;
public :
	OrderItem(const std::string& input);
	void set_product_name(const std::string& input);
	void set_quantity();
	void set_price(const unsigned int& price);
	unsigned int get_price() const;
	unsigned int get_quantity() const;
	void display_order_item() const;
	std::string get_product_name() const;
};