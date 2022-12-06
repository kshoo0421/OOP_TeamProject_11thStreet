#include "ProductManager.h"

class ProductManager
{
private:
	CategoryManager category_manager;
	vector<Product> fashion_list;
	vector<Product> beauty_list;
	vector<Product> food_list;
	vector<Product> digital_list;
	vector<Product> life_list;

	void display_products_in_sub_category(std::vector<Product> product_list) const
	{
		for (int i = 0; i < product_list.size(); i++)
		{
			cout << i + 1 << ". " << product_list[i].get_product_name() << endl;
		}
		cout << endl;
	}

	bool is_product_in_list(const Product& product, vector<Product> product_list)
	{
		vector<Product>::iterator iterator = product_list.begin();
		for (; iterator < product_list.end(); iterator++)
		{
			if (iterator->get_product_id() == product.get_product_id()) 
				return true;
		}
		return false;
	}

public:
	void add_product(const Product& product)
	{
		switch (product.get_category())
		{
		case MainCategory::FASHION :
			if (is_product_in_list(product, fashion_list))
			{
				std::cout << "�̹� �����ϴ� �׸��Դϴ�." << std::endl;
				return;
			}
			fashion_list.emplace_back(product);
			std::cout << "�׸��� �߰��Ǿ����ϴ�." << std::endl;
			break;

		case MainCategory::BEAUTY :
			if (is_product_in_list(product, beauty_list))
			{
				std::cout << "�̹� �����ϴ� �׸��Դϴ�." << std::endl;
				return;
			}
			beauty_list.emplace_back(product);
			std::cout << "�׸��� �߰��Ǿ����ϴ�." << std::endl;
			break;

		case MainCategory::FOOD :
			if (is_product_in_list(product, food_list))
			{
				std::cout << "�̹� �����ϴ� �׸��Դϴ�." << std::endl;
				return;
			}
			food_list.emplace_back(product);
			std::cout << "�׸��� �߰��Ǿ����ϴ�." << std::endl;
			break;

		case MainCategory::DIGITAL :
			if (is_product_in_list(product, digital_list))
			{
				std::cout << "�̹� �����ϴ� �׸��Դϴ�." << std::endl;
				return;
			}
			digital_list.emplace_back(product);
			std::cout << "�׸��� �߰��Ǿ����ϴ�." << std::endl;
			break;

		case MainCategory::LIFE :
			if (is_product_in_list(product, life_list))
			{
				std::cout << "�̹� �����ϴ� �׸��Դϴ�." << std::endl;
				return;
			}
			life_list.emplace_back(product);
			std::cout << "�׸��� �߰��Ǿ����ϴ�." << std::endl;
			break;
		}
	}

	void delete_product()
	{
		int input;
		category_manager.display_categories();
		cout << "������ �׸��� ī�װ����� �����ϼ���(����) : ";
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
			cout << "�׸� ������ ����մϴ�." << endl;
			return;
		}
		cout << "��ǰ ������ �Ϸ�Ǿ����ϴ�." << endl;
	
	}

	void display_products_in_category()
	{
		int input;
		category_manager.display_categories();
		std::cout << "��ǰ�� �� ī�װ����� �����ϼ���(���ڷ� �Է�) : ";
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
		}
		std::cout << "��ǰ ���⸦ �����մϴ�." << std::endl;
	}

	void display_orders_by_seller_id(const unsigned int& seller_id) const
	{
		cout << "�Ǹ��� ��ǰ�� ǥ���մϴ�." << endl;
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

		cout << "�׸� ����� �����մϴ�." << endl << endl;
	}

	Product& get_product(const unsigned int& product_id)
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

		cout << "ã�� ���߽��ϴ�." << endl;
	}

};