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
		cout << "�ֹ��Ͻ� ������ �Է����ּ���" << endl;
		cin >> quantity;
		return;
	}

	/*
	void set_couponed_price()
	{
		cout << "������ ���� ������ �Է����ּ���" << endl;
		cin >> couponed_price;
	}
	*/

	void set_price()
	{
		cout << "��ǰ�� ������ �Է����ּ���" << endl;
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

	unsigned int get_couponed_price() const // ����
	{
		return couponed_price;
	}
	*/

	void display_order_item() const
	{
		cout << "�ֹ� �ɼ� :" << option_string << endl;
		cout << "�ֹ� ���� :" << quantity << endl;
		cout << "��ǰ ���� :" << price << endl;

	}

	
};