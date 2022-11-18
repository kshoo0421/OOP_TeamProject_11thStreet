#pragma once

class BuyerInterface
{
public :
	virtual void go_shopping() = 0;
	virtual void look_up_my_order_list() const = 0;
	virtual void my_information() const = 0;
};