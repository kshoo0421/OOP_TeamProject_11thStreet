#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
#include "CategoryManager.h"
using namespace std;

class ProductManager
{
private:
	CategoryManager category_manager;
	vector<Product> fashion_list;
	vector<Product> beauty_list;
	vector<Product> food_list;
	vector<Product> digital_list;
	vector<Product> life_list;

public :
	void add_product(const Product& product);
	void delete_product();
	void display_products_in_category();
	void display_orders_by_seller_id(const unsigned int& seller_id) const;
	Product& get_product();
	Product& get_product(const unsigned int& product_id);
};