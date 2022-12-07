#pragma once

class BuyerProductInterface
{
public:
	virtual void display_products_details() const = 0;
	virtual unsigned int get_delivery_fee() const = 0;
	virtual unsigned int get_main_price() = 0;
};