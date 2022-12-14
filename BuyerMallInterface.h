#pragma once
#include "BuyerInterface.h"
#include "Order.h"
#include "Product.h"

class BuyerMallInterface : BuyerInterface
{
public :
	virtual void display_all_products() = 0;
	virtual void request_order(Order new_order) = 0;
	virtual void add_new_order() = 0;
	virtual void display_orders_by_buyer_id() const = 0;
	virtual void look_up_my_order_list() const = 0;
	virtual Order get_order() = 0;
};