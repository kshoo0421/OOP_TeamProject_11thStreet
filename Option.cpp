#include "Option.h"
using namespace std;

class Option
{
private:
	string option_name;
	vector<OptionDetails> option_detail_list;
public:
	Option() = default;

	~Option() = default;

	void delete_option_details(const OptionDetails& option_detail)
	{
		vector<OptionDetails>::iterator iterator = option_detail_list.begin();
		for (; iterator < option_detail_list.end(); iterator++)
		{
			if (iterator->get_option_value() == option_detail.get_option_value())
			{
				option_detail_list.erase(iterator);
				cout << "�׸� ������ �Ϸ�Ǿ����ϴ�." << endl;
				return;
			}
		}
		cout << "������ �׸��� ã�� ���߽��ϴ�." << endl;

	}

	void add_option_details(const OptionDetails& option_detail)
	{
		vector<OptionDetails>::iterator iterator = option_detail_list.begin();
		for (; iterator < option_detail_list.end(); iterator++)
		{
			if (iterator->get_option_value() == option_detail.get_option_value())
			{
				cout << "�̹� �����ϴ� �߰� �׸��Դϴ�." << endl;
				return;
			}
		}
		option_detail_list.emplace_back(option_detail);
		cout << "�׸��� �߰��Ǿ����ϴ�." << endl;
		return;
	}

	void display_option()
	{
		cout << option_name << endl;
		vector<OptionDetails>::iterator iterator = option_detail_list.begin();
		for (; iterator != option_detail_list.end(); iterator++)
		{
			cout << "option_value : " << iterator->get_option_value() << endl;
			cout << "additional_price : " << iterator->get_additional_price() << endl;
			cout << "get_option_value : " << iterator->get_option_value() << endl << endl;
		}
	}
};