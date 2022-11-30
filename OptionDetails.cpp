#include "OptionDetails.h"
using namespace std;

class OptionDetails : public DetailsInterface
{
private:
	string option_value;
	unsigned int additional_price;
	unsigned int stock;

	// 개인 추가
	void print_options()
	{
		cout << "수정할 항목을 선택하세요.\n";
		cout << "1. option_value\n";
		cout << "2. additional_price\n";
		cout << "3. stock\n";
	}
	void input_change(const int& option_num, string& string_temp, unsigned int& ui_temp) const	// 변화하고 싶은 항목을 입력 및 확인하는 함수
	{
		bool is_right;	// 탈출 확인용
		string options[3] = { "option_value", "additional_price", "stock" };
		while (1)
		{
			cout << options[option_num - 1] << "을 입력하세요\n";
			(option_num == 1) ? cin >> string_temp : cin >> ui_temp;
			cout << options[option_num - 1] << "이 ";
			(option_num == 1) ? cout << string_temp : cout << ui_temp;
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
			option_value = string_temp;
			cout << "option_value은 " << option_value << "입니다.\n\n";
			break;
		case 2:
			additional_price = ui_temp;
			cout << "additional_price는 " << additional_price << "원입니다.\n\n";
			break;
		case 3:
			stock = ui_temp;
			cout << "stock는 " << stock << "입니다.\n\n";
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

	// 인터페이스 내용
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
		std::cout << "option_value : " << option_value << std::endl;
		std::cout << "additional_price : " << additional_price << std::endl;
		std::cout << "stock : " << stock << std::endl;
	}
};