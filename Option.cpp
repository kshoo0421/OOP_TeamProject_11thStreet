#include "Option.h"

class Option
{
private:
	std::string option_name;
	std::vector<OptionDetails> option_detail_list;
public:
	Option()
	{

	}

	~Option() = default;

	void delete_option()
	{

	}

	void add_option()
	{
	
	}

	void display_option()
	{
		std::cout << option_name << std::endl;
		std::vector<OptionDetails>::iterator iterator = option_detail_list.begin();
		for (; iterator != option_detail_list.end(); iterator++)
		{
			std::cout << "option_value : " << iterator->get_option_value() << std::endl;
			std::cout << "additional_price : " << iterator->get_additional_price() << std::endl;
			std::cout << "get_option_value : " << iterator->get_option_value() << std::endl << std::endl;
		}
	}
};