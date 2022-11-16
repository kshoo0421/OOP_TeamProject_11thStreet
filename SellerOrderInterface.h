#pragma once

class SellerOrderInterface
{
public:
	virtual void set_status() = 0;
	virtual void set_actual_order_date() = 0;
	virtual void display_order() = 0;
};