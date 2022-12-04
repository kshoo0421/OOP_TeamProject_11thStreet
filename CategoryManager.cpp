#include "CategoryManager.h"
using namespace std;

enum class MainCategory { NONE, FASHION, BEAUTY, FOOD, DIGITAL, LIFE };
// 아래는 enum들은 참고용. 실제로 사용되지는 않음.
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
		cout << "주요 카테고리\n";
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
			cout << "clothes가 선택되었습니다.\n";
			return "clothes";
		case 2:
			cout << "shoes가 선택되었습니다.\n";
			return "shoes";
		case 3: 
			cout << "bag가 선택되었습니다.\n";
			return "bag";
		default: 
			cout << "어떤 것도 선택되지 않았습니다.\n";
			return "none";
		}
	}

	string return_beauty_category(const int& option_number) const
	{
		switch (option_number)
		{
		case 1: 
			cout << "skin_care가 선택되었습니다.\n";
			return "skin_care";
		case 2: 
			cout << "make_up이 선택되었습니다.\n";
			return "make_up";
		case 3: 
			cout << "hair_care가 선택되었습니다.\n";
			return "hair_care";
		case 4: 
			cout << "perfume가 선택되었습니다.\n";
			return "perfume";
		default: 
			cout << "어떤 것도 선택되지 않았습니다.\n";
			return "none";
		}
	}

	string return_food_category(const int& option_number) const
	{
		switch (option_number)
		{
		case 1: 
			cout << "fruit가 선택되었습니다.\n";
			return "fruit";
		case 2: 
			cout << "vegetable이 선택되었습니다.\n";
			return "vegetable";
		case 3: 
			cout << "fish가 선택되었습니다.\n";
			return "fish";
		case 4: 
			cout << "snack이 선택되었습니다.\n";
			return "snack";
		default: 
			cout << "어떤 것도 선택되지 않았습니다.\n";
			return "none";
		}
	}

	string return_digital_category(const int& option_number) const
	{
		switch (option_number)
		{
		case 1: 
			cout << "tv가 선택되었습니다.\n";
			return "tv";
		case 2: 
			cout << "refrigerator가 선택되었습니다.\n";
			return "refrigerator";
		case 3: 
			cout << "washing_machine이 선택되었습니다.\n";
			return "washing_machine";
		case 4: 
			cout << "computer가 선택되었습니다.\n";
			return "computer";
		case 5: 
			cout << "smart_phone가 선택되었습니다.\n";
			return "smart_phone";
		default: 
			cout << "어떤 것도 선택되지 않았습니다.\n";
			return "none";
		}
	}

	string return_life_category(const int& option_number) const
	{
		switch (option_number)
		{
		case 1: 
			cout << "bathroom이 선택되었습니다.\n";
			return "bathroom";
		case 2: 
			cout << "kitchen이 선택되었습니다.\n";
			return "kitchen";
		case 3: 
			cout << "cleaning이 선택되었습니다.\n";
			return "cleaning";
		case 4: 
			cout << "washing이 선택되었습니다.\n";
			return "washing";
		default: 
			cout << "어떤 것도 선택되지 않았습니다.\n";
			return "none";
		}
	}

public:
	void display_categories() const
	{
		int input;
		display_main_category();
		cout << "어떤 카테고리를 선택하시겠습니까?(1~5, 그 외는 선택 종료) : ";
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
		cout << "출력을 종료합니다.\n";
		return;
	}

	MainCategory choose_main_category() const
	{
		int input;
		display_main_category();
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

	string choose_sub_category(const MainCategory& main_category) const
	{
		int input;

		switch (main_category)
		{
		case MainCategory::FASHION :
			display_fashion_category();
			cout << "세부 카테고리를 선택하세요.(숫자 선택) : ";
			cin >> input;
			return return_fashion_category(input);

		case MainCategory::BEAUTY :
			display_beauty_category();
			cout << "세부 카테고리를 선택하세요.(숫자 선택) : ";
			cin >> input;
			return return_beauty_category(input);

		case MainCategory::FOOD :
			display_food_category();
			cout << "세부 카테고리를 선택하세요.(숫자 선택) : ";
			cin >> input;
			return return_food_category(input);

		case MainCategory::DIGITAL :
			display_digital_category();
			cout << "세부 카테고리를 선택하세요.(숫자 선택) : ";
			cin >> input;
			return return_digital_category(input);

		case MainCategory::LIFE:
			display_life_category();
			cout << "세부 카테고리를 선택하세요.(숫자 선택) : ";
			cin >> input;
			return return_life_category(input);
		default : 
			cout << "어떤 것도 선택되지 않았습니다.\n";
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