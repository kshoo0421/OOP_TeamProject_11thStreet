#pragma once

class SellerInterface
{
public:
	virtual void poster_product_list() = 0;
	virtual void requested_orders() = 0;
	virtual void my_information() = 0;
};