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
				cout << "항목 삭제가 완료되었습니다." << endl;
				return;
			}
		}
		cout << "삭제할 항목을 찾지 못했습니다." << endl;

	}

	void add_option_details(const OptionDetails& option_detail)
	{
		vector<OptionDetails>::iterator iterator = option_detail_list.begin();
		for (; iterator < option_detail_list.end(); iterator++)
		{
			if (iterator->get_option_value() == option_detail.get_option_value())
			{
				cout << "이미 존재하는 추가 항목입니다." << endl;
				return;
			}
		}
		option_detail_list.emplace_back(option_detail);
		cout << "항목이 추가되었습니다." << endl;
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