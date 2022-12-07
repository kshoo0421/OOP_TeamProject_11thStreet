#include "EleventhStreet.h"

class EleventhStreet : public SellerMallInterface, public BuyerMallInterface
{
private:
	CategoryManager category_manager;
	ProductManager product_manager;

	User cur_user;
	int cur_user_index = 0;
	bool is_logined = false;
	bool is_user_seller = false;
	Seller seller_list[3];
	Buyer buyer_list[3];

	std::vector<Order*> order_list;

	void use_eleventh_street()
	{
		while (is_logined == false)
		{
			log_in();
		}
		if (is_logined)
		{
			if (is_user_seller) use_seller_interface();
			else use_buyer_interface();
		}
	}

	void use_seller_interface()
	{
		int input;
		while (1)
		{
			display_seller_interface();
			cin >> input;
			switch (input)
			{
			case 1: 
				poster_product_list();
				break;
			case 2: 
				my_information();
				break;
			default :
				cout << "�̿��� �����մϴ�." << endl;
				break;
			}
		}
	}

	void display_seller_interface()
	{
		cout << "�̿� ���� ���" << endl;
		cout << "1. ��ǰ ����ϱ�" << endl;
		cout << "2. �Ǹ��� ���� ����" << endl << endl;
		return;
	}

	void use_buyer_interface()
	{
		int input;
		while (1)
		{
			display_buyer_interface();
			cin >> input;
			switch (input)
			{
			case 1:
				go_shopping();
				break;
			case 2:
				look_up_my_order_list();
				break;
			case 3:
				my_information();
				break;
			case 4:
				log_out();
				cout << "�α׾ƿ� �Ǿ����ϴ�." << endl;
				break;
			default:
				break;
			}
		}
		return;
	}

	void display_shopping_options()
	{
		cout << "�����ϱ�" << endl;
		cout << "1. ��ü ��ǰ ����" << endl;
		cout << "2. ��ǰ ��ٱ��� ���" << endl;
		cout << "3. �ֹ��ϱ�" << endl;
		return;
	}

	void display_buyer_interface()
	{
		cout << "�̿� ���� ���" << endl;
		cout << "1. �����ϱ�" << endl;
		cout << "2. ��ٱ��� ����" << endl;
		cout << "3. �� ���� ����" << endl << endl;
		return;
	}

	void log_in()
	{
		int input;
		cout << "�α����� ������ ������ �����ϼ���." << endl;
		cout << "1. ������ ����" << endl;
		cout << "2. �Ǹ��� ����" << endl;
		cin >> input;
		if (input == 1) cur_user = buyer_log_in();
		else if (input == 2) cur_user = seller_log_in();
		else cout << "���õ��� �ʾҽ��ϴ�." << endl;
		cout << "�α����� �����մϴ�." << endl;
	}

	void log_out()
	{
		is_logined = false;
		is_user_seller = false;
		return;
	}

	Seller& seller_log_in()
	{
		int input;
		cout << "�α����� ������ �����ϼ���." << endl;
		cout << "1. �Ǹ��� 1" << endl;
		cout << "2. �Ǹ��� 2" << endl;
		cout << "3. �Ǹ��� 3" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			is_logined = true;
			is_user_seller = true;
			return seller_list[0];
		case 2:
			is_logined = true;
			is_user_seller = true;
			return seller_list[1];
		case 3:
			is_logined = true;
			is_user_seller = true;
			return seller_list[2];
		default: break;
		}
		cout << "�α��ο� �����߽��ϴ�." << endl;
	}

	Buyer& buyer_log_in()
	{
		int input;
		cout << "�α����� ������ �����ϼ���." << endl;
		cout << "1. ������ 1" << endl;
		cout << "2. ������ 2" << endl;
		cout << "3. ������ 3" << endl;
		cin >> input;
		switch (input)
		{
		case 1:
			is_logined = true;
			return buyer_list[0];
		case 2:
			is_logined = true;
			return buyer_list[1];
		case 3:
			is_logined = true;
			return buyer_list[2];
		default: break;
		}
		cout << "�α��ο� �����߽��ϴ�." << endl;
	}

	void set_ids_and_orders()
	{
		for (int i = 0; i < 3; i++)
		{
			seller_list[i].set_id(1001 + i);
			buyer_list[i].set_id(2001 + i);
			order_list.emplace_back(&Order((unsigned int)3001 + i));
		}
	}

