#pragma once
#include <ctime>
#include "Product.h"
#include "DetailsInterface.h"

class ProductDetails : public DetailsInterface
{
private :
	std::string product_name;
	const tm posted_date;	
	tm effective_date;	
	std::string main_category;
	std::string sub_category;
	unsigned int main_price;
	unsigned int get_main_price();
public :
	ProductDetails();
	~ProductDetails();

	// DetailsInterface Interface
	void init_details() override;
	void modify_details() override;
	void display_details() const override;
};