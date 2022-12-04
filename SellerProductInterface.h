#pragma once
#include "Product.h"
#include "SellerInterface.h"

class SellerProductInterface : SellerInterface
{
public :
	virtual void display_product_details() const = 0;
	virtual void modify_product() = 0;
};