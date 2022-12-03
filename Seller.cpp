#include "Seller.h"

class Seller : public User
{
private:
	Address source_address;	// 물류창고
	Address return_address;	// 환불쳐
	std::vector<unsigned int> its_product_index_list;

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
		std::cout << "return_address 주소 변경입니다." << std::endl;
		std::cout << "변경할 주소를 입력하세요." << std::endl;
		Address new_address;
		new_address.init_address();
		return_address = new_address;
		std::cout << "return_address 변경이 완료되었습니다." << std::endl;
		return;
	}

	void modify_source_address()
	{
		std::cout << "source_address 주소 변경입니다." << std::endl;
		std::cout << "변경할 주소를 입력하세요." << std::endl;
		Address new_address;
		new_address.init_address();
		source_address = new_address;
		std::cout << "source_address 변경이 완료되었습니다." << std::endl;
		return;
	}
};