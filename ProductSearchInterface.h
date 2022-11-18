#pragma once

class ProductSearchInterface
{
public :
	virtual unsigned int get_product_id() const = 0;
	virtual unsigned int get_seller_id() const = 0;
};