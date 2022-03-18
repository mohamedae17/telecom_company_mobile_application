#include <iostream>
#include <string>
using namespace std;

int number_of_user = 1;
int user_number;

struct user {
	string id, email, name, password, number, address, number2, number3;
};
struct sign_data {
	string  name, password;
};
struct charge{
	float number[3]; //Each user has a minimum of 3 fonts
};
user arr[100];
charge balance[100];
charge package_type[100];

void sign_message();
void sign_in();
void sign_up();
void error_message();
void the_menu(int number_user);
void add_number();
void package();
void call();
void message();
void balance_recharge();
void transfer();

int main(){
	arr[0].name = "mohamed";
	arr[0].password = "123";
	arr[0].number = "0115";
	package_type[0].number[0] = 10;
	balance[0].number[0] = 10;
	cout << "Welcome to telecom company mobile application " << endl;
	sign_message();
	system("pause");
	return 0;
}

void sign_message(){
	string number_of_operation;
	cout << "What do you want ?" << endl;
	cout << "1.Sign up \t 2.Sign in" << endl;
	cin >> number_of_operation;
	if (number_of_operation == "1"){
		sign_up();
	}
	else if (number_of_operation == "2"){
		sign_in();
	}
	else {
		error_message();
		sign_message();
	}
}
void sign_in(){
	sign_data sign;
	int name_correct = 0, password_corect = 0;

	cout << "Enter Your name" << endl;
	cin >> sign.name;
	cout << "Enter Your user password" << endl;
	cin >> sign.password;
	//forLoop to search about name and password in array
	for (user_number = 0; user_number < 100; user_number++){
		//Check if name is correct
		if (sign.name == arr[user_number].name){
			//check if password is correct
			if (sign.password == arr[user_number].password){
				password_corect = 1;
				cout << "welcome " << sign.name << " , your login has been successful" << endl;

				the_menu(user_number);

			}
			name_correct = 1;
		}
	}
	//check what has changed ??
	if (name_correct == 0){
		cout << "Name or password is wrong. Please try again" << endl;
		//To have the user not know the correct password for another account
		sign_in();
	}
	if (password_corect == 0){
		cout << "The password is wrong. Please try again" << endl;
		//To let the user know that the name is correct but the password is wrong
		sign_in();
	}

}
void sign_up(){
	//ForLoop to size the array
	for (number_of_user; number_of_user<100; number_of_user++){
		cout << "Enter Your Id :" << endl;
		cin >> arr[number_of_user].id;
		cout << "Enter Your email :" << endl;
		cin >> arr[number_of_user].email;
		cout << "Enter Your Name :" << endl;
		cin >> arr[number_of_user].name;
		cout << "Enter Your password :" << endl;
		cin >> arr[number_of_user].password;
		cout << "Enter Your Address :" << endl;
		getline(cin, (arr[number_of_user].address)); //to get adress with spaces
		cin.ignore(1000, '\n');
		cout << "Enter Your Number : " << endl;
		cin >> arr[number_of_user].number;

		cout << "Congratulations, you now have an account.." << endl;
		package_type[number_of_user].number[0] = 10;
		balance[number_of_user].number[0] = 10;
		number_of_user++;
		sign_message();

		break;

	}

}
void error_message(){
	cout << "Please enter a valid number" << endl;
}
void the_menu(int number_user){
	string operation;
	cout << endl << "******************************************" << endl;

	cout << arr[number_user].number << " Your balance is : " << balance[number_user].number[0] << endl;
	cout << "Package Type Internet : " << package_type[number_user].number[0] << endl;
	cout << "Start Date : 01/06/2020" << endl;
	cout << "Renewal Date : 01/06/2024" << endl;
	cout << endl << "====================================" << endl;

	//add phone
	if (!arr[number_user].number2.empty()){
		cout << arr[number_user].number2 << " Your balance is : " << balance[number_user].number[1] << endl;
		cout << "Package Type Internet : " << package_type[number_user].number[1] << endl;
		cout << "Start Date : 01/06/2020" << endl;
		cout << "Renewal Date : 01/06/2025" << endl;
		cout << endl << "====================================" << endl;
	}
	if (!arr[number_user].number3.empty()){
		cout << arr[number_user].number3 << " Your balance is : " << balance[number_user].number[2] << endl;
		cout << "Package Type Internet : " << package_type[number_user].number[2] << endl;
		cout << "Start Date : 01/06/2020" << endl;
		cout << "Renewal Date : 01/06/2026" << endl;
		cout << endl << "====================================" << endl;
	}
	// the list
	cout << "To make add a number \t press 1" << endl;
	cout << "To renew Your subscription to the package \t press 2" << endl;
	cout << "To call a person for 0.25 LE \t press 3" << endl;
	cout << "To message someone for 0,25 LE \t press 4" << endl;
	cout << "To recharge your balance \t press 5 " << endl;
	cout << "To transfer balance to another user on the same network \t press 6 " << endl;
	cout << "To sign out \t press 7 " << endl;
	cin >> operation;
	if (operation == "1" && (arr[number_user].number2.empty() || arr[number_user].number3.empty())){
		add_number();
	}
	else if (operation == "1" && !arr[number_user].number3.empty() && !arr[number_user].number3.empty()){
		cout << "Unfortunately, the maximum line ownership is 3 lines";
		the_menu(number_user);
	}
	else if (operation == "2"){
		package();
	}
	else if (operation == "3"){
		call();
	}
	else if (operation == "4"){
		message();
	}
	else if (operation == "5"){
		balance_recharge();
	}
	else if (operation == "6"){
		transfer();

	}
	else if (operation == "7"){
		sign_message();
	}
	else{
		error_message();
		the_menu(number_user);
	}
}
void add_number(){
	cout << "Type the number you want to add :  " << endl;
	if (arr[user_number].number2.empty()){
		cin >> arr[user_number].number2;
		package_type[user_number].number[1] = 10;
		balance[user_number].number[1] = 10;
	}
	else{
		cin >> arr[user_number].number3;
		package_type[user_number].number[2] = 10;
		balance[user_number].number[2] = 10;
	}
	cout << "New number added successfully.." << endl;
	the_menu(user_number);
}
void package(){
	string change_package;
	string internet;
	string package_phone;
	cout << "Do you want change your package ?" << endl;
	cout << "1.yes \t 2.No" << endl;
	cin >> change_package;
	cout << "On which phone number do you want this package?" << endl;
	cout << arr[user_number].number << "\t press 1" << endl;
	if (!arr[user_number].number2.empty()){
		cout << arr[user_number].number2 << "\t press 2" << endl;
	}
	if (!arr[user_number].number3.empty()){
		cout << arr[user_number].number3 << "\t press 3" << endl;
	}
	cin >> package_phone;
	if (change_package == "1"){
		cout << "What package do you prefer ? " << endl;
		cout << "Internet >> 10 L.E \t press 1" << endl;
		cout << "Internet >> 20 L.E \t press 2" << endl;
		cout << "Internet >> 50 L.E \t press 3" << endl;
		cin >> internet;
		if (package_phone == "2"){

			if (internet == "1"){
				//We first ensure that the balance is sufficient
				if (package_type[user_number].number[1] <= balance[user_number].number[1]){
					package_type[user_number].number[1] = 10;
					balance[user_number].number[1] -= package_type[user_number].number[1];
				}
				else{
					cout << "Sorry, your balance is not enough" << endl;
				}
			}
			if (internet == "2"){

				if (package_type[user_number].number[1] <= balance[user_number].number[1]){
					package_type[user_number].number[1] = 20;
					balance[user_number].number[1] -= package_type[user_number].number[1];
				}
				else{
					cout << "Sorry, your balance is not enough" << endl;
				}
			}
			if (internet == "3"){

				if (package_type[user_number].number[1] <= balance[user_number].number[1]){
					package_type[user_number].number[1] = 50;
					balance[user_number].number[1] -= package_type[user_number].number[1];
				}
				else{
					cout << "Sorry, your balance is not enough" << endl;
				}
			}

		}
		else if (package_phone == "3"){

			if (internet == "1"){

				if (package_type[user_number].number[2] <= balance[user_number].number[2]){
					package_type[user_number].number[2] = 10;
					balance[user_number].number[2] -= package_type[user_number].number[2];
				}
				else{
					cout << "Sorry, your balance is not enough" << endl;
				}
			}
			if (internet == "2"){

				if (package_type[user_number].number[2] <= balance[user_number].number[2]){
					package_type[user_number].number[2] = 20;
					balance[user_number].number[2] -= package_type[user_number].number[2];
				}
				else{
					cout << "Sorry, your balance is not enough" << endl;
				}
			}
			if (internet == "3"){

				if (package_type[user_number].number[2] <= balance[user_number].number[2]){
					package_type[user_number].number[2] = 50;
					balance[user_number].number[2] -= package_type[user_number].number[2];
				}
				else{
					cout << "Sorry, your balance is not enough" << endl;
				}
			}

		}
		else if (package_phone == "1"){

			if (internet == "1"){

				if (package_type[user_number].number[0] <= balance[user_number].number[0]){
					package_type[user_number].number[0] = 10;
					balance[user_number].number[0] -= package_type[user_number].number[0];
				}
				else{
					cout << "Sorry, your balance is not enough" << endl;
				}
			}
			if (internet == "2"){

				if (package_type[user_number].number[0] <= balance[user_number].number[0]){
					package_type[user_number].number[0] = 20;
					balance[user_number].number[0] -= package_type[user_number].number[0];
				}
				else{
					cout << "Sorry, your balance is not enough" << endl;
				}
			}
			if (internet == "3"){

				if (package_type[user_number].number[0] <= balance[user_number].number[0]){
					package_type[user_number].number[0] = 50;
					balance[user_number].number[0] -= package_type[user_number].number[0];
				}
				else{
					cout << "Sorry, your balance is not enough" << endl;
				}
			}

		}
		else{
			error_message();
			package();
		}

	}
	else if (change_package == "2"){

		if (package_phone == "2"){
			if (package_type[user_number].number[1] <= balance[user_number].number[1]){
				balance[user_number].number[1] -= package_type[user_number].number[1];
			}
			else{
				cout << "Sorry, your balance is not enough" << endl;
			}
		}
		else if (package_phone == "3"){
			if (package_type[user_number].number[2] <= balance[user_number].number[2]){
				balance[user_number].number[2] -= package_type[user_number].number[2];
			}
			else{
				cout << "Sorry, your balance is not enough" << endl;
			}
		}
		else if (package_phone == "1"){
			if (package_type[user_number].number[0] <= balance[user_number].number[0]){
				balance[user_number].number[0] -= package_type[user_number].number[0];
			}
			else{
				cout << "Sorry, your balance is not enough" << endl;
			}
		}
		else{
			error_message();
			package();
		}
	}
	else{
		error_message();
		package();
	}
	the_menu(user_number);
}

