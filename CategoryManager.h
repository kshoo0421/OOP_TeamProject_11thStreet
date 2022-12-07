#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
#include "MainCategory.h"

static class CategoryManager
{
private:
	std::vector<Product> fashion_list;
	std::vector<Product> beauty_list;
	std::vector<Product> food_list;
	std::vector<Product> digital_list;
	std::vector<Product> life_list;

public:
	void display_categories() const;
	enum MainCategory choose_main_category() const;
	std::string main_category_to_string(const enum MainCategory& main_category) const;
};