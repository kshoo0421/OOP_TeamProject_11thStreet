#pragma once
#include "Product.h"
#include "DetailsInterface.h"

class DeliveryDetails : public DetailsInterface
{
private :
	std::string lead_time;
	unsigned int delivery_fee;
	unsigned int free_delivery_amount;
	unsigned int exchange_delivery_fee;
	unsigned int return_delivery_fee;
	// 개인 추가
	void print_options();
	void input_change(const int& option_num, string& string_temp, unsigned int& ui_temp) const;
	void fix_change(const int& option_num, const string& string_temp, const unsigned int& ui_temp);

public :
	DeliveryDetails();
	~DeliveryDetails();
	std::string get_lead_time() const;
	unsigned int get_delivery_fee() const;
	unsigned int get_free_delivery_amount() const;

	// DetailsInterface
	void init_details() override;
	void modify_details() override;
	void display_details() const override;
};