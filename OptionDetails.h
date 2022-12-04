#pragma once
#include <iostream>
#include <string>
#include "DetailsInterface.h"


class OptionDetails : public DetailsInterface
{
private :
	std::string option_value;
	unsigned int additional_price;
	unsigned int stock;
	void print_options();

public :
	std::string get_option_value() const;
	int get_additional_price() const;
	bool is_sold_out() const;

	// 인터페이스 내용
	void init_details() override;
	void modify_details() override;
	void display_details() const override;
};