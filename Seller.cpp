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
	cout << "return_address 주소 변경입니다." << endl;
	cout << "변경할 주소를 입력하세요." << endl;
	Address new_address;
	new_address.init_address();
	return_address = new_address;
	cout << "return_address 변경이 완료되었습니다." << endl;
	return;
}

void Seller::modify_source_address()
{
	std::cout << "source_address 주소 변경입니다." << endl;
	std::cout << "변경할 주소를 입력하세요." << endl;
	Address new_address;
	new_address.init_address();
	source_address = new_address;
	std::cout << "source_address 변경이 완료되었습니다." << endl;
	return;
}