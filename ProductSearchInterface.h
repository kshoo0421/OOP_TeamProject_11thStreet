#pragma once
#include <string>

class ProductSearchInterface
{
public :
	virtual std::string get_product_id() const = 0;
	virtual std::string get_seller_id() const = 0;
};