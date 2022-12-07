#include "DeliveryDetails.h"
using namespace std;

void DeliveryDetails::print_options()
{
	cout << "������ �׸��� �����ϼ���.\n";
	cout << "1. delivery_fee\n";
	cout << "�� �� : ���� ����\n\n";
}

unsigned int DeliveryDetails::get_delivery_fee() const
{
	return delivery_fee;
}

// DetailsInterface
void DeliveryDetails::init_details()
{
	cout << "�ʱⰪ�� �����մϴ�.\n";
	cout << "delivery_fee�� �Է��ϼ��� : ";
	cin >> delivery_fee;
	return;
}
	 
void DeliveryDetails::modify_details() 
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

void DeliveryDetails::display_details() const 
{
	cout << "delivery_fee : " << delivery_fee << endl;
	return;
}