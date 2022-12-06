#include "ProductDetails.h"
#include "CategoryManager.h"
using namespace std;

class ProductDetails : public DetailsInterface
{
private:
	CategoryManager category_manager;

	unsigned int main_price;	// �⺻ ����
	string product_name;	// ��ǰ��
	
	MainCategory main_category;	// ���� ī�װ�

	tm* posted_date;	// ��ǰ �����
	tm* effective_date;	// �Խ� ��ȿ��

	void print_options() const // �޴� ���� �� ǥ���� ��������
	{
		cout << "������ �׸��� �����ϼ���.\n";
		cout << "1. product_name\n";
		cout << "2. main_price\n";
		cout << "3. category\n";
		cout << "�� �� : ���� ����\n\n";
		return;
	}

public:
	unsigned int get_main_price() const
	{
		return main_price;
	}
	
	MainCategory get_category() const
	{
		return main_category;
	}


	void end_registeration()	// ù Ȯ������
	{
		if (posted_date == NULL)
		{
			time_t temp_time_t = time(0);
			posted_date = localtime(&temp_time_t);
			temp_time_t += 2592000;	// 30�Ͽ� �ش��ϴ� ��
			effective_date = localtime(&temp_time_t);
		}
		return;
	}

	void extension_effective_time()	// ��ȿ�Ⱓ ���� ���� ���� 30�� �߰�
	{
		time_t temp_time_t = time(0);
		temp_time_t += 2592000;	// 30�Ͽ� �ش��ϴ� ��
		effective_date = localtime(&temp_time_t);
		return;
	}

	// DetailsInterface Interface
	void init_details() override
	{
		cout << "�ʱⰪ�� �����մϴ�.\n";
		cout << "product_name�� �Է��ϼ��� : ";
		cin >> product_name;

		cout << "main_price�� �Է��ϼ��� : ";
		cin >> main_price;

		cout << "category�� �����ϼ��� : ";
		main_category = category_manager.choose_main_category();
		return;
	}

	void modify_details() override
	{
		bool is_break_while = false;
		int option_num;
		while (1)
		{
			print_options();
			cin >> option_num;
			cout << "1. product_name\n";
			cout << "2. main_price\n";
			cout << "3. category(main, sub)\n";

			switch (option_num)
			{
			case 1:
				cout << "product_name�� �����մϴ�.\n";
				cout << "������ product_name�� �Է��ϼ��� : ";
				cin >> product_name;
				cout << "product_name�� " << product_name << "�� ����Ǿ����ϴ�.\n";
				break;
			case 2:
				cout << "main_price�� �����մϴ�.\n";
				cout << "������ main_price�� �Է��ϼ��� : ";
				cin >> main_price;
				cout << "main_price�� " << main_price << "�� ����Ǿ����ϴ�.\n";
				break;
			case 3:
				cout << "category�� �����մϴ�.\n";
				main_category = category_manager.choose_main_category();
				break;
			default:
				is_break_while = true;
				break;
			}
			if (is_break_while)
			{
				cout << "���� ������ �����մϴ�\n";
				break;
			}
		}
		return;
	}

	void display_details() const override	// ���� ���� ǥ��
	{
		cout << "product_name : " << product_name << endl;
		cout << "main_price : " << main_price << endl;
		cout << "posted_date : " << posted_date->tm_year << "�� " << posted_date->tm_mon << "�� "
			<< posted_date->tm_mday << "��\n";
		cout << "effective_date : " << effective_date->tm_year << "�� " << effective_date->tm_mon << "�� "
			<< effective_date->tm_mday << "��\n";
		cout << "category : " << category_manager.main_category_to_string(main_category) << endl;
	}
};