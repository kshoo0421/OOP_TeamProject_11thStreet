#pragma once
#include "Order.h"
#include <string>

class BuyerProductInterface
{
public :
	// 공통
	virtual void display_product_details(const unsigned int& product_id) = 0;

	// EleventhStreet 상속
	virtual void display_all_products() = 0;
	virtual void display_option_selection_page() = 0;
	virtual void display_coupon_available() = 0;
	virtual void apply_coupon() = 0;
	virtual void request_order(const Order& new_order) = 0;

	// Product 상속
	virtual unsigned int get_lead_time() const = 0;
	virtual unsigned int get_free_delivery_amount() const = 0;
	virtual unsigned int get_delivery_fee() const = 0;
	virtual std::string option_selection(std::string& order_item_string, 
		const unsigned int& order_item_price) = 0;
	virtual unsigned int get_main_price() = 0;
};