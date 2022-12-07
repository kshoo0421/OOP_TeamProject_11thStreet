#pragma once
#include "SellerInterface.h"

class SellerOrderInterface 
{
public:
	virtual void set_status() = 0;
	virtual void set_actual_arrival_date() = 0;
	virtual void display_order() const = 0;
};