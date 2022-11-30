#include "ProductDetails.h"
using namespace std;

class ProductDetails : public DetailsInterface
{
private:
	string product_name;	// ��ǰ��
	const time_t posted_date = time(NULL);	// ?
	time_t effective_date;	// ?
	string main_category;	// ���� ī�װ�
	string sub_category;	// ���� ī�װ�
	unsigned int main_price;	// �⺻ ����

	// ���� �߰�
	void print_options() const // �޴� ���� �� ǥ���� ��������
	{
		cout << "������ �׸��� �����ϼ���.\n";
		cout << "1. product_name\n";
		cout << "2. effective_date\n";
		cout << "3. main_category\n";
		cout << "4. sub_category\n";
		cout << "5. main_price\n";
	}

	void input_change(const int& option_num, string& string_temp, unsigned int& ui_temp) const	// ��ȭ�ϰ� ���� �׸��� �Է� �� Ȯ���ϴ� �Լ�
	{
		bool is_right;	// Ż�� Ȯ�ο�
		string options[6] = { "product_name", "effective_date", "main_category", "sub_category", "main_price" };
		while (1)	// Ȯ�ε� ������ �ݺ�
		{
			// �Է�
			cout << options[option_num - 1] << "�� �Է��ϼ���\n";
			(option_num != 5) ? cin >> string_temp : cin >> ui_temp;	// string���� unsigned int ���� Ȯ�� �� �Է¹���
			// Ȯ��
			cout << options[option_num - 1] << "�� ";
			(option_num != 5) ? cout << string_temp : cout << ui_temp;
			cout << "��(��) �½��ϱ�?(true/false)\n";
			cin >> is_right;
			if (is_right) break;	// �´ٸ� Ż��
		}
	}

	void fix_change(const int& option_num, const string& string_temp, const unsigned int& ui_temp)	// Ȯ�ε� ������ ���� ���� ��ȭ��Ű�� �Լ�
	{
		switch (option_num)
		{
		case 1:
			product_name = string_temp;
			cout << "product_name�� " << product_name << "�Դϴ�.\n\n";
			break;
		case 3:
			main_category = string_temp;
			cout << "main_category�� " << main_category << "�Դϴ�.\n\n";
			break;
		case 4:
			sub_category = string_temp;
			cout << "sub_category�� " << sub_category << "�Դϴ�.\n\n";
			break;
		case 5:
			main_price = ui_temp;
			cout << "main_price�� " << main_price << "���Դϴ�.\n\n";
			break;
		default: break;
		}
		return;
	}
	// ���� �߰� ��

public:
	ProductDetails()
	{
		init_details();
	}
	~ProductDetails() = default;

	unsigned int get_main_price() const
	{
		return main_price;
	}

	// DetailsInterface Interface
	void init_details() override
	{
		product_name = "";
		posted_date;
		effective_date;
		main_category = "";
		sub_category = "";
		main_price = 0;
	}

	void modify_details() override
	{
		int option_num;
		unsigned int ui_temp;
		string string_temp;

		while (1)
		{
			print_options();
			cin >> option_num;
			if (option_num < 0 || option_num > 5) 
			{
				cout << "���� ������ �����մϴ�\n";
				break;
			}
			else if (option_num == 2)
			{
				effective_date = time(NULL);
				cout << "effective_date�� ������Ʈ�Ǿ����ϴ�.\n\n";
			}
			else
			{	
				input_change(option_num, string_temp, ui_temp);
				fix_change(option_num, string_temp, ui_temp);
			}
		}
		return;
	}

	void display_details() const override	// ���� ���� ǥ��
	{
		cout << product_name << endl;
		cout << posted_date << endl;
		cout << effective_date << endl;
		cout << main_category << endl;
		cout << sub_category << endl;
		cout << main_price << endl;
	}
};