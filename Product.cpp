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
	cout << "��ǰ �̸��� �����ϼ��� : ";
	cin >> product_name;
	cout << "��ǰ �̸��� " << product_name << "���� �����Ǿ����ϴ�.\n";
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

// Buyer- �������̽� ����
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

// Seller- �������̽� ����
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

// ProductSearch- �������̽� ����
unsigned int Product::get_product_id() const 
{
	return product_id;
}

unsigned int Product::get_seller_id() const
{
	return seller_id;
}