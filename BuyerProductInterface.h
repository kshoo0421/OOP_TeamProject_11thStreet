#pragma once
#include "OrderItem.h"

class BuyerProductInterface
{
public:
	virtual void display_products_details() const = 0;
	virtual std::string get_lead_time() const = 0;
	virtual unsigned int get_free_delivery_amount() const = 0;
	virtual unsigned int get_delivery_fee() const = 0;
	virtual unsigned int get_main_price() = 0;
};