public:
	EleventhStreet()
	{
		set_ids_and_orders();
		use_eleventh_street();
	}

	// SellerMallInterface
	void display_categories() const override
	{
		category_manager.display_categories();
		return;
	}


	void add_new_product(const Product& new_product) override
	{
		product_manager.add_product(new_product);
		return;
	}

	void display_orders_by_seller_id(const unsigned int& seller_id) const override
	{
		product_manager.display_orders_by_seller_id(seller_id);
		return;
	}

	Order* get_order(const unsigned int& order_id) const override
	{
		return order_list[order_id];
	}

	Product& get_product(const unsigned int& product_id) override
	{
		return product_manager.get_product(product_id);
	}

	Product register_new_product() const
	{
		Product new_product;
		new_product.set_product_name();
		new_product.modify_product();
		return new_product;
	}

	// SellerMallInterface-SellerInterface
	void poster_product_list() override
	{
		int input;
		while (1)
		{
			cout << "��ǰ ���" << endl;
			cout << "1. �� ��ǰ ����ϱ�" << endl;
			cout << "2. �̹� ��ϵ� ��ǰ Ȯ���ϱ�" << endl;
			cout << "3. ��ϵ� ��ǰ �����ϱ�" << endl;
			cin >> input;
			switch (input)
			{
			case 1 :
				add_new_product(register_new_product());
				break;
			case 2 :
				display_orders_by_seller_id(cur_user.get_id());
				break;
			case 3 :
				product_manager.delete_product();
				break;
			default :
				cout << "��ǰ ����� �����մϴ�." << endl;
				return;
			}
		}
	}

	// BuyerMallInterface
	void display_all_products() override
	{
		product_manager.display_products_in_category();
		return;
	}

	void request_order(Order* new_order) override
	{
		int input = 0;
		while (1)
		{
			cout << "" << endl;
			cout << "1." << endl;
			cout << "2." << endl;
			cin >> input;
			switch (input)
			{
			case 1:
				add_new_order();
			case 2:
				cout << "" << endl;
				return;
			}
		}
		return;
	}

	void add_new_order() override // �Ű����� �߰�
	{
		OrderItem temp_item(product_manager.get_product());
		temp_item.set_quantity();
		temp_item.set_price();
		order_list[cur_user_index]->add_order_item(temp_item);
		cout << "�����Ͻ� ��ǰ :" << temp_item.get_product_name() << endl;
		cout << "��ǰ ���� : " << temp_item.get_price() / temp_item.get_quantity() << endl;
		cout << "��ǰ ���� : " << temp_item.get_quantity() << endl;
		cout << "��ǰ �� ���� :" << temp_item.get_price() << endl << endl;
		return;
	}

	void display_orders_by_buyer_id() const override
	{
		
		cout << "�ֹ� ��ǰ ����" << endl;
		order_list[cur_user_index]->display_order();
		
	}

	Product& get_product(const unsigned int& product_id) override
	{
		return product_manager.get_product(product_id);
	}

	Order* get_order() override
	{
		return order_list[cur_user_index];
	}

	// BuyerMallInterface - BuyerInterface
	void go_shopping() override
	{
		bool is_break = false;
		int input;
		while (1)
		{
			display_shopping_options();
			cin >> input;
			switch (input)
			{
			case 1:
				display_all_products();
				break;
			case 2:
				add_new_order();
				break;
			case 3:
				request_order(order_list[cur_user_index]);
				break;
			default:
				is_break = true;
				break;
			}
			if (is_break) break;
		}
		cout << "�����ϱ⸦ �����մϴ�.." << endl;
		return;
	}

	void look_up_my_order_list() const override
	{
		cout << "�� ��ٱ��� ���" << endl;
		cout << "������ :" << buyer_list[cur_user_index].get_user_name() << endl;
		order_list[cur_user_index]->display_order_details();
		return;
	}

	void my_information() override
	{
		int input;
		while (1)
		{
			cout << "�� ����" << endl;
			cout << "1. �� ���� ����" << endl;
			cout << "2. �� ���� �����ϱ�" << endl;
			cout << "�Է�(����) : ";
			cin >> input;
			switch (input)
			{
			case 1: 
				cur_user.display_account_information();
				break;
			case 2: 
				cur_user.modify_account_information();
				break;
			default :
				cout << "�� ������ �����մϴ�." << endl << endl;
				return;
			}
		}
		return;
	}
};