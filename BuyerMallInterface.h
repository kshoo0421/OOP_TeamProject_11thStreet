#pragma once
#include "BuyerInterface.h"
#include "Order.h"
#include "Product.h"

class BuyerMallInterface : BuyerInterface
{
public :
	virtual void display_all_products() = 0;
	virtual void request_order(Order* new_order) = 0;
	virtual void add_new_order() const = 0;
	virtual void display_orders_by_buyer_id(const unsigned int& buyer_id) const = 0;
	virtual Product& get_product(const unsigned int& product_id) = 0;
	virtual Order* get_order(const unsigned int& order_id) = 0;
};