#include "OptionDetails.h"
using namespace std;

class OptionDetails : public DetailsInterface
{
private:
	string option_value;
	unsigned int additional_price;
	unsigned int stock;

	// ���� �߰�
	void print_options()
	{
		cout << "������ �׸��� �����ϼ���.\n";
		cout << "1. option_value\n";
		cout << "2. additional_price\n";
		cout << "3. stock\n";
		cout << "�� �� : ���� ����\n";
		return;
	}

public:
	std::string get_option_value() const
	{
		return option_value;
	}

	int get_additional_price() const
	{
		return additional_price;
	}

	bool is_sold_out() const
	{
		if (stock == 0) return true;
		else return false;
	}

	// �������̽� ����
	void init_details() override
	{
		cout << "�ʱⰪ�� �����մϴ�.\n";
		cout << "option_value�� �Է��ϼ��� : ";
		cin >> option_value;
		cout << "additional_price�� �Է��ϼ��� : ";
		cin >> additional_price;
		cout << "stock�� �Է��ϼ��� : ";
		cin >> stock;
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
			switch (option_num)
			{
			case 1:
				cout << "option_value�� �����մϴ�.\n";
				cout << "������ option_value�� �Է��ϼ��� : ";
				cin >> option_value;
				cout << "option_value�� " << option_value << "�� ����Ǿ����ϴ�.\n";
				break;
			case 2:
				cout << "additional_price�� �����մϴ�.\n";
				cout << "������ additional_price�� �Է��ϼ��� : ";
				cin >> additional_price;
				cout << "additional_price�� " << additional_price << "�� ����Ǿ����ϴ�.\n";
				break;
			case 3:
				cout << "stock�� �����մϴ�.\n";
				cout << "������ stock�� �Է��ϼ��� : ";
				cin >> stock;
				cout << "stock�� " << stock << "�� ����Ǿ����ϴ�.\n";
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

	void display_details() const override
	{
		std::cout << "option_value : " << option_value << std::endl;
		std::cout << "additional_price : " << additional_price << std::endl;
		std::cout << "stock : " << stock << std::endl;
		return;
	}
};