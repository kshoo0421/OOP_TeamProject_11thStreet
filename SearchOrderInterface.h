#pragma once

class SearchOrderInterface
{
public :
	virtual unsigned int get_order_id() const = 0;
	virtual unsigned int get_buyer_id() const = 0;
	virtual unsigned int product_id() const = 0;
};