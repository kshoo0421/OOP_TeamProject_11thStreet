#pragma once
#include <iostream>
#include <vector>
#include "Product.h"

class ProductManager
{
private:
	CategoryManager category_manager;
	std::vector<Product> fashion_list;
	std::vector<Product> beauty_list;
	std::vector<Product> food_list;
	std::vector<Product> digital_list;
	std::vector<Product> life_list;

	void display_products_in_sub_category(std::vector<Product> product_list) const;
	bool is_product_in_list(const Product& product, std::vector<Product> product_list);
public :
	void add_product(const Product& product);
	void delete_product();
	void display_products_in_category();
	void display_orders_by_seller_id(const unsigned int& seller_id) const;
	Product& get_product();
	Product& get_product(const unsigned int& product_id);
};