#pragma once
#include <ctime>
#include "Product.h"
#include "DetailsInterface.h"


class ProductDetails : public DetailsInterface
{
private :
	unsigned int main_price;
	std::string product_name;
	std::string main_category;
	std::string sub_category;
	
	tm posted_date;
	tm effective_date;

	// 개인 추가
	void print_options() const;
	void input_change(const int& option_num, string& string_temp, unsigned int& ui_temp) const;
	void fix_change(const int& option_num, const string& string_temp, const unsigned int& ui_temp);
	void set_category();

public :
	ProductDetails();
	~ProductDetails();
	unsigned int get_main_price() const;
	void end_registeration();

	// DetailsInterface Interface
	void init_details() override;
	void modify_details() override;
	void display_details() const override;
};