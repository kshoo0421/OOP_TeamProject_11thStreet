#include "CategoryManager.h"
using namespace std;

void CategoryManager::display_categories() const
{
	cout << "ī�װ�\n";
	cout << "1. fashion\n";
	cout << "2. beauty\n";
	cout << "3. food\n";
	cout << "4. digital\n";
	cout << "5. life\n\n";
	return;
}

enum MainCategory CategoryManager::choose_main_category() const
{
	int input;
	display_categories();
	cout << "ī�װ��� �����ϼ���.(���� ����) : ";
	cin >> input;
	switch (input)
	{
	case 1:
		cout << "fashion�� ���õǾ����ϴ�.\n";
		return MainCategory::FASHION;
	case 2:
		cout << "beauty�� ���õǾ����ϴ�.\n";
		return MainCategory::BEAUTY;
	case 3:
		cout << "food�� ���õǾ����ϴ�.\n";
		return MainCategory::FOOD;
	case 4:
		cout << "digital�� ���õǾ����ϴ�.\n";
		return MainCategory::DIGITAL;
	case 5:
		cout << "life�� ���õǾ����ϴ�.\n";
		return MainCategory::LIFE;
	default:
		cout << "�ƹ��͵� ���õ��� �ʾҽ��ϴ�.\n";
		return MainCategory::NONE;
	}
}

string CategoryManager::main_category_to_string(const enum MainCategory& main_category) const
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