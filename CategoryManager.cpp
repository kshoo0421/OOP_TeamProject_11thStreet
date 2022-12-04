#include "CategoryManager.h"
using namespace std;

enum class MainCategory { NONE, FASHION, BEAUTY, FOOD, DIGITAL, LIFE };
// �Ʒ��� enum���� �����. ������ �������� ����.
enum class FashionCategory { CLOTHES, SHOES, BAG };
enum class BeautyCategory { SKIN_CARE, MAKE_UP, HAIR_CARE, PERFUME };
enum class FoodCategory { FRUIT, VEGETABLE, LIVESTOCK, FISH, SNACK };
enum class DigitalCategory { TV, REFRIGERATOR, WASHING_MACHINE, COMPUTER, SMARTPHONE };
enum class LifeCategory { BATHROOM, KITCHEN, CLEANING, WASHING };

class CategoryManager
{
private :
	void display_main_category() const
	{
		cout << "�ֿ� ī�װ�\n";
		cout << "1. fashion\n";
		cout << "2. beauty\n";
		cout << "3. food\n";
		cout << "4. digital\n";
		cout << "5. life\n\n";
		return;
	}

	void display_fashion_category() const
	{
		cout << "fashion category\n";
		cout << "1. clothes\n";
		cout << "2. shoes\n";
		cout << "3. bag\n\n";
		return;
	}

	void display_beauty_category() const
	{
		cout << "beauty category\n";
		cout << "1. skin_care\n";
		cout << "2. make_up\n";
		cout << "3. hair_care\n";
		cout << "4. perfume\n\n";
		return;
	}

	void display_food_category() const
	{
		cout << "food category\n";
		cout << "1. fruit\n";
		cout << "2. vegetable\n";
		cout << "3. livestock\n";
		cout << "4. fish\n";
		cout << "5. snack\n\n";
		return;
	}

	void display_digital_category() const
	{
		cout << "digital category\n";
		cout << "1. tv\n";
		cout << "2. refrigerator\n";
		cout << "3. washing_machine\n";
		cout << "4. computer\n";
		cout << "5. smart_phone\n\n";
		return;
	}

	void display_life_category() const
	{
		cout << "life category\n";
		cout << "1. bathroom\n";
		cout << "2. kitchen\n";
		cout << "3. cleaning\n\n";
		cout << "4. washing\n\n";
		return;
	}

	string return_fashion_category(const int& option_number) const
	{
		switch (option_number)
		{
		case 1: 
			cout << "clothes�� ���õǾ����ϴ�.\n";
			return "clothes";
		case 2:
			cout << "shoes�� ���õǾ����ϴ�.\n";
			return "shoes";
		case 3: 
			cout << "bag�� ���õǾ����ϴ�.\n";
			return "bag";
		default: 
			cout << "� �͵� ���õ��� �ʾҽ��ϴ�.\n";
			return "none";
		}
	}

	string return_beauty_category(const int& option_number) const
	{
		switch (option_number)
		{
		case 1: 
			cout << "skin_care�� ���õǾ����ϴ�.\n";
			return "skin_care";
		case 2: 
			cout << "make_up�� ���õǾ����ϴ�.\n";
			return "make_up";
		case 3: 
			cout << "hair_care�� ���õǾ����ϴ�.\n";
			return "hair_care";
		case 4: 
			cout << "perfume�� ���õǾ����ϴ�.\n";
			return "perfume";
		default: 
			cout << "� �͵� ���õ��� �ʾҽ��ϴ�.\n";
			return "none";
		}
	}

	string return_food_category(const int& option_number) const
	{
		switch (option_number)
		{
		case 1: 
			cout << "fruit�� ���õǾ����ϴ�.\n";
			return "fruit";
		case 2: 
			cout << "vegetable�� ���õǾ����ϴ�.\n";
			return "vegetable";
		case 3: 
			cout << "fish�� ���õǾ����ϴ�.\n";
			return "fish";
		case 4: 
			cout << "snack�� ���õǾ����ϴ�.\n";
			return "snack";
		default: 
			cout << "� �͵� ���õ��� �ʾҽ��ϴ�.\n";
			return "none";
		}
	}

	string return_digital_category(const int& option_number) const
	{
		switch (option_number)
		{
		case 1: 
			cout << "tv�� ���õǾ����ϴ�.\n";
			return "tv";
		case 2: 
			cout << "refrigerator�� ���õǾ����ϴ�.\n";
			return "refrigerator";
		case 3: 
			cout << "washing_machine�� ���õǾ����ϴ�.\n";
			return "washing_machine";
		case 4: 
			cout << "computer�� ���õǾ����ϴ�.\n";
			return "computer";
		case 5: 
			cout << "smart_phone�� ���õǾ����ϴ�.\n";
			return "smart_phone";
		default: 
			cout << "� �͵� ���õ��� �ʾҽ��ϴ�.\n";
			return "none";
		}
	}

	string return_life_category(const int& option_number) const
	{
		switch (option_number)
		{
		case 1: 
			cout << "bathroom�� ���õǾ����ϴ�.\n";
			return "bathroom";
		case 2: 
			cout << "kitchen�� ���õǾ����ϴ�.\n";
			return "kitchen";
		case 3: 
			cout << "cleaning�� ���õǾ����ϴ�.\n";
			return "cleaning";
		case 4: 
			cout << "washing�� ���õǾ����ϴ�.\n";
			return "washing";
		default: 
			cout << "� �͵� ���õ��� �ʾҽ��ϴ�.\n";
			return "none";
		}
	}

public:
	void display_categories() const
	{
		int input;
		display_main_category();
		cout << "� ī�װ��� �����Ͻðڽ��ϱ�?(1~5, �� �ܴ� ���� ����) : ";
		switch (input)
		{
		case 1:
			display_fashion_category();
			break;
		case 2:
			display_beauty_category();
			break;
		case 3:
			display_food_category();
			break;
		case 4:
			display_digital_category();
			break;
		case 5:
			display_life_category();
			break;
		default :
			break;
		}
		cout << "����� �����մϴ�.\n";
		return;
	}

	MainCategory choose_main_category() const
	{
		int input;
		display_main_category();
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

	string choose_sub_category(const MainCategory& main_category) const
	{
		int input;

		switch (main_category)
		{
		case MainCategory::FASHION :
			display_fashion_category();
			cout << "���� ī�װ��� �����ϼ���.(���� ����) : ";
			cin >> input;
			return return_fashion_category(input);

		case MainCategory::BEAUTY :
			display_beauty_category();
			cout << "���� ī�װ��� �����ϼ���.(���� ����) : ";
			cin >> input;
			return return_beauty_category(input);

		case MainCategory::FOOD :
			display_food_category();
			cout << "���� ī�װ��� �����ϼ���.(���� ����) : ";
			cin >> input;
			return return_food_category(input);

		case MainCategory::DIGITAL :
			display_digital_category();
			cout << "���� ī�װ��� �����ϼ���.(���� ����) : ";
			cin >> input;
			return return_digital_category(input);

		case MainCategory::LIFE:
			display_life_category();
			cout << "���� ī�װ��� �����ϼ���.(���� ����) : ";
			cin >> input;
			return return_life_category(input);
		default : 
			cout << "� �͵� ���õ��� �ʾҽ��ϴ�.\n";
			return "none";
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