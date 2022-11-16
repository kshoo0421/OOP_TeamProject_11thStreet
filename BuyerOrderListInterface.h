#pragma once

class BuyerOrderListInterface
{
public:
	virtual void display_buyer_order_list(const unsigned int& buyer_id)= 0;
	virtual void display_item_details(const unsigned int& order_id) = 0;
	virtual void request_order_refund(const unsigned int& order_id) = 0;
	virtual void request_refund(const unsigned int& order_id,
		const unsigned int& item_index)= 0;
};