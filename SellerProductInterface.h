#pragma once

class SellerProductInterface
{
public :
	// 공통
	virtual void display_product_details(const unsigned int& product_id)= 0;
	virtual void display_product_details() const = 0;	// 위아래 다름

	// Eleventh Street
	virtual void display_seller_products() = 0;
	virtual void modify_product_details() = 0;
	virtual void delete_product() = 0;
	virtual void add_product() = 0;
	virtual void category_selection() = 0;
	virtual void issue_coupon() = 0;
	virtual void display_coupons() = 0;
	virtual void delete_coupon() = 0;

	// Product
	virtual void modify_product() = 0;
};