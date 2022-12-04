#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "OptionDetails.h"

class Option
{
private :
	std::string option_name;
	std::vector<OptionDetails> option_detail_list;
public :
	Option();
	~Option();
	void display_option();
};