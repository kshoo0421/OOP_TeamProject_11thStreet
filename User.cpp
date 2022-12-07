#include "User.h"
using namespace std;

void User::print_options()
{
	cout << "변경할 항목을 선택하세요.(숫자로 입력)" << endl;
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
	if (email == input_email) return true;	// 같으면 true
	else return false;	// 다르면 false
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
			cout << "user_id를 변경합니다." << endl;
			cout << "변경할 user_id를 입력하세요 : ";
			cin >> user_id;
			cout << "user_id가 " << user_id << "로 변경되었습니다." << endl;
			break;

		case 2:
			cout << "email을 변경합니다." << endl;
			cin >> email;
			cout << "email이 " << email << "로 변경되었습니다." << endl;
			break;

		case 3:
			cout << "password를 변경합니다." << endl;
			cin >> password;
			cout << "password가 " << password << "로 변경되었습니다." << endl;
			break;

		case 4:
			cout << "user_name을 변경합니다." << endl;
			cin >> user_name;
			cout << "user_names이 " << user_name << "로 변경되었습니다." << endl;
			break;

		case 5:
			cout << "balance를 변경합니다." << endl;
			cin >> balance;
			cout << "balance가 " << balance << "로 변경되었습니다." << endl;
			break;
		default:
			break_while = true;
			break;
		}
		if (break_while) break;
		cout << endl;
	}
	cout << "설정 변경을 종료합니다." << endl;
}