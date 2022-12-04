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

public:
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
		cout << "�ʱⰪ�� �����մϴ�.\n";
		cout << "delivery_fee�� �Է��ϼ��� : ";
		cin >> delivery_fee;
		cout << "free_delivery_amount�� �Է��ϼ��� : ";
		cin >> free_delivery_amount;
		cout << "exchange_delivery_fee�� �Է��ϼ��� : ";
		cin >> exchange_delivery_fee;
		cout << "return_delivery_fee�� �Է��ϼ��� : ";
		cin >> return_delivery_fee;
		cout << "lead_time�� �Է��ϼ��� : ";
		cin >> lead_time;
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
				cout << "delivery_fee�� �����մϴ�.\n";
				cout << "������ delivery_fee�� �Է��ϼ��� : ";
				cin >> delivery_fee;
				cout << "delivery_fee�� " << delivery_fee << "�� ����Ǿ����ϴ�.\n";
				break;
			case 2:
				cout << "free_delivery_amount�� �����մϴ�.\n";
				cout << "������ free_delivery_amount�� �Է��ϼ��� : ";
				cin >> free_delivery_amount;
				cout << "free_delivery_amount�� " << free_delivery_amount << "�� ����Ǿ����ϴ�.\n";
				break;
			case 3:
				cout << "exchange_delivery_fee�� �����մϴ�.\n";
				cout << "������ exchange_delivery_fee�� �Է��ϼ��� : ";
				cin >> exchange_delivery_fee;
				cout << "exchange_delivery_fee�� " << exchange_delivery_fee << "�� ����Ǿ����ϴ�.\n";
				break;
			case 4:
				cout << "return_delivery_fee�� �����մϴ�.\n";
				cout << "������ return_delivery_fee�� �Է��ϼ��� : ";
				cin >> return_delivery_fee;
				cout << "return_delivery_fee�� " << return_delivery_fee << "�� ����Ǿ����ϴ�.\n";
				break;
			case 5:
				cout << "lead_time�� �����մϴ�.\n";
				cout << "������ lead_time�� �Է��ϼ��� : ";
				cin >> lead_time;
				cout << "lead_time�� " << lead_time << "�� ����Ǿ����ϴ�.\n";
				break;

			default :
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
		cout << "delivery_fee : " << delivery_fee << endl;
		cout << "free_delivery_amount : " << free_delivery_amount << endl;
		cout << "exchange_delivery_fee : " << exchange_delivery_fee << endl;
		cout << "return_delivery_fee : " << return_delivery_fee << endl;
		cout << "lead_time : " << lead_time << endl;
		return;
	}
};