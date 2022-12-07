#include "OrderItem.h"
using namespace std;

class OrderItem
{
private:
	Product product;
	unsigned int quantity;
	unsigned int total_price;
public:
	OrderItem(const Product& input) : product(input)
	{ }
	
	void set_product(const Product& input)
	{
		product = input;
		return;
	}

	void set_quantity()
	{
		cout << "�ֹ��Ͻ� ������ �Է����ּ���" << endl;
		cin >> quantity;
		return;
	}

	void set_price()
	{
		total_price = product.get_main_price() * quantity;
		return;
	}

	unsigned int get_quantity() const
	{
		return quantity;
	}
	
	unsigned int get_price() const
	{
		return total_price;
	}

	std::string get_product_name() const
	{
		return product.get_product_name();
	}

	void display_order_item() const
	{
		cout << "��ǰ �̸� :" << product.get_product_name() << endl;
		cout << "�ֹ� ���� :" << quantity << endl;
		cout << "��ǰ �� ���� :" << total_price << endl;
		return;
	}
};