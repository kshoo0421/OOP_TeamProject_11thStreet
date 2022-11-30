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
	}
	void input_change(const int& option_num, string& string_temp, unsigned int& ui_temp) const	// ��ȭ�ϰ� ���� �׸��� �Է� �� Ȯ���ϴ� �Լ�
	{
		bool is_right;	// Ż�� Ȯ�ο�
		string options[3] = { "option_value", "additional_price", "stock" };
		while (1)
		{
			cout << options[option_num - 1] << "�� �Է��ϼ���\n";
			(option_num == 1) ? cin >> string_temp : cin >> ui_temp;
			cout << options[option_num - 1] << "�� ";
			(option_num == 1) ? cout << string_temp : cout << ui_temp;
			cout << "��(��) �½��ϱ�?(true/false)\n";
			cin >> is_right;
			if (is_right) break;
		}
	}

	void fix_change(const int& option_num, const string& string_temp, const unsigned int& ui_temp)	// Ȯ�ε� ������ ���� ���� ��ȭ��Ű�� �Լ�
	{
		switch (option_num)
		{
		case 1:
			option_value = string_temp;
			cout << "option_value�� " << option_value << "�Դϴ�.\n\n";
			break;
		case 2:
			additional_price = ui_temp;
			cout << "additional_price�� " << additional_price << "���Դϴ�.\n\n";
			break;
		case 3:
			stock = ui_temp;
			cout << "stock�� " << stock << "�Դϴ�.\n\n";
			break;
		}
		return;
	}

public:
	OptionDetails()
	{
		init_details();
	}

	~OptionDetails() = default;

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
		option_value = "";
		additional_price = 0;
		stock = 0;
	}

	void modify_details() override
	{
		bool is_right;
		int option_num;
		unsigned int ui_temp;
		string string_temp;
		while (1)
		{
			print_options();
			cin >> option_num;
			if (option_num < 0 || option_num > 2)
			{
				cout << "���� ������ �����մϴ�\n";
				break;
			}
			else
			{
				input_change(option_num, string_temp, ui_temp);
				fix_change(option_num, string_temp, ui_temp);
			}
		}
		return;
	}

	void display_details() const override
	{
		std::cout << "option_value : " << option_value << std::endl;
		std::cout << "additional_price : " << additional_price << std::endl;
		std::cout << "stock : " << stock << std::endl;
	}
};