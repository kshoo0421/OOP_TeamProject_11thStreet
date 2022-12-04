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
		cout << "그 외 : 수정 종료\n";
		return;
	}

public:
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
		cout << "초기값을 설정합니다.\n";
		cout << "option_value를 입력하세요 : ";
		cin >> option_value;
		cout << "additional_price을 입력하세요 : ";
		cin >> additional_price;
		cout << "stock을 입력하세요 : ";
		cin >> stock;
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
				cout << "option_value를 변경합니다.\n";
				cout << "변경할 option_value를 입력하세요 : ";
				cin >> option_value;
				cout << "option_value가 " << option_value << "로 변경되었습니다.\n";
				break;
			case 2:
				cout << "additional_price를 변경합니다.\n";
				cout << "변경할 additional_price를 입력하세요 : ";
				cin >> additional_price;
				cout << "additional_price가 " << additional_price << "로 변경되었습니다.\n";
				break;
			case 3:
				cout << "stock를 변경합니다.\n";
				cout << "변경할 stock를 입력하세요 : ";
				cin >> stock;
				cout << "stock가 " << stock << "로 변경되었습니다.\n";
				break;
			default:
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
		std::cout << "option_value : " << option_value << std::endl;
		std::cout << "additional_price : " << additional_price << std::endl;
		std::cout << "stock : " << stock << std::endl;
		return;
	}
};