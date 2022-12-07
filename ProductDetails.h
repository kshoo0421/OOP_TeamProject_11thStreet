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

	unsigned int main_price;	// 기본 가격
	std::string product_name;	// 상품명

	MainCategory main_category;	// 메인 카테고리

	tm* posted_date;	// 상품 등록일
	tm* effective_date;	// 게시 유효일

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