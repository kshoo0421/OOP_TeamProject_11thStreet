#include "User.h"
using namespace std;

void User::print_options()
{
	cout << "������ �׸��� �����ϼ���.(���ڷ� �Է�)" << endl;
	cout << "1. user_id" << endl;
	cout << "2. email" << endl;
	cout << "3. password" << endl;
	cout << "4. user_name" << endl;
	cout << "5. balance" << endl;
	return;
}

void User::set_id(const unsigned int& input)
{
	user_id = input;
	return;
}

string User::get_user_name() const
{
	return user_name;
}

unsigned int User::get_id() const
{
	return user_id;
}

bool User::compare_email(const string& input_email) const
{
	if (email == input_email) return true;	// ������ true
	else return false;	// �ٸ��� false
}

bool User::compare_password(const string& input_password) const
{
	if (password == input_password) return true;
	else return false;
}

void User::display_account_information() const
{
	cout << "user_id : " << user_id << endl;
	cout << "email : " << email << endl;
	cout << "password : " << password << endl;
	cout << "user_name : " << user_name << endl;
	cout << "balance : " << balance << endl << endl;
	return;
}

void User::modify_account_information()
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
			cout << "user_id�� �����մϴ�." << endl;
			cout << "������ user_id�� �Է��ϼ��� : ";
			cin >> user_id;
			cout << "user_id�� " << user_id << "�� ����Ǿ����ϴ�." << endl;
			break;

		case 2:
			cout << "email�� �����մϴ�." << endl;
			cin >> email;
			cout << "email�� " << email << "�� ����Ǿ����ϴ�." << endl;
			break;

		case 3:
			cout << "password�� �����մϴ�." << endl;
			cin >> password;
			cout << "password�� " << password << "�� ����Ǿ����ϴ�." << endl;
			break;

		case 4:
			cout << "user_name�� �����մϴ�." << endl;
			cin >> user_name;
			cout << "user_names�� " << user_name << "�� ����Ǿ����ϴ�." << endl;
			break;

		case 5:
			cout << "balance�� �����մϴ�." << endl;
			cin >> balance;
			cout << "balance�� " << balance << "�� ����Ǿ����ϴ�." << endl;
			break;
		default:
			break_while = true;
			break;
		}
		if (break_while) break;
		cout << endl;
	}
	cout << "���� ������ �����մϴ�." << endl;
}