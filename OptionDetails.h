#pragma once
#include <string>
#include "DetailsInterface.h"


class OptionDetails : public DetailsInterface
{
private :
	std::string option_value;
	int additional_price;
	unsigned int stock;
public :
	OptionDetails();
	~OptionDetails();
	std::string get_option_value() const;
	int get_additional_price() const;
	bool is_sold_out() const;

	// �������̽� ����
	void init_details() override;
	void modify_details() override;
	void display_details() const override;
};