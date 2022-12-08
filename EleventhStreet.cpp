#include "EleventhStreet.h"

void EleventhStreet::use_eleventh_street()
{
	int input;
	while (is_logined == false)
	{
		log_in();
		if (is_logined == false)
		{
			cout << endl << "로그인을 종료하시겠습니까?(1 : 예, 그 외 : 아니요)" << endl;
			cin >> input;
			if (input == 1) break;
		}
	}
	if (is_logined)
	{
		if (is_user_seller) use_seller_interface();
		else use_buyer_interface();
	}
}

void EleventhStreet::use_seller_interface()
{
	bool is_break = false;
	int input;
	while (1)
	{
		display_seller_interface();
		cin >> input;
		switch (input)
		{
		case 1: 
			register_product();
			break;
		case 2: 
			my_information();
			break;
		case 3:
			log_out();
			is_break = true;
			cout << "로그아웃합니다." << endl;
			break;
		default :
			is_break = true;
			cout << "이용을 종료합니다." << endl;
			break;
		}
		if (is_break) break;
	}
}

void EleventhStreet::display_seller_interface()
{
	cout << endl << "이용 가능 목록" << endl;
	cout << "1. 상품 등록하기" << endl;
	cout << "2. 판매자 정보 보기" << endl;
	cout << "3. 로그아웃 하기" << endl << endl;
	return;
}

void EleventhStreet::use_buyer_interface()
{
	bool is_break = false;
	int input;
	while (1)
	{
		display_buyer_interface();
		cin >> input;
		switch (input)
		{
		case 1:
			go_shopping();
			break;
		case 2:
			look_up_my_order_list();
			break;
		case 3:
			my_information();
			break;
		case 4:
			log_out();
			is_break = true;
			cout << "로그아웃 되었습니다." << endl;
			break;
		default:
			break;
		}
		if (is_break) break;
	}
	return;
}

void EleventhStreet::display_shopping_options()
{
	cout << endl << "쇼핑하기" << endl;
	cout << "1. 전체 상품 보기" << endl;
	cout << "2. 상품 장바구니 담기" << endl;
	cout << "3. 주문하기" << endl;
	return;
}

void EleventhStreet::display_buyer_interface()
{
	cout << endl << "이용 가능 목록" << endl;
	cout << "1. 쇼핑하기" << endl;
	cout << "2. 장바구니 보기" << endl;
	cout << "3. 내 정보 보기" << endl;
	cout << "4. 로그아웃" << endl << endl;
	return;
}

void EleventhStreet::log_in()
{
	int input;
	cout << "로그인할 계정의 종류를 선택하세요." << endl;
	cout << "1. 구매자 계정" << endl;
	cout << "2. 판매자 계정" << endl;
	cin >> input;
	if (input == 1)
	{
		cur_user = buyer_log_in();
		cout << "로그인이 완료되었습니다." << endl;
	}

	else if (input == 2)
	{
		cur_user = seller_log_in();
		cout << "로그인이 완료되었습니다." << endl;
	}
	else
	{
		cout << "선택되지 않았습니다." << endl;
		cout << "로그인을 종료합니다." << endl;
	}
	return;
}

void EleventhStreet::log_out()
{
	is_logined = false;
	is_user_seller = false;
	return;
}

Seller& EleventhStreet::seller_log_in()
{
	int input;
	cout << "로그인할 계정을 선택하세요." << endl;
	cout << "1. 판매자 1" << endl;
	cout << "2. 판매자 2" << endl;
	cout << "3. 판매자 3" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		is_logined = true;
		is_user_seller = true;
		cout << "로그인에 성공했습니다. 계정 : 판매자1" << endl << endl;
		return seller_list[0];
	case 2:
		is_logined = true;
		is_user_seller = true;
		cout << "로그인에 성공했습니다. 계정 : 판매자2" << endl << endl;
		return seller_list[1];
	case 3:
		is_logined = true;
		is_user_seller = true;
		cout << "로그인에 성공했습니다. 계정 : 판매자3" << endl << endl;
		return seller_list[2];
	default: break;
	}
	cout << "로그인에 실패했습니다." << endl;
	return seller_log_in();
}

Buyer& EleventhStreet::buyer_log_in()
{
	int input;
	cout << "로그인할 계정을 선택하세요." << endl;
	cout << "1. 구매자 1" << endl;
	cout << "2. 구매자 2" << endl;
	cout << "3. 구매자 3" << endl;
	cin >> input;
	switch (input)
	{
	case 1:
		is_logined = true;
		cout << "로그인에 성공했습니다. 계정 : 구매자1" << endl << endl;
		return buyer_list[0];
	case 2:
		is_logined = true;
		cout << "로그인에 성공했습니다. 계정 : 구매자2" << endl << endl;
		return buyer_list[1];
	case 3:
		is_logined = true;
		cout << "로그인에 성공했습니다. 계정 : 구매자3" << endl << endl;
		return buyer_list[2];
	default: break;
	}
	cout << "로그인에 실패했습니다." << endl;
	return buyer_log_in();
}

