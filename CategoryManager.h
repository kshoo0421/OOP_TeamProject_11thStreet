#pragma once
#include <iostream>
#include <vector>
#include "Product.h"
enum MainCategory { NONE, FASHION, BEAUTY, FOOD, DIGITAL, LIFE };

static class CategoryManager
{
public:
	void display_categories() const;
	enum MainCategory choose_main_category() const;
	std::string main_category_to_string(const enum MainCategory& main_category) const;
};