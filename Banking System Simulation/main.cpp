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

        if (choice == 1) {  // Admin Login
            if (bank.adminLogin()) {  // If login is successful
                int adChoice;
                do {
                    bank.displayAdminMenu();
                    std::cin >> adChoice;

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
                        std::cout << "Logging out..." << std::endl;
                        break;
                    case 6:
                        std::cout << "Exiting from bank...";
                        return 0;  // Exit program
                    default:
                        std::cout << "Invalid input. Please try again." << std::endl;
                    }
                } while (adChoice != 5);  // Exit admin menu only when choice is 5
            }
        }
        else if (choice == 2) {  // User Menu
            if (bank.userLogin()) {
                int cusChoice;
                do
                {
                    bank.displayUserMenu();
                    std::cin >> cusChoice;

                    switch (cusChoice)
                    {
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
                        std::cout << "Logging out..." << std::endl;
                        break;
                    case 5:
                        std::cout << "Exiting from bank...";
                        return 0;
                    default:
                        std::cout << "Invalid input. Please try again." << std::endl;
                    }
                } while (cusChoice != 4);  // Exit user menu only when choice is 4
            }
        }
        else if (choice == 3) {  // Exit Bank
            std::cout << "Exiting from bank...";
            break;
        }
        else {
            std::cout << "Invalid input!" << std::endl;
        }
    }


    return 0;
}