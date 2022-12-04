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
		cout << "수정할 항목을 선택하세요.\n";
		cout << "1. delivery_fee\n";
		cout << "2. free_delivery_amount\n";
		cout << "3. exchange_delivery_fee\n";
		cout << "4. return_delivery_fee\n";
		cout << "5. lead_time\n";
		cout << "그 외 : 수정 종료\n\n";
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
		cout << "초기값을 설정합니다.\n";
		cout << "delivery_fee를 입력하세요 : ";
		cin >> delivery_fee;
		cout << "free_delivery_amount을 입력하세요 : ";
		cin >> free_delivery_amount;
		cout << "exchange_delivery_fee을 입력하세요 : ";
		cin >> exchange_delivery_fee;
		cout << "return_delivery_fee을 입력하세요 : ";
		cin >> return_delivery_fee;
		cout << "lead_time를 입력하세요 : ";
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
				cout << "delivery_fee를 변경합니다.\n";
				cout << "변경할 delivery_fee를 입력하세요 : ";
				cin >> delivery_fee;
				cout << "delivery_fee가 " << delivery_fee << "로 변경되었습니다.\n";
				break;
			case 2:
				cout << "free_delivery_amount를 변경합니다.\n";
				cout << "변경할 free_delivery_amount를 입력하세요 : ";
				cin >> free_delivery_amount;
				cout << "free_delivery_amount가 " << free_delivery_amount << "로 변경되었습니다.\n";
				break;
			case 3:
				cout << "exchange_delivery_fee를 변경합니다.\n";
				cout << "변경할 exchange_delivery_fee를 입력하세요 : ";
				cin >> exchange_delivery_fee;
				cout << "exchange_delivery_fee가 " << exchange_delivery_fee << "로 변경되었습니다.\n";
				break;
			case 4:
				cout << "return_delivery_fee를 변경합니다.\n";
				cout << "변경할 return_delivery_fee를 입력하세요 : ";
				cin >> return_delivery_fee;
				cout << "return_delivery_fee가 " << return_delivery_fee << "로 변경되었습니다.\n";
				break;
			case 5:
				cout << "lead_time을 변경합니다.\n";
				cout << "변경할 lead_time를 입력하세요 : ";
				cin >> lead_time;
				cout << "lead_time이 " << lead_time << "로 변경되었습니다.\n";
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