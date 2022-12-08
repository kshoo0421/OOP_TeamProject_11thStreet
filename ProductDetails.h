#pragma once
#include <ctime>
#include <string>
#include "Product.h"
#include "CategoryManager.h"
#include "DetailsInterface.h"
using namespace std;

class ProductDetails : public DetailsInterface
{
private:
	class CategoryManager category_manager;

	unsigned int main_price;	// �⺻ ����
	std::string product_name;	// ��ǰ��

	MainCategory main_category;	// ���� ī�װ�

	const tm* posted_date;	// ��ǰ �����
	tm* effective_date;	// �Խ� ��ȿ��

	void set_product_name();
	void set_main_price();
	void set_main_category();
	void set_posted_date();
	void extension_effective_time();
	void print_options() const;
	void init_details() override;

public:
	ProductDetails();
	std::string get_product_name() const;
	unsigned int get_main_price() const;
	MainCategory get_category() const;

	// DetailsInterface Interface
	void modify_details() override;
	void display_details() const override;
};