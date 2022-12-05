#pragma once
#include <ctime>
#include "Product.h"
#include "CategoryManager.h"
#include "DetailsInterface.h"


class ProductDetails : public DetailsInterface
{
private :
	std::string product_name;
	unsigned int main_price;
	std::string product_name;
	std::string main_category;
	std::string sub_category;
	
	CategoryManager category_manager;

	tm posted_date;
	tm effective_date;

	// ���� �߰�
	void print_options() const;
	void set_category();

public :
	unsigned int get_main_price() const;
	void end_registeration();

	// DetailsInterface Interface
	void init_details() override;
	void modify_details() override;
	void display_details() const override;
};