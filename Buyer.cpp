#include "Buyer.h"

class Buyer : public User
{
private:
	Address addresses[3];
	std::list<unsigned int> IndexList;
	std::vector<Coupon> its_coupon_list;
public:
	void add_new_address()
	{

	}

	void delete_address()
	{

	}

	void display_addresses() const
	{

	}

	std::string get_address(const unsigned int& order_id) const
	{
		return addresses[order_id].get_address();
	}

	void add_order_list(const unsigned int& order_id) const
	{

	}

	void add_coupon(const Coupon& new_coupon) const
	{

	}

	void delete_coupon(const unsigned int& address_number) const
	{

	}
};