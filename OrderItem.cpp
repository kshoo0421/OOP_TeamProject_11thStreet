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
		cout << "주문하실 수량을 입력해주세요" << endl;
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
		cout << "제품 이름 :" << product.get_product_name() << endl;
		cout << "주문 수량 :" << quantity << endl;
		cout << "제품 총 가격 :" << total_price << endl;
		return;
	}
};