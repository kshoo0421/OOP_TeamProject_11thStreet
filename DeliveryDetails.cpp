#include "DeliveryDetails.h"
using namespace std;

class DeliveryDetails : public DetailsInterface
{
private:
	unsigned int delivery_fee;
	unsigned int free_delivery_amount;
	unsigned int exchange_delivery_fee;
	unsigned int return_delivery_fee;
	string lead_time;
	// ���� �߰�
	void print_options()
	{
		cout << "������ �׸��� �����ϼ���.\n";
		cout << "1. delivery_fee\n";
		cout << "2. free_delivery_amount\n";
		cout << "3. exchange_delivery_fee\n";
		cout << "4. return_delivery_fee\n";
		cout << "5. lead_time\n";
		cout << "�� �� : ���� ����\n\n";
	}

	void input_change(const int& option_num, string& string_temp, unsigned int& ui_temp) const	// ��ȭ�ϰ� ���� �׸��� �Է� �� Ȯ���ϴ� �Լ�
	{
		bool is_right;	// Ż�� Ȯ�ο�
		string options[5] = { "delivery_fee", "free_delivery_amount", "exchange_delivery_fee",  "return_delivery_fee", "lead_times"};
		while (1)
		{
			cout << options[option_num - 1] << "�� �Է��ϼ���\n";
			(option_num == 5) ? cin >> string_temp : cin >> ui_temp;
			cout << options[option_num - 1] << "�� ";
			(option_num == 5) ? cout << string_temp : cout << ui_temp;
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
			delivery_fee = ui_temp;
			cout << "delivery fee�� " << delivery_fee << "���Դϴ�.\n\n";
			break;
		case 2:
			free_delivery_amount = ui_temp;
			cout << "free_delivery_amount�� " << free_delivery_amount << "�Դϴ�.\n\n";
			break;
		case 3:
			cout << exchange_delivery_fee << endl;
			cout << "exchange_delivery_fee�� " << exchange_delivery_fee << "���Դϴ�.\n\n";
			break;
		case 4:
			cout << return_delivery_fee << endl;
			cout << "return_delivery_fee�� " << return_delivery_fee << "���Դϴ�.\n\n";
			break;
		case 5:
			lead_time = string_temp;
			cout << "lead_time�� " << lead_time << "�Դϴ�.\n\n";
			break;
		}
		return;
	}

	// ���� �߰� ��

public:
	DeliveryDetails()
	{
		init_details();
	}

	~DeliveryDetails() = default;

	string get_lead_time() const
	{
		return lead_time;
	}

	unsigned int get_delivery_fee() const
	{
		return delivery_fee;
	}

	unsigned int get_free_delivery_amount() const
	{
		return free_delivery_amount;
	}

	// DetailsInterface
	void init_details() override
	{
		lead_time = "";
		delivery_fee = 0;
		free_delivery_amount = 0;
		exchange_delivery_fee = 0;
		return_delivery_fee = 0;
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
			if (option_num < 0 || option_num > 4)
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
		cout << lead_time << endl;
		cout << delivery_fee << endl;
		cout << free_delivery_amount << endl;
		cout << exchange_delivery_fee << endl;
		cout << return_delivery_fee << endl;
	}
};