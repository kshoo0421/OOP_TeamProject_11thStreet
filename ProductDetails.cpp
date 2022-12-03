#include "ProductDetails.h"
using namespace std;

class ProductDetails : public DetailsInterface
{
private:
	unsigned int main_price;	// �⺻ ����
	string product_name;	// ��ǰ��
	
	string main_category;	// ���� ī�װ�
	string sub_category;	// ���� ī�װ�

	tm* posted_date;	// ��ǰ �����
	tm* effective_date;	// �Խ� ��ȿ��

	// ���� �߰�
	void print_options() const // �޴� ���� �� ǥ���� ��������
	{
		cout << "������ �׸��� �����ϼ���.\n";
		cout << "1. product_name\n";
		cout << "2. main_price\n";
		cout << "3. category(main, sub)\n";
	}

	void input_change(const int& option_num, string& string_temp, unsigned int& ui_temp) const	// ��ȭ�ϰ� ���� �׸��� �Է� �� Ȯ���ϴ� �Լ�
	{
		bool is_right;	// Ż�� Ȯ�ο�
		string options[3] = { "product_name", "main_price", "category" };
		while (1)	// Ȯ�ε� ������ �ݺ�
		{
			if (option_num == 3) return; // ī�װ��� ����. ���� �Լ����� ����

			(option_num == 1) ? cin >> string_temp : cin >> ui_temp;	// string���� unsigned int ���� Ȯ�� �� �Է¹���
			// Ȯ��
			cout << options[option_num - 1] << "�� ";
			(option_num == 2) ? cout << string_temp : cout << ui_temp;
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
		case 2:
			main_price = ui_temp;
			cout << "main_price�� " << main_price << "���Դϴ�.\n\n";
			break;
		case 3:
			set_category();
			cout << "main_category�� " << main_category << "�Դϴ�.\n\n";
			cout << "sub_category�� " << sub_category << "�Դϴ�.\n\n";
			break;
		default: break;
		}
		return;
	}

	void set_category()
	{
		// ī�װ� ����
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
			if (option_num < 0 || option_num > 3) 
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

	void display_details() const override	// ���� ���� ǥ��
	{
		cout << "product_name : " << product_name << endl;
		cout << "main_price : " << main_price << endl;
		cout << "posted_date : " << posted_date->tm_year << "�� " << posted_date->tm_mon << "�� "
			<< posted_date->tm_mday << "��\n";
		cout << "effective_date : " << effective_date->tm_year << "�� " << effective_date->tm_mon << "�� "
			<< effective_date->tm_mday << "��\n";
		cout << "main_category : " << main_category << endl;
		cout << "sub_category : " << sub_category << endl;
	}
};