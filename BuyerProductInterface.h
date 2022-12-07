#pragma once

class BuyerProductInterface
{
public:
	virtual void display_product_details() const = 0;
	virtual unsigned int get_main_price() = 0;
};