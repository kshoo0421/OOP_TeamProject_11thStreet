#include "ProductDetails.h"
using namespace std;

class ProductDetails : public DetailsInterface
{
private:
	unsigned int main_price;	// 기본 가격
	string product_name;	// 상품명
	
	string main_category;	// 메인 카테고리
	string sub_category;	// 세부 카테고리

	tm* posted_date;	// 상품 등록일
	tm* effective_date;	// 게시 유효일

	// 개인 추가
	void print_options() const // 메뉴 선택 시 표시할 선택지들
	{
		cout << "설정할 항목을 선택하세요.\n";
		cout << "1. product_name\n";
		cout << "2. main_price\n";
		cout << "3. category(main, sub)\n";
	}

	void input_change(const int& option_num, string& string_temp, unsigned int& ui_temp) const	// 변화하고 싶은 항목을 입력 및 확인하는 함수
	{
		bool is_right;	// 탈출 확인용
		string options[3] = { "product_name", "main_price", "category" };
		while (1)	// 확인될 때까지 반복
		{
			if (option_num == 3) return; // 카테고리는 예외. 추후 함수에서 진행

			(option_num == 1) ? cin >> string_temp : cin >> ui_temp;	// string인지 unsigned int 인지 확인 후 입력받음
			// 확인
			cout << options[option_num - 1] << "이 ";
			(option_num == 2) ? cout << string_temp : cout << ui_temp;
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
		case 2:
			main_price = ui_temp;
			cout << "main_price는 " << main_price << "원입니다.\n\n";
			break;
		case 3:
			set_category();
			cout << "main_category는 " << main_category << "입니다.\n\n";
			cout << "sub_category는 " << sub_category << "입니다.\n\n";
			break;
		default: break;
		}
		return;
	}

	void set_category()
	{
		// 카테고리 설정
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

	void end_registeration()	// 첫 확정일자
	{
		if (posted_date == NULL)
		{
			time_t temp_time_t = time(0);
			posted_date = localtime(&temp_time_t);
			temp_time_t += 2592000;	// 30일에 해당하는 초
			effective_date = localtime(&temp_time_t);
		}
		return;
	}

	void extension_effective_time()	// 유효기간 현재 일자 기준 30일 추가
	{
		time_t temp_time_t = time(0);
		temp_time_t += 2592000;	// 30일에 해당하는 초
		effective_date = localtime(&temp_time_t);
		return;
	}

	// DetailsInterface Interface
	void init_details() override
	{

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
			if (option_num < 0 || option_num > 3) 
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

	void display_details() const override	// 세부 내용 표시
	{
		cout << "product_name : " << product_name << endl;
		cout << "main_price : " << main_price << endl;
		cout << "posted_date : " << posted_date->tm_year << "년 " << posted_date->tm_mon << "월 "
			<< posted_date->tm_mday << "일\n";
		cout << "effective_date : " << effective_date->tm_year << "년 " << effective_date->tm_mon << "월 "
			<< effective_date->tm_mday << "일\n";
		cout << "main_category : " << main_category << endl;
		cout << "sub_category : " << sub_category << endl;
	}
};