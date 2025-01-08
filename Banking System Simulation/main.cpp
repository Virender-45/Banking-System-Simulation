#include<iostream>
#include<string>


using namespace std;

class Bank {
public:
	struct Customer {
		int accountNumber = 0;
		string name;
		double balance = 0;
	};
	Customer cusHave[100];
	int totalCustomer;
	Bank();

	void displayMenu();
	void addCustomer();
	void displayCustomers();
	void searchCustomer();
	void depositMoney();
	void withdrawMoney();
	void transferMoney();
};
void Bank::withdrawMoney() {
	int ac;
	double amt;
	cout << "Enter the Account No. : ";
	cin >> ac;
	cout << "Enter the amount to withdraw : ";
	cin >> amt;

	bool found = false;
	for (int i = 0; i < totalCustomer; i++) {
		if (ac == cusHave[i].accountNumber) {
			found = true;
			if (amt <= cusHave[i].balance) {
				cout << "Withdrawl Sucessful." << endl;
				cusHave[i].balance -= amt;
				cout << "Balance left in account " << cusHave[i].accountNumber << " is " << cusHave[i].balance << endl;
			}
			else {
				cout << "Not a valid Amount.." << endl;
			}
		}
	}
	if (!found) {
		cout << "Customer with Acc. No. " << ac << " not found" << endl;
	}
}
void Bank::depositMoney() {
	int ac;
	double newBalance;
	cout << "Enter the Account No. : ";
	cin >> ac;
	cout << "Enter the amount to be add : ";
	cin >> newBalance;

	bool found = false;
	for (int i = 0; i < totalCustomer; i++) {
		if (ac == cusHave[i].accountNumber) {
			cusHave[i].balance += newBalance;
			cout << "Balance Updated Sucessfully" << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Customer with Acc. No. " << ac << " not found" << endl;
	}
}
void Bank::searchCustomer() {
	int ac;
	cout << "Enter the Account No. of Employee : ";
	cin >> ac;

	bool found = false;
	for (int i = 0; i < totalCustomer; i++) {
		if (ac == cusHave[i].accountNumber) {
			cout << "Customer with Acc. No. " << ac << " is : " << endl;
			cout << "Name : " << cusHave[i].name << endl;
			cout << "Balance : " << cusHave[i].balance << endl;
			found = true;
		}
	}
	if (!found) {
		cout << "Not found..." << endl;
	}
}

void Bank::displayCustomers() {
	for (int i = 0; i < totalCustomer; i++) {
		cout << "Customer " << i + 1 << " :" << endl;
		cout << "Account No. : " << cusHave[i].accountNumber << endl;
		cout << "Name : " << cusHave[i].name << endl;
		cout << "Balance : " << cusHave[i].balance << endl;
	}
}
void Bank::addCustomer() {
	int n;
	cout << "How many customers you want to add : ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		cout << "Enter details of customer - " << i + 1 << " :" << endl;
		cout << "Enter account number : ";
		cin >> cusHave[i].accountNumber;
		cout << "Enter name : ";
		cin >> cusHave[i].name;
		cout << "Enter the balance : ";
		cin >> cusHave[i].balance;
		cout << "\nCustomer with name : " << cusHave[i].name << " added\n" << endl;

		totalCustomer += n;
	}
}
Bank::Bank() {
	cusHave[0] = { 10001, "Virender", 100 };
	cusHave[1] = { 10002, "Sahil", 1000 };
	cusHave[2] = { 10003, "Atul", 10000 };
	cusHave[3] = { 10004, "Nikhil", 100000};
	cusHave[4] = { 10005, "Abhay", 1000000 };
	totalCustomer = 5;
}
void Bank::displayMenu() {
	cout << "----------Welcome to Apna Bank----------" << endl;
	cout << "(1) Add Customer." << endl;
	cout << "(2) Display All Customers." << endl;
	cout << "(3) Search a Customer." << endl;
	cout << "(4) Deposit Money." << endl;
	cout << "(5) Withdraw Money." << endl;
	cout << "(6) Transfer Money." << endl;
	cout << "(7) Exit From Bank." << endl;
	cout << "Enter your choice : ";
}

int main() {
	int choice;
	Bank obj;

	do {
		obj.displayMenu();
		cin >> choice;
		switch (choice) {
		case 1:
			obj.addCustomer();
			break;
		case 2:
			obj.displayCustomers();
			break;
		case 3:
			obj.searchCustomer();
			break;
		case 4:
			obj.depositMoney();
			break;
		case 5:
			obj.withdrawMoney();
			break;
		case 6:
			obj.transferMoney();
		case 7:
			cout << "Eciting the bank..." << endl;
			break;
		default:
			cout << "Inavild input..." << endl;
			break;
		}
	} while (choice != 7);

	return 0;
}
