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
	// 개인 추가
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

	void input_change(const int& option_num, string& string_temp, unsigned int& ui_temp) const	// 변화하고 싶은 항목을 입력 및 확인하는 함수
	{
		bool is_right;	// 탈출 확인용
		string options[5] = { "delivery_fee", "free_delivery_amount", "exchange_delivery_fee",  "return_delivery_fee", "lead_times"};
		while (1)
		{
			cout << options[option_num - 1] << "을 입력하세요\n";
			(option_num == 5) ? cin >> string_temp : cin >> ui_temp;
			cout << options[option_num - 1] << "이 ";
			(option_num == 5) ? cout << string_temp : cout << ui_temp;
			cout << "이(가) 맞습니까?(true/false)\n";
			cin >> is_right;
			if (is_right) break;
		}
	}

	void fix_change(const int& option_num, const string& string_temp, const unsigned int& ui_temp)	// 확인된 값으로 내부 값을 변화시키는 함수
	{
		switch (option_num)
		{
		case 1:
			delivery_fee = ui_temp;
			cout << "delivery fee는 " << delivery_fee << "원입니다.\n\n";
			break;
		case 2:
			free_delivery_amount = ui_temp;
			cout << "free_delivery_amount는 " << free_delivery_amount << "입니다.\n\n";
			break;
		case 3:
			cout << exchange_delivery_fee << endl;
			cout << "exchange_delivery_fee는 " << exchange_delivery_fee << "원입니다.\n\n";
			break;
		case 4:
			cout << return_delivery_fee << endl;
			cout << "return_delivery_fee는 " << return_delivery_fee << "원입니다.\n\n";
			break;
		case 5:
			lead_time = string_temp;
			cout << "lead_time은 " << lead_time << "입니다.\n\n";
			break;
		}
		return;
	}

	// 개인 추가 끝

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
				cout << "내용 수정을 종료합니다\n";
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