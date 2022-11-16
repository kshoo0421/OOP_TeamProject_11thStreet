#pragma once

class SellerOrderListInterface
{
public :
	virtual void display_seller_order_list(const unsigned int& buyer_id)= 0;
	virtual void process_order() = 0;
	virtual void process_refund() = 0;
};