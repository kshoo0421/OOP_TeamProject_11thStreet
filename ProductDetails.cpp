#include "ProductDetails.h"
using namespace std;

// private)
void ProductDetails::set_product_name()
{
	cout << "상품명을 설정하세요 : ";
	std::cin >> std::ws;
	getline(cin, product_name);
	return;
}

void ProductDetails::set_main_price()
{
	cout << endl << "가격을 설정하세요 : ";
	cin >> main_price;
	return;
}

void ProductDetails::set_main_category()
{
	cout << endl << "카테고리를 설정하세요 : ";
	main_category = category_manager.choose_main_category();
	return;
}

void ProductDetails::set_posted_date()
{
	time_t temp_time_t = time(0);
	posted_date = localtime(&temp_time_t);
	temp_time_t += 2592000;	// 30일에 해당하는 초
	effective_date = localtime(&temp_time_t);
	return;
}

void ProductDetails::extension_effective_time()	// 유효기간 현재 일자 기준 30일 추가
{
	time_t temp_time_t = time(0);
	temp_time_t += 2592000;	// 30일에 해당하는 초
	effective_date = localtime(&temp_time_t);
	return;
}

void ProductDetails::print_options() const // 메뉴 선택 시 표시할 선택지들
{
	cout << "변경할 항목을 선택하세요." << endl;
	cout << "1. 상품명 변경" << endl;
	cout << "2. 가격 변경" << endl;
	cout << "3. 카테고리 변경" << endl;
	cout << "4. 상품 등록 기간 연장" << endl;
	cout << "그 외 : 수정 종료" << endl << endl;
	return;
}

// DetailsInterface Interface
void ProductDetails::init_details()
{
	set_product_name();
	set_main_price();
	set_main_category();
	set_posted_date();
	cout << endl << "상품 초기 등록이 완료되었습니다." << endl << endl;
	return;
}

// public
ProductDetails::ProductDetails()
{
	init_details();
}

string ProductDetails::get_product_name() const
{
	return product_name;
}

unsigned int ProductDetails::get_main_price() const
{
	return main_price;
}
	
MainCategory ProductDetails::get_category() const
{
	return main_category;
}

// DetailsInterface Interface
void ProductDetails::modify_details()
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
			cout << "product_name을 변경합니다." << endl;
			cout << "변경할 product_name를 입력하세요 : ";
			cin >> product_name;
			cout << "product_name이 " << product_name << "로 변경되었습니다." << endl;
			break;
		case 2:
			cout << "main_price를 변경합니다." << endl;
			cout << "변경할 main_price를 입력하세요 : ";
			cin >> main_price;
			cout << "main_price가 " << main_price << "로 변경되었습니다." << endl;
			break;
		case 3:
			cout << "category를 변경합니다." << endl;
			main_category = category_manager.choose_main_category();
			break;
		case 4:
			extension_effective_time();
			cout << "유효기간이" << effective_date->tm_year << "년 " << effective_date->tm_mon << "월 "
				<< effective_date->tm_mday << "일로 변경되었습니다." << endl;
		default:
			is_break_while = true;
			break;
		}
		cout << endl;
		if (is_break_while)
		{
			cout << "내용 수정을 종료합니다." << endl;
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
		<< posted_date->tm_mday << "일" << endl;
	cout << "effective_date : " << effective_date->tm_year << "년 " << effective_date->tm_mon << "월 "
		<< effective_date->tm_mday << "일" << endl;
	cout << "category : " << category_manager.main_category_to_string(main_category) << endl;
	return;
}