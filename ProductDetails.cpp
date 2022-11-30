#include "ProductDetails.h"
using namespace std;

class ProductDetails : public DetailsInterface
{
private:
	string product_name;	// 상품명
	const time_t posted_date = time(NULL);	// ?
	time_t effective_date;	// ?
	string main_category;	// 메인 카테고리
	string sub_category;	// 세부 카테고리
	unsigned int main_price;	// 기본 가격

	// 개인 추가
	void print_options() const // 메뉴 선택 시 표시할 선택지들
	{
		cout << "수정할 항목을 선택하세요.\n";
		cout << "1. product_name\n";
		cout << "2. effective_date\n";
		cout << "3. main_category\n";
		cout << "4. sub_category\n";
		cout << "5. main_price\n";
	}

	void input_change(const int& option_num, string& string_temp, unsigned int& ui_temp) const	// 변화하고 싶은 항목을 입력 및 확인하는 함수
	{
		bool is_right;	// 탈출 확인용
		string options[6] = { "product_name", "effective_date", "main_category", "sub_category", "main_price" };
		while (1)	// 확인될 때까지 반복
		{
			// 입력
			cout << options[option_num - 1] << "을 입력하세요\n";
			(option_num != 5) ? cin >> string_temp : cin >> ui_temp;	// string인지 unsigned int 인지 확인 후 입력받음
			// 확인
			cout << options[option_num - 1] << "이 ";
			(option_num != 5) ? cout << string_temp : cout << ui_temp;
			cout << "이(가) 맞습니까?(true/false)\n";
			cin >> is_right;
			if (is_right) break;	// 맞다면 탈출
		}
	}

	void fix_change(const int& option_num, const string& string_temp, const unsigned int& ui_temp)	// 확인된 값으로 내부 값을 변화시키는 함수
	{
		switch (option_num)
		{
		case 1:
			product_name = string_temp;
			cout << "product_name은 " << product_name << "입니다.\n\n";
			break;
		case 3:
			main_category = string_temp;
			cout << "main_category는 " << main_category << "입니다.\n\n";
			break;
		case 4:
			sub_category = string_temp;
			cout << "sub_category는 " << sub_category << "입니다.\n\n";
			break;
		case 5:
			main_price = ui_temp;
			cout << "main_price는 " << main_price << "원입니다.\n\n";
			break;
		default: break;
		}
		return;
	}
	// 개인 추가 끝

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

	// DetailsInterface Interface
	void init_details() override
	{
		product_name = "";
		posted_date;
		effective_date;
		main_category = "";
		sub_category = "";
		main_price = 0;
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
			if (option_num < 0 || option_num > 5) 
			{
				cout << "내용 수정을 종료합니다\n";
				break;
			}
			else if (option_num == 2)
			{
				effective_date = time(NULL);
				cout << "effective_date가 업데이트되었습니다.\n\n";
			}
			else
			{	
				input_change(option_num, string_temp, ui_temp);
				fix_change(option_num, string_temp, ui_temp);
			}
		}
		return;
	}

	void display_details() const override	// 세부 내용 표시
	{
		cout << product_name << endl;
		cout << posted_date << endl;
		cout << effective_date << endl;
		cout << main_category << endl;
		cout << sub_category << endl;
		cout << main_price << endl;
	}
};