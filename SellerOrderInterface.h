#pragma once
#include "SellerInterface.h"

class SellerOrderInterface : SellerInterface
{
public:
	virtual void set_status() = 0;
	virtual void set_actual_arrival_date() = 0;
	virtual void display_order() const = 0;
	virtual void process_order() = 0;
	virtual void process_refund() = 0;
};