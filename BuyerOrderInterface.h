#pragma once
#include "OrderItem.h"
#include "Address.h"

class BuyerOrderInterface
{
public :
	virtual void add_order_item(const OrderItem& new_item) = 0;
	virtual void display_order_details() const = 0;
	virtual void display_order() const = 0;
	virtual void set_buyer_address(const Address& buyer_address) = 0;
	virtual void set_delivery_price() = 0;
	virtual void set_total_price() = 0;
	virtual void set_total_product_price() = 0;
};