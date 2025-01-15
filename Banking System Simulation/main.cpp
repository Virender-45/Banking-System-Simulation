#include <iostream>
#include "Bank.h"
using namespace std;

int main() {
    int choice;
    Bank bank;

    /*
    do {
        bank.displayMenu();
        cin >> choice;
        switch (choice) {
        case 1:
            bank.addCustomer();
            break;
        case 2:
            bank.displayCustomers();
            break;
        case 3:
            bank.searchCustomer();
            break;
        case 4:
            bank.depositMoney();
            break;
        case 5:
            bank.withdrawMoney();
            break;
        case 6:
            bank.transferMoney();
            break;
        case 7:
            cout << "Exiting the bank..." << endl;
            break;
        default:
            cout << "Invalid input..." << endl;
            break;
        }
    } while (choice != 7);*/

	// The above do-while loop can be replaced with the following while loop
    while (true) {
        bank.displayMenu();
        cin >> choice;

        if (choice == 7) {
            cout << "Exiting the bank..." << endl;
            break;
        }

        switch (choice) {
        case 1:
            bank.addCustomer();
            break;
        case 2:
            bank.displayCustomers();
            break;
        case 3:
            bank.searchCustomer();
            break;
        case 4:
            bank.depositMoney();
            break;
        case 5:
            bank.withdrawMoney();
            break;
        case 6:
            bank.transferMoney();
            break;
        default:
            cout << "Invalid input. Please try again." << endl;
        }
    }


    return 0;
}
