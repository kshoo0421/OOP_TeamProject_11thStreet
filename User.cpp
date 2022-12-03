#include "User.h"

class User
{
protected:
	unsigned int user_id;
	std::string email;
	std::string password;
	std::string user_name;
	unsigned int balance;
public:
	User()
	{

	}

	~User() = default;

	std::string get_user_name() const
	{
		return user_name ;
	}

	unsigned int get_id() const
	{
		return user_id ;
	}

	bool compare_email(const std::string& input_email) const
	{
		if (true)
		{

		}
	}

	bool compare_password(const std::string& input_password) const
	{
		if (true)
		{

		}
	}

	void display_account_information() const
	{
		cout<<
	}

	void modify_account_information()
	{

	}
};