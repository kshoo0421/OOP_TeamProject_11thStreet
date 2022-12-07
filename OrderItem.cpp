#include "OrderItem.h"
using namespace std;

class OrderItem
{
private:
	std::string product_name;
	unsigned int quantity;
	unsigned int price;
	unsigned int applied_coupon_id;
	unsigned int couponed_price;
public:
	OrderItem()
	{

	}

	~OrderItem()
	{

	}

	void set_quantity()
	{
		cout << "주문하실 수량을 입력해주세요" << endl;
		cin >> quantity;
		return;
	}

	/*
	void set_couponed_price()
	{
		cout << "쿠폰의 할인 가격을 입력해주세요" << endl;
		cin >> couponed_price;
	}
	*/

	void set_product_name(const std::string name)
	{
		product_name = name;
		return;
	}

	void set_price(const unsigned int & product_price)
	{
		price = product_price;
		return;
	}

	unsigned int get_quantity() const
	{
		return quantity;
	}
	
	unsigned int get_price() const
	{
		return price;
	}


	/*
	unsigned int get_applied_coupon_id() const
	{
		return applied_coupon_id;
	}

	unsigned int get_couponed_price() const // 변경
	{
		return couponed_price;
	}
	*/

	void display_order_item() const
	{
		cout << "제품 이름 :" << option_string << endl;
		cout << "주문 수량 :" << quantity << endl;
		cout << "제품 가격 :" << price << endl;

	}

	
};