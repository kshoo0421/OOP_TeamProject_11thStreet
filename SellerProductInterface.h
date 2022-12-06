#pragma once

class SellerProductInterface
{
public :
	virtual void display_product_details() const = 0;
	virtual void modify_product() = 0;
};