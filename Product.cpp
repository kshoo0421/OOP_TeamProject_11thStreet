#include "Product.h"
using namespace std;

Product::Product()
{
	delivery_details = new DeliveryDetails();
	description = new ProductDetails();
	category_manager = new CategoryManager();
}

Product::~Product()
{
	delete delivery_details;
	delete description;
	delete category_manager;
}

void Product::set_product_name()
{
	cout << "상품 이름을 결정하세요 : ";
	cin >> product_name;
	cout << "상품 이름이 " << product_name << "으로 결정되었습니다.\n";
	return;
}

string Product::get_product_name() const
{
	return product_name;
}

enum MainCategory Product::get_category() const
{
	return description->get_category();
}

// Buyer- 인터페이스 내용
void Product::display_products_details() const
{
	description->display_details();
	return;
}

unsigned int Product::get_delivery_fee() const 
{
	return delivery_details->get_delivery_fee();
}

unsigned int Product::get_main_price() 
{
	return description->get_main_price();
}

// Seller- 인터페이스 내용
void Product::display_product_details() const 
{
	description->display_details();
	return;
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