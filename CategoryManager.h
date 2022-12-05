#pragma once
#include <iostream>
#include <vector>
#include "Product.h"

enum class MainCategory { NONE, FASHION, BEAUTY, FOOD, DIGITAL, LIFE };
// 아래는 enum들은 참고용. 실제로 사용되지는 않음.
enum class FashionCategory { CLOTHES, SHOES, BAG };
enum class BeautyCategory { SKIN_CARE, MAKE_UP, HAIR_CARE, PERFUME };
enum class FoodCategory { FRUIT, VEGETABLE, LIVESTOCK, FISH, SNACK };
enum class DigitalCategory { TV, REFRIGERATOR, WASHING_MACHINE, COMPUTER, SMARTPHONE };
enum class LifeCategory { BATHROOM, KITCHEN, CLEANING, WASHING };

static class CategoryManager
{
private:
	std::vector<Product> fashion_list;
	std::vector<Product> beauty_list;
	std::vector<Product> food_list;
	std::vector<Product> digital_list;
	std::vector<Product> life;


	void display_main_category() const;
	void display_fashion_category() const;
	void display_beauty_category() const;
	void display_food_category() const;
	void display_digital_category() const;
	void display_life_category() const;

	std::string return_fashion_category(const int& option_number) const;
	std::string return_beauty_category(const int& option_number) const;
	std::string return_food_category(const int& option_number) const;
	std::string return_digital_category(const int& option_number) const;
	std::string return_life_category(const int& option_number) const;

public :
	void display_categories() const;
	MainCategory choose_main_category() const;
	std::string choose_sub_category(const MainCategory& main_category) const;
	std::string main_category_to_string(const MainCategory& main_category) const;
};