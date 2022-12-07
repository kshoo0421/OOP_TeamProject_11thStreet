#pragma once
#include "Product.h"
#include "DetailsInterface.h"

class DeliveryDetails : public DetailsInterface
{
private :
	unsigned int delivery_fee;
	unsigned int free_delivery_amount;
	unsigned int exchange_delivery_fee;
	unsigned int return_delivery_fee;
	void print_options();

public :
	unsigned int get_delivery_fee() const;

	// DetailsInterface
	void init_details() override;
	void modify_details() override;
	void display_details() const override;
};