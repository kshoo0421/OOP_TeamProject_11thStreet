#include "ProductDetails.h"
using namespace std;

ProductDetails::ProductDetails()
{
	category_manager = new CategoryManager();
}

ProductDetails::~ProductDetails()
{
	delete category_manager;
}

void ProductDetails::print_options() const // 메뉴 선택 시 표시할 선택지들
{
	cout << "설정할 항목을 선택하세요.\n";
	cout << "1. product_name\n";
	cout << "2. main_price\n";
	cout << "3. category\n";
	cout << "그 외 : 수정 종료\n\n";
	return;
}

unsigned int ProductDetails::get_main_price() const
{
	return main_price;
}
	
enum MainCategory ProductDetails::get_category() const
{
	return main_category;
}

void ProductDetails::end_registeration()	// 첫 확정일자
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

void ProductDetails::extension_effective_time()	// 유효기간 현재 일자 기준 30일 추가
{
	time_t temp_time_t = time(0);
	temp_time_t += 2592000;	// 30일에 해당하는 초
	effective_date = localtime(&temp_time_t);
	return;
}

// DetailsInterface Interface
void ProductDetails::init_details()
{
	cout << "초기값을 설정합니다.\n";
	cout << "product_name를 입력하세요 : ";
	cin >> product_name;

	cout << "main_price을 입력하세요 : ";
	cin >> main_price;

	cout << "category를 설정하세요 : ";
	main_category = category_manager->choose_main_category();
	return;
}

void ProductDetails::modify_details()
{
	bool is_break_while = false;
	int option_num;
	while (1)
	{
		print_options();
		cin >> option_num;
		cout << "1. product_name\n";
		cout << "2. main_price\n";
		cout << "3. category(main, sub)\n";

		switch (option_num)
		{
		case 1:
			cout << "product_name을 변경합니다.\n";
			cout << "변경할 product_name를 입력하세요 : ";
			cin >> product_name;
			cout << "product_name이 " << product_name << "로 변경되었습니다.\n";
			break;
		case 2:
			cout << "main_price를 변경합니다.\n";
			cout << "변경할 main_price를 입력하세요 : ";
			cin >> main_price;
			cout << "main_price가 " << main_price << "로 변경되었습니다.\n";
			break;
		case 3:
			cout << "category를 변경합니다.\n";
			main_category = category_manager->choose_main_category();
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

void ProductDetails::display_details() const	// 세부 내용 표시
{
	cout << "product_name : " << product_name << endl;
	cout << "main_price : " << main_price << endl;
	cout << "posted_date : " << posted_date->tm_year << "년 " << posted_date->tm_mon << "월 "
		<< posted_date->tm_mday << "일\n";
	cout << "effective_date : " << effective_date->tm_year << "년 " << effective_date->tm_mon << "월 "
		<< effective_date->tm_mday << "일\n";
	cout << "category : " << category_manager->main_category_to_string(main_category) << endl;
	return;
}