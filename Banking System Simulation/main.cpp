#include "Bank.h"

int main()
{
    Bank bank;
    int choice;

    while (true)
    {
        bank.displayMainMenu();
        std::cin >> choice;

        switch (choice)
        {
        case 1:
            if (bank.adminLogin())
            {
                int adminChoice;
                do
                {
                    bank.displayAdminMenu();
                    std::cin >> adminChoice;
                    switch (adminChoice)
                    {
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
                        std::cout << "Logging Out..." << std::endl;
                        break;
                    case 8:
                        std::cout << "Exiting System..." << std::endl;
                        return 0;
                    default:
                        std::cout << "Invalid Choice! Try again." << std::endl;
                    }
                } while (adminChoice != 7);
            }
            break;

        case 2:
            if (bank.userLogin())
            {
                int userChoice;
                do
                {
                    bank.displayUserMenu();
                    std::cin >> userChoice;
                    switch (userChoice)
                    {
                    case 1:
                        bank.depositMoney();
                        break;
                    case 2:
                        bank.withdrawMoney();
                        break;
                    case 3:
                        bank.transferMoney();
                        break;
                    case 4:
                        bank.checkBalance();
                        break;
                    case 5:
                        std::cout << "Logging Out..." << std::endl;
                        break;
                    case 6:
                        std::cout << "Exiting System..." << std::endl;
                        return 0;
                    default:
                        std::cout << "Invalid Choice! Try again." << std::endl;
                    }
                } while (userChoice != 5);
            }
            break;

        case 3:
            std::cout << "Thank you for using Apna Bank! Exiting..." << std::endl;
            return 0;

        default:
            std::cout << "Invalid Choice! Please try again." << std::endl;
        }
    }
}
