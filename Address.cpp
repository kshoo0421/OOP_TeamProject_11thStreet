#include "Address.h"
using namespace std;
class Address
{
private:
	std::string address_name;
	std::string name;
	std::string address;
	std::string phone_number;
public:
	Address() = default;

	~Address() = default;

	void init_address()
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

	std::string get_address_name() const
	{
		return address_name;
	}

	std::string get_name() const
	{
		return name;
	}

	std::string get_address() const
	{
		return address;
	}

	std::string get_phone_number() const
	{
		return phone_number;
	}
};