#include "CategoryManager.h"
using namespace std;

void CategoryManager::display_categories() const
{
	cout << "카테고리" << endl;
	cout << "1. fashion" << endl;
	cout << "2. beauty" << endl;
	cout << "3. food" << endl;
	cout << "4. digital" << endl;
	cout << "5. life" << endl << endl;
	return;
}

enum class MainCategory CategoryManager::choose_main_category() const
{
	int input;
	display_categories();
	cout << "카테고리를 선택하세요.(숫자 선택) : ";
	cin >> input;
	switch (input)
	{
	case 1:
		cout << "fashion이 선택되었습니다.\n";
		return MainCategory::FASHION;
	case 2:
		cout << "beauty가 선택되었습니다.\n";
		return MainCategory::BEAUTY;
	case 3:
		cout << "food가 선택되었습니다.\n";
		return MainCategory::FOOD;
	case 4:
		cout << "digital이 선택되었습니다.\n";
		return MainCategory::DIGITAL;
	case 5:
		cout << "life가 선택되었습니다.\n";
		return MainCategory::LIFE;
	default:
		cout << "아무것도 선택되지 않았습니다.\n";
		return MainCategory::NONE;
	}
}

string CategoryManager::main_category_to_string(const enum class MainCategory& main_category) const
{
	switch (main_category)
	{
	case MainCategory::FASHION:
		return "fashion";
	case MainCategory::BEAUTY:
		return "beauty";
	case MainCategory::FOOD:
		return "food";
	case MainCategory::DIGITAL:
		return "digital";
	case MainCategory::LIFE:
		return "life";
	default: return "None";
	}
}