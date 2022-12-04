#include "Coupon.h"

class Coupon
{
private:
	unsigned int coupon_id;
	unsigned int product_id;
	unsigned int discounting;	// 등록할 때 금액으로 표시
	time_t expiration_date;

public:
	Coupon()
	{
		static unsigned int coupon_index = 1;
		coupon_id = coupon_index;
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
		std::cout << "expiration_date : " << expiration_date << std::endl;
	}

	unsigned int get_discounting() const
	{
		return discounting;
	}
};