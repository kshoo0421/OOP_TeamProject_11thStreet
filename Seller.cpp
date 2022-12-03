#include "Seller.h"

class Seller : public User
{
private:
	Address source_address;
	Address return_address;
	std::list<unsigned int> its_product_index_list;

public:
	std::string get_return_address() const
	{
		return return_address.get_address();
	}

	std::string get_source_address() const
	{
		return source_address.get_address();
	}

	void modify_return_address()
	{

	}

	void modify_source_address()
	{

	}
};