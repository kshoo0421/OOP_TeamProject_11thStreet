#pragma once
#include <iostream>
#include <vector>
#include "Product.h"

class ProductManager
{
private:
	static std::vector<Product> product_list;

public :
	void add_product_list(const Product& product);
	void add_product_list(const Product& product);
	Product get_product_in_list(const int& index) const;
};