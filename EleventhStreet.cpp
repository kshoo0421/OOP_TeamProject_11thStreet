#include "EleventhStreet.h"

void EleventhStreet::use_eleventh_street()
{
	int input;
	while (is_logined == false)
	{
		log_in();
		if (is_logined == false)
		{
			cout << endl << "�α����� �����Ͻðڽ��ϱ�?(1 : ��, �� �� : �ƴϿ�)" << endl;
			cin >> input;
			if (input == 1) break;
		}
	}
	if (is_logined)
	{
		if (is_user_seller) use_seller_interface();
		else use_buyer_interface();
	}
}

void EleventhStreet::use_seller_interface()
{
	bool is_break = false;
	int input;
	while (1)
	{
		display_seller_interface();
		cin >> input;
		switch (input)
		{
		case 1: 
			register_product();
			break;
		case 2: 
			my_information();
			break;
		case 3:
			log_out();
			is_break = true;
			cout << "�α׾ƿ��մϴ�." << endl;
			break;
		default :
			is_break = true;
			cout << "�̿��� �����մϴ�." << endl;
			break;
		}
		if (is_break) break;
	}
}

void EleventhStreet::display_seller_interface()
{
	cout << endl << "�̿� ���� ���" << endl;
	cout << "1. ��ǰ ����ϱ�" << endl;
	cout << "2. �Ǹ��� ���� ����" << endl;
	cout << "3. �α׾ƿ� �ϱ�" << endl << endl;
	return;
}

void EleventhStreet::use_buyer_interface()
{
	bool is_break = false;
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
			is_break = true;
			cout << "�α׾ƿ� �Ǿ����ϴ�." << endl;
			break;
		default:
			break;
		}
		if (is_break) break;
	}
	return;
}

void EleventhStreet::display_shopping_options()
{
	cout << endl << "�����ϱ�" << endl;
	cout << "1. ��ü ��ǰ ����" << endl;
	cout << "2. ��ǰ ��ٱ��� ���" << endl;
	cout << "3. �ֹ��ϱ�" << endl;
	return;
}

void EleventhStreet::display_buyer_interface()
{
	cout << endl << "�̿� ���� ���" << endl;
	cout << "1. �����ϱ�" << endl;
	cout << "2. ��ٱ��� ����" << endl;
	cout << "3. �� ���� ����" << endl;
	cout << "4. �α׾ƿ�" << endl << endl;
	return;
}

void EleventhStreet::log_in()
{
	int input;
	cout << "�α����� ������ ������ �����ϼ���." << endl;
	cout << "1. ������ ����" << endl;
	cout << "2. �Ǹ��� ����" << endl;
	cin >> input;
	if (input == 1)
	{
		cur_user = buyer_log_in();
		cout << "�α����� �Ϸ�Ǿ����ϴ�." << endl;
	}

	else if (input == 2)
	{
		cur_user = seller_log_in();
		cout << "�α����� �Ϸ�Ǿ����ϴ�." << endl;
	}
	else
	{
		cout << "���õ��� �ʾҽ��ϴ�." << endl;
		cout << "�α����� �����մϴ�." << endl;
	}
	return;
}

void EleventhStreet::log_out()
{
	is_logined = false;
	is_user_seller = false;
	return;
}

Seller& EleventhStreet::seller_log_in()
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
		cout << "�α��ο� �����߽��ϴ�. ���� : �Ǹ���1" << endl << endl;
		return seller_list[0];
	case 2:
		is_logined = true;
		is_user_seller = true;
		cout << "�α��ο� �����߽��ϴ�. ���� : �Ǹ���2" << endl << endl;
		return seller_list[1];
	case 3:
		is_logined = true;
		is_user_seller = true;
		cout << "�α��ο� �����߽��ϴ�. ���� : �Ǹ���3" << endl << endl;
		return seller_list[2];
	default: break;
	}
	cout << "�α��ο� �����߽��ϴ�." << endl;
	return seller_log_in();
}

Buyer& EleventhStreet::buyer_log_in()
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
		cout << "�α��ο� �����߽��ϴ�. ���� : ������1" << endl << endl;
		return buyer_list[0];
	case 2:
		is_logined = true;
		cout << "�α��ο� �����߽��ϴ�. ���� : ������2" << endl << endl;
		return buyer_list[1];
	case 3:
		is_logined = true;
		cout << "�α��ο� �����߽��ϴ�. ���� : ������3" << endl << endl;
		return buyer_list[2];
	default: break;
	}
	cout << "�α��ο� �����߽��ϴ�." << endl;
	return buyer_log_in();
}

