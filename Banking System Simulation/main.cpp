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
        int choice;
        std::cin >> choice;

        if (std::cin.fail()) {  // Handle invalid input (non-numeric values)
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            std::cout << "Invalid input! Please enter a number.\n";
            continue;
        }

        if (choice == 1) {  // Admin Login
            if (bank.adminLogin()) {  // Login must be successful to proceed
                int adChoice;
                do {
                    bank.displayAdminMenu();
                    std::cin >> adChoice;

                    if (std::cin.fail()) {  // Validate input
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Invalid input! Please enter a valid number.\n";
                        continue;
                    }

                    switch (adChoice) {
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
                        std::cout << "Logging out from admin panel...\n";
                        break;
                    case 6:
                        std::cout << "Exiting from bank...\n";
                        return 0;  // Exit program
                    default:
                        std::cout << "Invalid input. Please try again.\n";
                    }
                } while (adChoice != 5);  // Exit admin menu only when choice is 5
            }
        }
        else if (choice == 2) {  // User Login
            if (bank.userLogin()) {  // Login must be successful to proceed
                int cusChoice;
                do {
                    bank.displayUserMenu();
                    std::cin >> cusChoice;

                    if (std::cin.fail()) {  // Validate input
                        std::cin.clear();
                        std::cin.ignore(10000, '\n');
                        std::cout << "Invalid input! Please enter a valid number.\n";
                        continue;
                    }

                    switch (cusChoice) {
                    case 1:
                        bank.depositMoney();
                        break;
                    case 2:
                        bank.checkBalance();
                        break;
                    case 3:
                        bank.transferMoney();
                        break;
                    case 4:
                        std::cout << "Logging out from user panel...\n";
                        break;
                    case 5:
                        std::cout << "Exiting from bank...\n";
                        return 0;  // Exit program
                    default:
                        std::cout << "Invalid input. Please try again.\n";
                    }
                } while (cusChoice != 4);  // Exit user menu only when choice is 4
            }
        }
        else if (choice == 3) {  // Exit Bank
            std::cout << "Exiting from bank...\n";
            break;
        }
        else {
            std::cout << "Invalid choice! Please enter a valid number.\n";
        }
    }



    return 0;
}