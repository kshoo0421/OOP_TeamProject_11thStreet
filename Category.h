#pragma once
#include <iostream>
#include <string>
#include <vector>	// DynamicArray ¥Î√º

class Category
{
private :
	std::string main_category;
	std::vector<std::string> sub_category_list;
public :
	Category() ;
	~Category();
	std::string get_main_category() const;
	std::string get_sub_category() const;
	void add_sub_category(const std::string& new_sub_category);
	void delete_sub_category(const std::string& target_sub_category);
};