void EleventhStreet::set_ids_and_orders()
{
	for (int i = 0; i < 3; i++)
	{
		seller_list[i].set_id(1001 + i);
		buyer_list[i].set_id(2001 + i);
		order_list.emplace_back(Order((unsigned int)3001 + i));
	}
	return;
}

// SellerMallInterface
void EleventhStreet::display_categories() const
{
	category_manager.display_categories();
	return;
}


void EleventhStreet::add_new_product(const Product& new_product)
{
	product_manager.add_product(new_product);
	return;
}

Order EleventhStreet::get_order(const unsigned int& order_id) const
{
	return order_list[order_id];
}

Product EleventhStreet::register_new_product() const
{
	Product new_product(cur_user.get_id());
	return new_product;
}

// SellerMallInterface-SellerInterface
void EleventhStreet::register_product()
{
	int input;
	while (1)
	{
		cout << "상품 등록" << endl;
		cout << "1. 새 상품 등록하기" << endl;
		cout << "2. 이미 등록된 상품 확인하기" << endl;
		cout << "3. 등록된 상품 삭제하기" << endl;
		cout << "그 외 : 등록 종료" << endl << endl;
		cin >> input;
		switch (input)
		{
		case 1 :
			add_new_product(register_new_product());
			break;
		case 2 :
			product_manager.display_products_by_seller_id(cur_user.get_id());
			break;
		case 3 :
			product_manager.delete_product();
			break;
		default :
			cout << "상품 등록을 종료합니다." << endl;
			return;
		}
	}
}

// BuyerMallInterface
void EleventhStreet::display_all_products()
{
	product_manager.display_products_in_category();
	return;
}

void EleventhStreet::request_order(Order new_order) 
{
	int input = 0;
	cout << "현재 장바구니 항목입니다." << endl;
	order_list[cur_user_index].set_total_product_price();
	order_list[cur_user_index].set_delivery_price();
	order_list[cur_user_index].set_total_price();
	order_list[cur_user_index].display_order();
	cout << "결제하시겠습니까?(1 : 예, 그 외 : 아니요) : ";
	cin >> input;
	if (input == 1)
	{
		cout << "결제가 완료되었습니다." << endl;
		order_list[cur_user_index].clear_order_item_list();
	}
	else
	{
		cout << "결제가 취소되었습니다." << endl;
	}
	return;
}

void EleventhStreet::add_new_order() // 매개변수 추가
{
	Product temp_product = product_manager.get_product();
	OrderItem temp_item(temp_product.get_product_name());
	temp_item.set_quantity();
	temp_item.set_price(temp_product.get_main_price());
	order_list[cur_user_index].add_order_item(temp_item);
	cout << "선택하신 제품 :" << temp_item.get_product_name() << endl;
	cout << "제품 가격 : " << temp_item.get_price() << endl;
	cout << "제품 갯수 : " << temp_item.get_quantity() << endl;
	cout << "제품 총 가격 :" << temp_item.get_price() * temp_item.get_quantity() << endl << endl;
	return;
}

void EleventhStreet::display_orders_by_buyer_id() const
{
	cout << "주문 상품 내역" << endl;
	order_list[cur_user_index].display_order();
	return;
}

Order EleventhStreet::get_order()
{
	return order_list[cur_user_index];
}

// BuyerMallInterface - BuyerInterface
void EleventhStreet::go_shopping()
{
	bool is_break = false;
	int input;
	while (1)
	{
		display_shopping_options();
		cin >> input;
		switch (input)
		{
		case 1:
			display_all_products();
			break;
		case 2:
			add_new_order();
			break;
		case 3:
			request_order(order_list[cur_user_index]);
			break;
		default:
			is_break = true;
			break;
		}
		if (is_break) break;
	}
	cout << "쇼핑하기를 종료합니다.." << endl;
	return;
}

void EleventhStreet::look_up_my_order_list() const
{
	cout << "내 장바구니 목록" << endl;
	cout << "구매자 :" << buyer_list[cur_user_index].get_user_name() << endl;
	order_list[cur_user_index].display_order_details();
	return;
}

void EleventhStreet::my_information()
{
	int input;
	while (1)
	{
		cout << "내 정보" << endl;
		cout << "1. 내 정보 보기" << endl;
		cout << "2. 내 정보 수정하기" << endl;
		cout << "입력(숫자) : ";
		cin >> input;
		switch (input)
		{
		case 1: 
			cur_user.display_account_information();
			break;
		case 2: 
			cur_user.modify_account_information();
			break;
		default :
			cout << "내 정보를 종료합니다." << endl << endl;
			return;
		}
	}
	return;
}

EleventhStreet::EleventhStreet()
{
	int input;
	set_ids_and_orders();
	while (1)
	{
		use_eleventh_street();
		cout << "11번가를 종료하시겠습니까?(예 : 1, 그 외 숫자 : 아니요)" ;
		cin >> input;
		if (input == 1) break;
	}
	cout << "11번가를 종료합니다." << endl;
}