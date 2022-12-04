#include "Coupon.h"
using namespace std;

class Coupon
{
private:
	unsigned int coupon_id;
	unsigned int product_id;
	unsigned int discounting;	// ����� �� �ݾ����� ǥ��
	tm* expiration_date;

public:
	Coupon() = default;

	// ���ο� ������ �� ��
	Coupon(const unsigned int& p_id, const unsigned int& discount) : product_id(p_id), discounting(discount)
	{
		static unsigned int coupon_index = 1;
		coupon_id = coupon_index;
		coupon_index++;

		time_t temp_time_t = time(0);
		temp_time_t += 2592000;	// 30�Ͽ� �ش��ϴ� ��
		expiration_date = localtime(&temp_time_t);
	}

	~Coupon() = default;

	unsigned int get_coupon_id() const
	{
		return coupon_id;
	}

	unsigned int get_product_id() const
	{
		return product_id;
	}

	void display_coupon_information() const
	{
		std::cout << "coupon_id : " << coupon_id << std::endl;
		std::cout << "product_id : " << product_id << std::endl;
		std::cout << "discounting : " << discounting << std::endl;
		cout << "expiration_date : " << expiration_date->tm_year << "�� " << expiration_date->tm_mon << "�� "
			<< expiration_date->tm_mday << "��\n";
		return;
	}

	unsigned int get_discounting() const
	{
		return discounting;
	}
};