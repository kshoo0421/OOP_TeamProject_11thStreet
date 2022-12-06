#include "DeliveryDetails.h"
using namespace std;

class DeliveryDetails : public DetailsInterface
{
private:
	unsigned int delivery_fee;
	string lead_time;

	void print_options()
	{
		cout << "������ �׸��� �����ϼ���.\n";
		cout << "1. delivery_fee\n";
		cout << "2. lead_time\n";
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


	// DetailsInterface
	void init_details() override
	{
		cout << "�ʱⰪ�� �����մϴ�.\n";
		cout << "delivery_fee�� �Է��ϼ��� : ";
		cin >> delivery_fee;
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
		cout << "lead_time : " << lead_time << endl;
		return;
	}
};