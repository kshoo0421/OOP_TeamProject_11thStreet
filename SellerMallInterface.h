#pragma once
#include "SellerInterface.h"
#include "Product.h"
#include "Order.h"

class SellerMallInterface : SellerInterface
{
public :
	virtual void add_coupon() = 0;
	virtual void display_coupons(const unsigned int& product_id) const = 0;
	virtual void delete_coupon(const unsigned int& coupon_id) = 0;
	virtual void display_main_categories() const = 0;
	virtual void display_sub_categories() const = 0;
	virtual void add_new_product(const Product& new_product) const = 0;
	virtual void display_orders_by_seller_id(const unsigned int& seller_id) const = 0;
	virtual Order* get_order(const unsigned int& order_id) const = 0;
	virtual Product* get_product(const unsigned int& product_id) const = 0;
};