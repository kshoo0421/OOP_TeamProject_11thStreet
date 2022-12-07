#pragma once
#include <ctime>
#include "Product.h"
#include "CategoryManager.h"
#include "DetailsInterface.h"
using namespace std;

class ProductDetails : public DetailsInterface
{
private:
	CategoryManager category_manager;

	unsigned int main_price;	// �⺻ ����
	std::string product_name;	// ��ǰ��

	MainCategory main_category;	// ���� ī�װ�

	tm* posted_date;	// ��ǰ �����
	tm* effective_date;	// �Խ� ��ȿ��

	void print_options() const;

public:
	unsigned int get_main_price() const;
	MainCategory get_category() const;
	void end_registeration();	
	void extension_effective_time();

	// DetailsInterface Interface
	void init_details() override;
	void modify_details() override;
	void display_details() const override;
};