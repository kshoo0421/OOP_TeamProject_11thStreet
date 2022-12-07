#pragma once
#include <iostream>
#include <string>
#include "Product.h";

class OrderItem
{
private :
	Product product;
	unsigned int quantity;
	unsigned int price;
public :
	OrderItem(const Product& input);
	void set_quantity();
	void set_product(const Product& input);
	void set_price();
	unsigned int get_price() const;
	unsigned int get_quantity() const;
	void display_order_item() const;
	std::string get_product_name() const;
};