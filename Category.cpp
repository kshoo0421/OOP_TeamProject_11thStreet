#include "Category.h"
using namespace std;

class Category
{
private:
	string main_category;
	vector<string> sub_category_list;
	
	void init_category()
	{

	}

public:
	Category()
	{

	}

	~Category() = default;

	string get_main_category() const
	{
		return main_category;
	}

	string get_sub_category() const
	{
		
	}

	void add_sub_category(const string& new_sub_category)
	{
		vector<string>::iterator iterator = sub_category_list.begin();
		for (; iterator != sub_category_list.end(); iterator++)
		{
			if (*iterator == new_sub_category)
			{
				cout << "이미 존재하는 세부 카테고리입니다." << endl;
				return;
			}
		}
		sub_category_list.emplace_back(new_sub_category);
		return;
	}

	void delete_sub_category(const string& target_sub_category)
	{
		vector<string>::iterator iterator = sub_category_list.begin();
		for (; iterator != sub_category_list.end(); iterator++)
		{
			if (*iterator == target_sub_category)
			{
				sub_category_list.erase(iterator);
				break;
			}
		}
	}
};