#include "OrderItem.h"
using namespace std;

OrderItem::OrderItem(const string& input) : product_name(input) { };
	
void OrderItem::set_product_name(const string& input)
{
	product_name = input;
	return;
}

void OrderItem::set_quantity()
{
	cout << "주문하실 수량을 입력해주세요" << endl;
	cin >> quantity;
	return;
}

void OrderItem::set_price(const unsigned int& price)
{
	total_price = price * quantity;
	return;
}

unsigned int OrderItem::get_quantity() const
{
	return quantity;
}
	
unsigned int OrderItem::get_price() const
{
	return total_price;
}

string OrderItem::get_product_name() const
{
	return product_name;
}

void OrderItem::display_order_item() const
{
	cout << "제품 이름 :" << product_name << endl;
	cout << "주문 수량 :" << quantity << endl;
	cout << "제품 총 가격 :" << total_price << endl;
	return;
}