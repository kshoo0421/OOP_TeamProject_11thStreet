#pragma once
#include "Product.h"
#include "DetailsInterface.h"

class ProductDetails : public Product, public DetailsInterface
{
private :
	std::string product_name;
	const int posted_date;	// time 대신 int 사용
	int effective_date;	// time 대신 int 사용
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
	void display_details() override;
};