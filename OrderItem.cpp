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
	cout << "�ֹ��Ͻ� ������ �Է����ּ���" << endl;
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
	cout << "��ǰ �̸� :" << product_name << endl;
	cout << "�ֹ� ���� :" << quantity << endl;
	cout << "��ǰ �� ���� :" << total_price << endl;
	return;
}