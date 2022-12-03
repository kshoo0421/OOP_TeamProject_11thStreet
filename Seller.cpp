#include "Seller.h"

class Seller : public User
{
private:
	Address source_address;	// ����â��
	Address return_address;	// ȯ����
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
		std::cout << "return_address �ּ� �����Դϴ�." << std::endl;
		std::cout << "������ �ּҸ� �Է��ϼ���." << std::endl;
		Address new_address;
		new_address.init_address();
		return_address = new_address;
		std::cout << "return_address ������ �Ϸ�Ǿ����ϴ�." << std::endl;
		return;
	}

	void modify_source_address()
	{
		std::cout << "source_address �ּ� �����Դϴ�." << std::endl;
		std::cout << "������ �ּҸ� �Է��ϼ���." << std::endl;
		Address new_address;
		new_address.init_address();
		source_address = new_address;
		std::cout << "source_address ������ �Ϸ�Ǿ����ϴ�." << std::endl;
		return;
	}
};