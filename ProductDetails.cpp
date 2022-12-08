#include "ProductDetails.h"
using namespace std;

// private)
void ProductDetails::set_product_name()
{
	cout << "��ǰ���� �����ϼ��� : ";
	std::cin >> std::ws;
	getline(cin, product_name);
	return;
}

void ProductDetails::set_main_price()
{
	cout << endl << "������ �����ϼ��� : ";
	cin >> main_price;
	return;
}

void ProductDetails::set_main_category()
{
	cout << endl << "ī�װ��� �����ϼ��� : ";
	main_category = category_manager.choose_main_category();
	return;
}

void ProductDetails::set_posted_date()
{
	time_t temp_time_t = time(0);
	posted_date = localtime(&temp_time_t);
	temp_time_t += 2592000;	// 30�Ͽ� �ش��ϴ� ��
	effective_date = localtime(&temp_time_t);
	return;
}

void ProductDetails::extension_effective_time()	// ��ȿ�Ⱓ ���� ���� ���� 30�� �߰�
{
	time_t temp_time_t = time(0);
	temp_time_t += 2592000;	// 30�Ͽ� �ش��ϴ� ��
	effective_date = localtime(&temp_time_t);
	return;
}

void ProductDetails::print_options() const // �޴� ���� �� ǥ���� ��������
{
	cout << "������ �׸��� �����ϼ���." << endl;
	cout << "1. ��ǰ�� ����" << endl;
	cout << "2. ���� ����" << endl;
	cout << "3. ī�װ� ����" << endl;
	cout << "4. ��ǰ ��� �Ⱓ ����" << endl;
	cout << "�� �� : ���� ����" << endl << endl;
	return;
}

// DetailsInterface Interface
void ProductDetails::init_details()
{
	set_product_name();
	set_main_price();
	set_main_category();
	set_posted_date();
	cout << endl << "��ǰ �ʱ� ����� �Ϸ�Ǿ����ϴ�." << endl << endl;
	return;
}

// public
ProductDetails::ProductDetails()
{
	init_details();
}

string ProductDetails::get_product_name() const
{
	return product_name;
}

unsigned int ProductDetails::get_main_price() const
{
	return main_price;
}
	
MainCategory ProductDetails::get_category() const
{
	return main_category;
}

// DetailsInterface Interface
void ProductDetails::modify_details()
{
	bool is_break_while = false;
	int option_num;
	while (1)
	{
		print_options();
		cin >> option_num;

		switch (option_num)
		{
		case 1:
			cout << "product_name�� �����մϴ�." << endl;
			cout << "������ product_name�� �Է��ϼ��� : ";
			cin >> product_name;
			cout << "product_name�� " << product_name << "�� ����Ǿ����ϴ�." << endl;
			break;
		case 2:
			cout << "main_price�� �����մϴ�." << endl;
			cout << "������ main_price�� �Է��ϼ��� : ";
			cin >> main_price;
			cout << "main_price�� " << main_price << "�� ����Ǿ����ϴ�." << endl;
			break;
		case 3:
			cout << "category�� �����մϴ�." << endl;
			main_category = category_manager.choose_main_category();
			break;
		case 4:
			extension_effective_time();
			cout << "��ȿ�Ⱓ��" << effective_date->tm_year << "�� " << effective_date->tm_mon << "�� "
				<< effective_date->tm_mday << "�Ϸ� ����Ǿ����ϴ�." << endl;
		default:
			is_break_while = true;
			break;
		}
		cout << endl;
		if (is_break_while)
		{
			cout << "���� ������ �����մϴ�." << endl;
			break;
		}
	}
	return;
}

void ProductDetails::display_details() const	// ���� ���� ǥ��
{
	cout << "product_name : " << product_name << endl;
	cout << "main_price : " << main_price << endl;
	cout << "posted_date : " << posted_date->tm_year << "�� " << posted_date->tm_mon << "�� "
		<< posted_date->tm_mday << "��" << endl;
	cout << "effective_date : " << effective_date->tm_year << "�� " << effective_date->tm_mon << "�� "
		<< effective_date->tm_mday << "��" << endl;
	cout << "category : " << category_manager.main_category_to_string(main_category) << endl;
	return;
}