void EleventhStreet::set_ids_and_orders()
{
	for (int i = 0; i < 3; i++)
	{
		seller_list[i].set_id(1001 + i);
		buyer_list[i].set_id(2001 + i);
		order_list.emplace_back(Order((unsigned int)3001 + i));
	}
	return;
}

// SellerMallInterface
void EleventhStreet::display_categories() const
{
	category_manager.display_categories();
	return;
}


void EleventhStreet::add_new_product(const Product& new_product)
{
	product_manager.add_product(new_product);
	return;
}

Order EleventhStreet::get_order(const unsigned int& order_id) const
{
	return order_list[order_id];
}

Product EleventhStreet::register_new_product() const
{
	Product new_product(cur_user.get_id());
	return new_product;
}

// SellerMallInterface-SellerInterface
void EleventhStreet::register_product()
{
	int input;
	while (1)
	{
		cout << "��ǰ ���" << endl;
		cout << "1. �� ��ǰ ����ϱ�" << endl;
		cout << "2. �̹� ��ϵ� ��ǰ Ȯ���ϱ�" << endl;
		cout << "3. ��ϵ� ��ǰ �����ϱ�" << endl;
		cout << "�� �� : ��� ����" << endl << endl;
		cin >> input;
		switch (input)
		{
		case 1 :
			add_new_product(register_new_product());
			break;
		case 2 :
			product_manager.display_products_by_seller_id(cur_user.get_id());
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
void EleventhStreet::display_all_products()
{
	product_manager.display_products_in_category();
	return;
}

void EleventhStreet::request_order(Order new_order) 
{
	int input = 0;
	cout << "���� ��ٱ��� �׸��Դϴ�." << endl;
	order_list[cur_user_index].set_total_product_price();
	order_list[cur_user_index].set_delivery_price();
	order_list[cur_user_index].set_total_price();
	order_list[cur_user_index].display_order();
	cout << "�����Ͻðڽ��ϱ�?(1 : ��, �� �� : �ƴϿ�) : ";
	cin >> input;
	if (input == 1)
	{
		cout << "������ �Ϸ�Ǿ����ϴ�." << endl;
		order_list[cur_user_index].clear_order_item_list();
	}
	else
	{
		cout << "������ ��ҵǾ����ϴ�." << endl;
	}
	return;
}

void EleventhStreet::add_new_order() // �Ű����� �߰�
{
	Product temp_product = product_manager.get_product();
	OrderItem temp_item(temp_product.get_product_name());
	temp_item.set_quantity();
	temp_item.set_price(temp_product.get_main_price());
	order_list[cur_user_index].add_order_item(temp_item);
	cout << "�����Ͻ� ��ǰ :" << temp_item.get_product_name() << endl;
	cout << "��ǰ ���� : " << temp_item.get_price() << endl;
	cout << "��ǰ ���� : " << temp_item.get_quantity() << endl;
	cout << "��ǰ �� ���� :" << temp_item.get_price() * temp_item.get_quantity() << endl << endl;
	return;
}

void EleventhStreet::display_orders_by_buyer_id() const
{
	cout << "�ֹ� ��ǰ ����" << endl;
	order_list[cur_user_index].display_order();
	return;
}

Order EleventhStreet::get_order()
{
	return order_list[cur_user_index];
}

// BuyerMallInterface - BuyerInterface
void EleventhStreet::go_shopping()
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

void EleventhStreet::look_up_my_order_list() const
{
	cout << "�� ��ٱ��� ���" << endl;
	cout << "������ :" << buyer_list[cur_user_index].get_user_name() << endl;
	order_list[cur_user_index].display_order_details();
	return;
}

void EleventhStreet::my_information()
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

EleventhStreet::EleventhStreet()
{
	int input;
	set_ids_and_orders();
	while (1)
	{
		use_eleventh_street();
		cout << "11������ �����Ͻðڽ��ϱ�?(�� : 1, �� �� ���� : �ƴϿ�)" ;
		cin >> input;
		if (input == 1) break;
	}
	cout << "11������ �����մϴ�." << endl;
}