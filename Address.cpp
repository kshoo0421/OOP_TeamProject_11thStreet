#include "Address.h"
using namespace std;

void Address::init_address()
{
	cout << "address_name�� �Է��ϼ���." << endl;
	cin >> address_name;
	cout << "name�� �Է��ϼ���" << endl;
	cin >> name;
	cout << "address�� �Է��ϼ���" << endl;
	cin >> address;
	cout << "phone_number�� �Է��ϼ���" << endl;
	cin >> phone_number;
}

string Address::get_address_name() const
{
	return address_name;
}

string Address::get_name() const
{
	return name;
}

string Address::get_address() const
{
	return address;
}

string Address::get_phone_number() const
{
	return phone_number;
}