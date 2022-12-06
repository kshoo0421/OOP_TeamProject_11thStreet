#pragma once
#include <iostream>
#include <vector>
#include "Product.h"

enum class MainCategory { NONE, FASHION, BEAUTY, FOOD, DIGITAL, LIFE };

static class CategoryManager
{
public :
	void display_categories() const;
	MainCategory choose_main_category() const;
	std::string main_category_to_string(const MainCategory& main_category) const;
};