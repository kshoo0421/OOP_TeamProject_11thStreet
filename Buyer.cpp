#include "Buyer.h"
using namespace std;

void Buyer::add_new_address()
{
	static int count = 0;
	if (count == 3)
	{
		cout << "�̹� �ּҰ� �� ���� �߰��� �� �����ϴ�.\n";
		return;
	}
	Address new_address;
	new_address.init_address();
	addresses.emplace_back(new_address);
	count++;
	cout << "�ּҰ� �߰��Ǿ����ϴ�.\n";
	return;
}

void Buyer::delete_address()
{
	int input;
	cout << "������ �ּҸ� �����ϼ���\n";
	vector<Address>::iterator iterator = addresses.begin();
	for (; iterator < addresses.end(); iterator++)
	{
		cout << "- " << iterator->get_address_name() << " : " << iterator->get_address_name() << endl;
	}
	cin >> input;
	input -= 1;
	if (input <= addresses.size())
	{
		addresses.erase(addresses.begin() + input);
		cout << "�ּҰ� �����Ǿ����ϴ�.\n";
	}
	cout << "�ּ� ������ �����մϴ�.\n";
	return;
}

void Buyer::display_addresses() const
{
	for (int i = 0; i < addresses.size(); i++)
	{
		cout << i + 1 << "��° �ּ�" << endl;
		cout << "address_name : " << addresses[i].get_address_name() << endl;
		cout << "name : " << addresses[i].get_name() << endl;
		cout << "address : " << addresses[i].get_address() << endl;
		cout << "phone_number : " << addresses[i].get_phone_number() << endl << endl;
	}
	cout << "�ּ� ��� ����" << endl;
	return;
}

Address Buyer::get_full_address(const unsigned int& order_id) const
{
	return addresses[order_id];
}

string Buyer::get_address(const unsigned int& order_id) const
{
	return addresses[order_id].get_address();
}

void Buyer::add_order_list(const unsigned int& order_id)
{
	its_order_index_list.emplace_back(order_id);
	return;
}