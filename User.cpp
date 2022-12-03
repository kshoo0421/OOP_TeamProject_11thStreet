#include "User.h"
using namespace std;

class User
{
protected:
	unsigned int user_id;
	std::string email;
	std::string password;
	std::string user_name;
	unsigned int balance;

	void print_options()
	{
		cout << "������ �׸��� �����ϼ���.(���ڷ� �Է�)\n";
		cout << "1. user_id\n";
		cout << "2. email\n";
		cout << "3. password\n";
		cout << "4. user_name\n";
		cout << "5. balance\n";
		return;
	}

public:
	User() = default;
	~User() = default;

	std::string get_user_name() const
	{
		return user_name;
	}

	unsigned int get_id() const
	{
		return user_id;
	}

	bool compare_email(const std::string& input_email) const
	{
		if (email == input_email) return true;	// ������ true
		else return false;	// �ٸ��� false
	}

	bool compare_password(const std::string& input_password) const
	{
		if (password == input_password) return true;
		else return false;
	}

	void display_account_information() const
	{
		cout << "user_id : " << user_id << endl;
		cout << "email : " << email << endl;
		cout << "password : " << password << endl;
		cout << "user_name : " << user_name << endl;
		cout << "balance : " << balance << endl << endl;
		return;
	}

	void modify_account_information()
	{
		bool break_while = false;
		int option_num;
		while (1)
		{
			print_options();
			cin >> option_num;
			switch (option_num)
			{
			case 1:
				cout << "user_id�� �����մϴ�.\n";
				cout << "������ user_id�� �Է��ϼ��� : ";
				cin >> user_id;
				cout << "user_id�� " << user_id << "�� ����Ǿ����ϴ�.\n";
				break;

			case 2:
				cout << "email�� �����մϴ�.\n";
				cin >> email;
				cout << "email�� " << email << "�� ����Ǿ����ϴ�.\n";
				break;

			case 3:
				cout << "password�� �����մϴ�.\n";
				cin >> password;
				cout << "password�� " << password << "�� ����Ǿ����ϴ�.\n";
				break;

			case 4:
				cout << "user_name�� �����մϴ�.\n";
				cin >> user_name;
				cout << "user_names�� " << user_name << "�� ����Ǿ����ϴ�.\n";
				break;

			case 5:
				cout << "balance�� �����մϴ�.\n";
				cin >> balance;
				cout << "balance�� " << balance << "�� ����Ǿ����ϴ�.\n";
				break;
			default:
				break_while = true;
				break;
			}
			if (break_while) break;
			cout << endl;
		}
		cout << "���� ������ �����մϴ�.\n";
	}
};