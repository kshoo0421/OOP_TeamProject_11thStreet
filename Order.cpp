#include "Order.h"
using namespace std;

void Order::clear_order_item_list()
{
	order_item_list.clear();
	return;
}


// Buyer- 
void Order::add_order_item(const OrderItem& new_item) 
{
	order_item_list.push_back(new_item);
	cout << order_item_list.size() << "개의 제품이 장바구니에 담겨있습니다." << endl;
	return;
}

void Order::display_order_details() const
{
	if (order_item_list.size() == 0)
	{
		cout << "주문하신 상품이 없습니다." << endl;
		return;
	}
	for (int i = 0; i < order_item_list.size(); i++)
	{
		cout << i + 1 << "번 상품" << endl;
		order_item_list[i].display_order_item();
	}
	return;
}

void Order::display_order() const
{
	display_order_details();
	time_t temp_time_t = time(0);
	tm* order_time = localtime(&temp_time_t);
	cout << "배송지 주소" << buyer_address.get_address_name() << endl;
	cout << "주문시간 :" << 1900 + order_time->tm_year - 100 << "." << order_time->tm_mon << "." <<
		order_time->tm_mday << endl;
	temp_time_t += 259200;
	order_time = localtime(&temp_time_t);

	cout << "예상 배송시간 :" << order_time->tm_year - 100 << "." << order_time->tm_mon << "." <<
		order_time->tm_mday << endl;

	cout << "제품 금액:" << total_product_price << endl;
	cout << "총 금액:" << total_price << endl;
	return;
}

void Order::set_buyer_address(const Address& buyer_address_in) 
{
	buyer_address = buyer_address_in;
	return;
}

void Order::set_delivery_price() 
{
	delivery_fee = (total_product_price < 10000) ? 3000 : (total_product_price < 30000 ? 2500 : 0);
	return;
}

void Order::set_total_price() 
{
	total_price = total_product_price + delivery_fee;
	return;
}

void Order::set_total_product_price() 
{
	total_product_price = 0;
	vector<OrderItem>::iterator iterator = order_item_list.begin();
	for (; iterator < order_item_list.end(); iterator++)
		total_product_price += iterator->get_price() * iterator->get_quantity();
}

// Seller- 
void Order::set_status()
{
	int i = 0;
	cout << "주문 진행 상태를 입력해주세요" << endl;
	cout << "1. order_requested" << endl;
	cout << "2. products_prepared" << endl;
	cout << "3. products_on_delivery" << endl;
	cout << "4. products_arriving" << endl;
	cin >> i;
	status = Status(i - 1);
	return;
}

void Order::set_actual_arrival_date() 
{
	cout << "실제 배송기간을 입력해주세요" << endl;
	cin >> actual_arrival_date;
	return;
}

// Search-
unsigned int Order::get_order_id() const
{
	return order_id;
}