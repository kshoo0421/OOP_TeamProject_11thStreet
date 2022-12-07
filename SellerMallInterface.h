#pragma once
#include "SellerInterface.h"
#include "Product.h"
#include "Order.h"

class SellerMallInterface : SellerInterface
{
public :
	virtual void display_categories() const = 0;
	virtual void add_new_product(const Product& new_product) = 0;
	virtual Order get_order(const unsigned int& order_id) const = 0;
};