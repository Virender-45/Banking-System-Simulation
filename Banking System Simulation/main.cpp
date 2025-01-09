#include <iostream>
#include "Bank.h"
using namespace std;

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
            break;
        case 7:
            cout << "Exiting the bank..." << endl;
            break;
        default:
            cout << "Invalid input..." << endl;
            break;
        }
    } while (choice != 7);

    return 0;
}
