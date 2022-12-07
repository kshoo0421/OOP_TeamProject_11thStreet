#include "ProductManager.h"
using namespace std;

void ProductManager::display_products_in_sub_category(std::vector<Product> product_list) const
{
	for (int i = 0; i < product_list.size(); i++)
	{
		cout << i + 1 << ". " << product_list[i].get_product_name() << endl;
	}
	cout << endl;
}

bool ProductManager::is_product_in_list(const Product& product, vector<Product> product_list)
{
	vector<Product>::iterator iterator = product_list.begin();
	for (; iterator < product_list.end(); iterator++)
	{
		if (iterator->get_product_id() == product.get_product_id()) 
			return true;
	}
	return false;
}

void ProductManager::add_product(const Product& product)
{
	switch (product.get_category())
	{
	case MainCategory::FASHION :
		if (is_product_in_list(product, fashion_list))
		{
			std::cout << "이미 존재하는 항목입니다." << std::endl;
			return;
		}
		fashion_list.emplace_back(product);
		std::cout << "항목이 추가되었습니다." << std::endl;
		break;

	case MainCategory::BEAUTY :
		if (is_product_in_list(product, beauty_list))
		{
			std::cout << "이미 존재하는 항목입니다." << std::endl;
			return;
		}
		beauty_list.emplace_back(product);
		std::cout << "항목이 추가되었습니다." << std::endl;
		break;

	case MainCategory::FOOD :
		if (is_product_in_list(product, food_list))
		{
			std::cout << "이미 존재하는 항목입니다." << std::endl;
			return;
		}
		food_list.emplace_back(product);
		std::cout << "항목이 추가되었습니다." << std::endl;
		break;

	case MainCategory::DIGITAL :
		if (is_product_in_list(product, digital_list))
		{
			std::cout << "이미 존재하는 항목입니다." << std::endl;
			return;
		}
		digital_list.emplace_back(product);
		std::cout << "항목이 추가되었습니다." << std::endl;
		break;

	case MainCategory::LIFE :
		if (is_product_in_list(product, life_list))
		{
			std::cout << "이미 존재하는 항목입니다." << std::endl;
			return;
		}
		life_list.emplace_back(product);
		std::cout << "항목이 추가되었습니다." << std::endl;
		break;
	}
}

void ProductManager::delete_product()
{
	int input;
	category_manager.display_categories();
	cout << "삭제할 항목의 카테고리를 선택하세요(숫자) : ";
	cin >> input;
	switch (input)
	{
	case 1:
		cout << "fashion category" << endl;
		display_products_in_sub_category(fashion_list);
		cin >> input;
		input -= 1;
		fashion_list.erase(fashion_list.begin() + input);
		break;
	case 2:
		cout << "beauty category" << endl;
		display_products_in_sub_category(beauty_list);
		cin >> input;
		input -= 1;
		beauty_list.erase(beauty_list.begin() + input);
		break;
	case 3:
		cout << "food category" << endl;
		display_products_in_sub_category(food_list);
		cin >> input;
		input -= 1;
		food_list.erase(food_list.begin() + input);
		break;
	case 4:
		cout << "digital category" << endl;
		display_products_in_sub_category(digital_list);
		cin >> input;
		input -= 1;
		digital_list.erase(digital_list.begin() + input);
		break;
	case 5:
		cout << "life category" << endl;
		display_products_in_sub_category(life_list);
		cin >> input;
		input -= 1;
		life_list.erase(life_list.begin() + input);
		break;
	default:
		cout << "항목 삭제를 취소합니다." << endl;
		return;
	}
	cout << "상품 삭제가 완료되었습니다." << endl;
	
}

void ProductManager::display_products_in_category()
{
	int input;
	category_manager.display_categories();
	std::cout << "상품을 볼 카테고리를 선택하세요(숫자로 입력) : ";
	std::cin >> input;
	switch (input)
	{
	case 1 : 
		cout << "fashion category" << endl;
		display_products_in_sub_category(fashion_list);
		break;
	case 2 :
		cout << "beauty category" << endl;
		display_products_in_sub_category(beauty_list);
		break;
	case 3 :
		cout << "food category" << endl;
		display_products_in_sub_category(food_list);
		break;
	case 4 :
		cout << "digital category" << endl;
		display_products_in_sub_category(digital_list);
		break;
	case 5 :
		cout << "life category" << endl;
		display_products_in_sub_category(life_list);
		break;
	default :
		break;
	}
	std::cout << "상품 보기를 종료합니다." << std::endl;
}

void ProductManager::display_orders_by_seller_id(const unsigned int& seller_id) const
{
	cout << "판매자 상품을 표시합니다." << endl;
	cout << "fashion category" << endl;
	display_products_in_sub_category(fashion_list);

	cout << "beauty category" << endl;
	display_products_in_sub_category(beauty_list);

	cout << "food category" << endl;
	display_products_in_sub_category(food_list);

	cout << "digital category" << endl;
	display_products_in_sub_category(digital_list);

	cout << "life category" << endl;
	display_products_in_sub_category(life_list);

	cout << "항목 출력을 종료합니다." << endl << endl;
}

Product& ProductManager::get_product()
{
	int input;
	category_manager.display_categories();
	std::cout << "상품을 볼 카테고리를 선택하세요(숫자로 입력) : ";
	std::cin >> input;
	switch (input)
	{
	case 1:
		cout << "fashion category" << endl;
		display_products_in_sub_category(fashion_list);
		cout << "항목을 선택하세요(숫자로 입력) : ";
		cin >> input;
		return fashion_list[input - 1];
		break;
	case 2:
		cout << "beauty category" << endl;
		display_products_in_sub_category(beauty_list);
		cout << "항목을 선택하세요(숫자로 입력) : ";
		cin >> input;
		return beauty_list[input - 1];
		break;
	case 3:
		cout << "food category" << endl;
		display_products_in_sub_category(food_list);
		cout << "항목을 선택하세요(숫자로 입력) : ";
		cin >> input;
		return food_list[input - 1];
		break;
	case 4:
		cout << "digital category" << endl;
		display_products_in_sub_category(digital_list);
		cout << "항목을 선택하세요(숫자로 입력) : ";
		cin >> input;
		return digital_list[input - 1];
		break;
	case 5:
		cout << "life category" << endl;
		display_products_in_sub_category(life_list);
		cout << "항목을 선택하세요(숫자로 입력) : ";
		cin >> input;
		return life_list[input - 1];
		break;
	default:
		break;
	}
	std::cout << "상품 보기를 종료합니다." << std::endl;
}

Product& ProductManager::get_product(const unsigned int& product_id)
{
	for (int i = 0; i < fashion_list.size(); i++)
	{
		if (fashion_list[i].get_product_id() == product_id)
			return fashion_list[i];
	}

	for (int i = 0; i < beauty_list.size(); i++)
	{
		if (beauty_list[i].get_product_id() == product_id)
			return beauty_list[i];
	}

	for (int i = 0; i < food_list.size(); i++)
	{
		if (food_list[i].get_product_id() == product_id)
			return food_list[i];
	}

	for (int i = 0; i < digital_list.size(); i++)
	{
		if (digital_list[i].get_product_id() == product_id)
			return digital_list[i];
	}

	for (int i = 0; i < life_list.size(); i++)
	{
		if (life_list[i].get_product_id() == product_id)
			return life_list[i];
	}

	cout << "찾지 못했습니다." << endl;
}