void call(){
	int phone_call;
	cout << "Enter the phone number you want to call : ";
	cin >> phone_call;
	if (balance[user_number].number[0] > 0){
	cout << "0.25 EGP was deducted from your balance" << endl;
	balance[user_number].number[0] -= 0.25; 
	}
	else{
		cout << "Sorry, your balance is not enough" << endl;
	}
	the_menu(user_number);
}
void message(){
	int phone_message;
	string text_message;
	cout << "Enter the phone number you want to message : ";
	cin >> phone_message;
	cout << "Write Your message and press Enter to send it.." << endl;
	cin >> text_message;
	if (balance[user_number].number[0] > 0){
		cout << "0.25 EGP was deducted from your balance" << endl;
		balance[user_number].number[0] -= 0.25;
	}
	else{
		cout << "Sorry, your balance is not enough" << endl;
	}
	the_menu(user_number);
}
void balance_recharge(){
	int serial_num;
	string choose_phone;
	cout << "On which phone number do you want to recharge ?" << endl;
	cout << arr[user_number].number << "\t press 1" << endl;
	if (!arr[user_number].number2.empty()){
		cout << arr[user_number].number2 << "\t press 2" << endl;
	}
	if (!arr[user_number].number3.empty()){
		cout << arr[user_number].number3 << "\t press 3" << endl;
	}
	cin >> choose_phone;
	cout << endl;
	cout << "Enter yor serial number : ";
	cin >> serial_num;
	if (choose_phone == "2"){

		if (serial_num > 9 && serial_num <1001){
			serial_num /= 2;
			if (serial_num % 5 == 0){
				balance[user_number].number[1] += serial_num;
			}
			else{
				cout << "Please enter a valid number" << endl;
				balance_recharge();
			}
		}
		else{
			cout << "Please enter a valid number" << endl;
			balance_recharge();
		}
	}
	else if (choose_phone == "3"){

		if (serial_num > 9 && serial_num <1001){
			serial_num /= 2;
			if (serial_num % 5 == 0){
				balance[user_number].number[2] += serial_num;
			}
			else{
				cout << "Please enter a valid number" << endl;
				balance_recharge();
			}
		}
		else{
			cout << "Please enter a valid number" << endl;
			balance_recharge();
		}
	}
	else if (choose_phone == "1"){
		if (serial_num > 9 && serial_num <1001){
			serial_num /= 2;
			if (serial_num % 5 == 0){
				balance[user_number].number[0] += serial_num;

			}
			else{
				cout << "Please enter a valid number" << endl;
				balance_recharge();
			}
		}
		else{
			cout << "Please enter a valid number" << endl;
			balance_recharge();
		}

	}
	else{
		error_message();
	}
	the_menu(user_number);
}
void transfer(){
	int pounds;
	string trnsfer_to_phone;
	cout << "To which number do you want to transfer your balance ?" << endl;
	if (!arr[user_number].number2.empty()){
		cout << arr[user_number].number2 << "\t press 1" << endl;
	}
	if (!arr[user_number].number3.empty()){
		cout << arr[user_number].number3 << "\t press 2" << endl;
	}
	cout << "Another person’s phone number \t press A" << endl;
	cin >> trnsfer_to_phone;
	if (trnsfer_to_phone == "1"){

		cout << " How many pounds do you want to transfer it ? ";
		cin >> pounds;

		if (pounds < balance[user_number].number[0]){
			balance[user_number].number[1] += pounds;
			balance[user_number].number[0] -= pounds;
		}
		else{
			cout << "Unfortunately, your balance is not sufficient";
			transfer();
		}

	}
	else if (trnsfer_to_phone == "2"){
		cout << " How many pounds do you want to transfer it ? ";
		cin >> pounds;
		if (pounds < balance[user_number].number[0]){
			balance[user_number].number[2] += pounds;
			balance[user_number].number[0] -= pounds;
		}
		else{
			cout << "Unfortunately, your balance is not sufficient";
			transfer();
		}
	}
	else if (trnsfer_to_phone == "A" || trnsfer_to_phone == "a"){
		string phone;
		cout << "Enter the number you want to transfer balance to" << endl;
		cin >> phone;
		for (int user_phone = 0; user_phone < 100; user_phone++){
			if (phone == arr[user_phone].number || phone == arr[user_phone].number2 || phone == arr[user_phone].number3){
				cout << " How many pounds do you want to transfer it ? ";
				cin >> pounds;
				if (pounds < balance[user_number].number[0] && phone == arr[user_phone].number2){
					balance[user_phone].number[1] += pounds;
					balance[user_number].number[0] -= pounds;
					cout << "The balance was transferred successfully";
				}
				else if (pounds < balance[user_number].number[0] && phone == arr[user_phone].number3){
					balance[user_phone].number[2] += pounds;
					balance[user_number].number[0] -= pounds;
					cout << "The balance was transferred successfully";
				}
				else if (pounds < balance[user_number].number[0] && phone == arr[user_phone].number){
					balance[user_phone].number[0] += pounds;
					balance[user_number].number[0] -= pounds;
					cout << "The balance was transferred successfully";
				}
				else {
					cout << "Unfortunately, your balance is not sufficient";
					transfer();
				}
				break;
			}
			else{
				error_message();
				transfer();
				break;
			}
		}
	}
	else{
		error_message();
	}
	the_menu(user_number);
}

