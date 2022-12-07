#pragma once
#include <iostream>

enum class MainCategory 
{
	NONE, 
	FASHION, 
	BEAUTY, 
	FOOD, 
	DIGITAL, 
	LIFE 
};

class CategoryManager
{
public:
	void display_categories() const;
	MainCategory choose_main_category() const;
	std::string main_category_to_string(const enum class MainCategory& main_category) const;
};