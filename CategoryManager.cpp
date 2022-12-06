#include "CategoryManager.h"
using namespace std;

enum class MainCategory { NONE, FASHION, BEAUTY, FOOD, DIGITAL, LIFE };

class CategoryManager
{
private:
	std::vector<Product> fashion_list;
	std::vector<Product> beauty_list;
	std::vector<Product> food_list;
	std::vector<Product> digital_list;
	std::vector<Product> life_list;

public:
	void display_categories() const
	{
		cout << "ī�װ�\n";
		cout << "1. fashion\n";
		cout << "2. beauty\n";
		cout << "3. food\n";
		cout << "4. digital\n";
		cout << "5. life\n\n";
		return;
	}

	MainCategory choose_main_category() const
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

	string main_category_to_string(const MainCategory& main_category) const
	{
		switch (main_category)
		{
		case MainCategory::FASHION :
			return "fashion";
		case MainCategory::BEAUTY :
			return "beauty";
		case MainCategory::FOOD :
			return "food";
		case MainCategory::DIGITAL :
			return "digital";
		case MainCategory::LIFE :
			return "life";
		default: return "None";
		}
	}
};