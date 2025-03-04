#include <iostream>
#include "Bank.h"

int main() {
    int choice;
    Bank bank;

    /*
    do {
        bank.displayMenu();
        std::cin >> choice;
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
            std::cout << "Exiting the bank..." << std::endl;
            break;
        default:
            std::cout << "Invalid input..." << std::endl;
            break;
        }
    } while (choice != 7);*/

    // The above do-while loop can be replaced with the following while loop
    /*while (true) {
        bank.displayMenu();
        std::cin >> choice;

        if (choice == 7) {
            std::cout << "Exiting the bank..." << std::endl;
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
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }*/
    while (true) {
        bank.displayMainMenu();
        std::cin >> choice;

        if (choice == 1) {
            bank.displayAdminMenu();
        }
        else if (choice == 2) {
            bank.displayUserMenu();
        }
        else if (choice == 3) {
            std::cout << "Exiting from bank...";
            break;
        }
        else {
            std::cout << "Invaild input" << std::endl;
        }
    }

    return 0;
}