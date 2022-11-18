#pragma once
#include "Product.h"
#include "SellerInterface.h"

class SellerProductInterface : SellerInterface
{
public :
	virtual void display_product_details() const = 0;
	virtual void modify_product() = 0;
	virtual void delete_product(const Product& product) = 0;
	virtual void add_product(const Product& product) = 0;
	virtual void category_selection() = 0;
};