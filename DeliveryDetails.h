#pragma once
#include "Product.h"
#include "DetailsInterface.h"

class DeliveryDetails : public Product, public DetailsInterface
{
private :
	std::string lead_time;
	unsigned int delivery_fee;
	unsigned int free_delivery_amount;
	unsigned int exchange_delivery_fee;
	unsigned int return_delivery_fee;
public :
	DeliveryDetails();
	~DeliveryDetails();
	unsigned int get_lead_time() const;
	unsigned int get_delivery_fee() const;
	unsigned int get_free_delivery_amount() const;

	// DetailsInterface
	void init_details() override;
	virtual void modify_details() override;
	virtual void display_details() const override;
};