#include "OrderItem.h"
using namespace std;

class OrderItem
{
private:
	std::string option_string;
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

	void set_price()
	{
		cout << "제품의 가격을 입력해주세요" << endl;
		cin >> price;
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
		cout << "주문 옵션 :" << option_string << endl;
		cout << "주문 수량 :" << quantity << endl;
		cout << "제품 가격 :" << price << endl;

	}

	
};