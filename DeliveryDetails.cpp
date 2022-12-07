#include "DeliveryDetails.h"
using namespace std;

void DeliveryDetails::print_options()
{
	cout << "수정할 항목을 선택하세요.\n";
	cout << "1. delivery_fee\n";
	cout << "그 외 : 수정 종료\n\n";
}

unsigned int DeliveryDetails::get_delivery_fee() const
{
	return delivery_fee;
}

// DetailsInterface
void DeliveryDetails::init_details()
{
	cout << "초기값을 설정합니다.\n";
	cout << "delivery_fee를 입력하세요 : ";
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
			cout << "delivery_fee를 변경합니다.\n";
			cout << "변경할 delivery_fee를 입력하세요 : ";
			cin >> delivery_fee;
			cout << "delivery_fee가 " << delivery_fee << "로 변경되었습니다.\n";
			break;

		default :
			is_break_while = true;
			break;
		}
		if (is_break_while)
		{
			cout << "내용 수정을 종료합니다\n";
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