#include "Seller.h"
using namespace std;

string Seller::get_return_address() const
{
	return return_address.get_address();
}

string Seller::get_source_address() const
{
	return source_address.get_address();
}

void Seller::modify_return_address()
{
	cout << "return_address �ּ� �����Դϴ�." << endl;
	cout << "������ �ּҸ� �Է��ϼ���." << endl;
	Address new_address;
	new_address.init_address();
	return_address = new_address;
	cout << "return_address ������ �Ϸ�Ǿ����ϴ�." << endl;
	return;
}

void Seller::modify_source_address()
{
	std::cout << "source_address �ּ� �����Դϴ�." << endl;
	std::cout << "������ �ּҸ� �Է��ϼ���." << endl;
	Address new_address;
	new_address.init_address();
	source_address = new_address;
	std::cout << "source_address ������ �Ϸ�Ǿ����ϴ�." << endl;
	return;
}