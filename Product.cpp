#include "Product.h"
using namespace std;

Product::Product()
{
	init_product_set();
}

Product::~Product()
{
	delete description;
}

string Product::get_product_name() const
{
	return product_name;
}

enum class MainCategory Product::get_category() const
{
	return description->get_category();
}

// Buyer- 인터페이스 내용
unsigned int Product::get_main_price() 
{
	return description->get_main_price();
}

void Product::display_product_details() const
{
	description->display_details();
	return;
}

// Seller- 인터페이스 내용
void Product::init_product_set()
{
	description = new ProductDetails();
	product_name = description->get_product_name();
}

void Product::modify_product()
{
	description->modify_details();
	return;
}

// ProductSearch- 인터페이스 내용
unsigned int Product::get_product_id() const
{
	return product_id;
}

unsigned int Product::get_seller_id() const
{
	return seller_id;
}