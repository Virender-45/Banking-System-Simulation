#include "Bank.h"
#include <iostream>
#include <fstream>
#include <string>

Bank::Bank()
{
    cusHave[0] = { 10001, "Virender", 100, "Rana12" };
    cusHave[1] = { 10002, "Sahil", 1000, "Dhiman13" };
    cusHave[2] = { 10003, "Atul", 10000, "Rana14" };
    cusHave[3] = { 10004, "Nikhil", 100000, "Rana15" };
    cusHave[4] = { 10005, "Abhay", 99872, "Chandel16" };
    totalCustomer = 5;

    adHave[0] = { 100, "Virender123" };
    adHave[1] = { 101, "Hello12" };
    adHave[2] = { 102, "Pass3dd" };
    adHave[3] = { 103, "YellowCotton" };
    totalAdmin = 4;
}

void Bank::displayMainMenu()
{
    std::cout << "----------Welcome to Apna Bank----------" << std::endl;
    std::cout << "(1) Log in as Admin" << std::endl;
    std::cout << "(2) Log in as User." << std::endl;
    std::cout << "(3) Exit from bank." << std::endl;
    std::cout << "Enter your choice : ";
}
void Bank::displayAdminMenu() {
    int id;
    std::string pass;
    std::cout << "Enter ID : ";
    std::cin >> id;
    std::cout << "Enter Password : ";
    std::cin >> pass;
    bool adFound = false;

    for (int i = 0; i < totalAdmin; i++) {
        if (id == adHave[i].id) {
            if (pass == adHave[i].password) {
                adFound = true;
            }
        }
    }
    if (adFound) {
        std::cout << "--------Good Morning Admin--------" << std::endl << std::endl;
        std::cout << "(1) Add Customer." << std::endl;
        std::cout << "(2) Display All Customers." << std::endl;
        std::cout << "(3) Search a Customer." << std::endl;
        std::cout << "(4) Deposit Money." << std::endl;
        std::cout << "(5) Log Out." << std::endl;
        std::cout << "(6) Exit From Bank." << std::endl;
        std::cout << "Enter Your Choice : ";
    }
    if (!adFound) {
        std::cout << "Admin not found" << std::endl;
    }
}
void Bank::displayUserMenu() {
    int ac;
    std::string pass;
    std::cout << "Enter Account Number : ";
    std::cin >> ac;
    std::cout << "Enter Password : ";
    std::cin >> pass;
    bool cusFound = false;

    for (int i = 0; i < totalAdmin; i++) {
        if (ac == cusHave[i].accountNumber) {
            if (pass == cusHave[i].password) {
                cusFound = true;
            }
        }
    }
    if (cusFound) {
        std::cout << "--------User Dashboard--------" << std::endl;
    }
    if (!cusFound) {
        std::cout << "User not found" << std::endl;
    }
}
void Bank::addCustomer()
{
    int n;
    std::cout << "How many customers you want to add: ";
    std::cin >> n;

    for (int i = totalCustomer; i < n + totalCustomer; i++) {
        std::cout << "Enter details of customer " << i + 1 << ":" << std::endl;
        std::cout << "Enter account number: ";
        std::cin >> cusHave[totalCustomer].accountNumber;
        std::cout << "Enter name: ";
        std::cin >> cusHave[totalCustomer].name;
        std::cout << "Enter the balance: ";
        std::cin >> cusHave[totalCustomer].balance;
        std::cout << "\nCustomer " << cusHave[totalCustomer].name << " added successfully.\n" << std::endl;
    }
        totalCustomer += n;
}
/*
void Bank::addCustomer()
{
    int n;
    std::cout << "How many customers you want to add: ";
    std::cin >> n;


    for (int i = totalCustomer; i < n + totalCustomer; i++) {
        std::cout << "Enter details of customer " << i + 1 << ":" << std::endl;
        std::cout << "Enter account number: ";
        std::cin >> cusHave[totalCustomer].accountNumber;
        std::cout << "Enter name: ";
        std::cin >> cusHave[totalCustomer].name;
        std::cout << "Enter the balance: ";
        std::cin >> cusHave[totalCustomer].balance;
        std::cout << "\nCustomer " << cusHave[totalCustomer].name << " added successfully.\n" << std::endl;
    }
    totalCustomer += n;

    // opeing file using constructor and writing it
    std::ofstream cusData("customer.txt", std::ios::app);
    //cusData.open("customer.txt");
    cusData << cusHave[totalCustomer].accountNumber;
    //cusData.close();
}*/

void Bank::displayCustomers()
{
    for (int i = 0; i < totalCustomer; i++) {
        std::cout << "Customer " << i + 1 << " :" << std::endl;
        std::cout << "Account No.: " << cusHave[i].accountNumber << std::endl;
        std::cout << "Name: " << cusHave[i].name << std::endl;
        std::cout << "Balance: " << cusHave[i].balance << std::endl;
    }
}

void Bank::searchCustomer() {
    int ac;
    std::cout << "Enter the Account No. of Customer: ";
    std::cin >> ac;

    bool found = false;
    for (int i = 0; i < totalCustomer; i++) {
        if (ac == cusHave[i].accountNumber) {
            std::cout << "Customer with Acc. No. " << ac << " is:" << std::endl;
            std::cout << "Name: " << cusHave[i].name << std::endl;
            std::cout << "Balance: " << cusHave[i].balance << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Not found..." << std::endl;
    }
}

void Bank::depositMoney() {
    int ac;
    double amt;
    std::cout << "Enter the Account No.: ";
    std::cin >> ac;
    std::cout << "Enter the amount to deposit: ";
    std::cin >> amt;

    bool found = false;
    for (int i = 0; i < totalCustomer; i++) {
        if (ac == cusHave[i].accountNumber) {
            cusHave[i].balance += amt;
            std::cout << "Deposit successful. Updated balance: " << cusHave[i].balance << std::endl;
            found = true;
        }
    }
    if (!found) {
        std::cout << "Account not found." << std::endl;
    }
}

void Bank::withdrawMoney() {
    int ac;
    double amt;
    std::cout << "Enter the Account No.: ";
    std::cin >> ac;
    std::cout << "Enter the amount to withdraw: ";
    std::cin >> amt;

    bool found = false;
    for (int i = 0; i < totalCustomer; i++) {
        if (ac == cusHave[i].accountNumber) {
            if (amt <= cusHave[i].balance) {
                cusHave[i].balance -= amt;
                std::cout << "Withdrawal successful. Remaining balance: " << cusHave[i].balance << std::endl;
            }
            else {
                std::cout << "Insufficient balance." << std::endl;
            }
            found = true;
        }
    }
    if (!found) {
        std::cout << "Account not found." << std::endl;
    }
}

void Bank::transferMoney() {
    int s_ac, r_ac;
    double amt, bal;
    std::cout << "Enter the sender Account No. : ";
    std::cin >> s_ac;
    std::cout << "Enter the reciever's Account No : ";
    std::cin >> r_ac;
    std::cout << "Enter the amount you want to transfer : ";
    std::cin >> amt;

    bool sender_found = false;
    bool reciever_found = false;

    for (int i = 0; i < totalCustomer; i++) {
        if (s_ac == cusHave[i].accountNumber) {
            sender_found = true;
            bal = cusHave[i].balance;
            if (bal < amt) {
                std::cout << "Insufficient Balance in Sender Account" << std::endl;
            }
        }
        else if (r_ac == cusHave[i].accountNumber) {
            reciever_found = true;
        }
    }
    if (sender_found == true && reciever_found == true && bal >= amt) {
        for (int i = 0; i < totalCustomer; i++) {
            if (s_ac == cusHave[i].accountNumber) {
                cusHave[i].balance -= amt;
                std::cout << "Money Debited form " << cusHave[i].name << " Account " << std::endl;
            }
            if (r_ac == cusHave[i].accountNumber) {
                cusHave[i].balance += amt;
                std::cout << "Money Credited to " << cusHave[i].name << " Account " << std::endl;
            }
        }
        std::cout << "Transaction Successful" << std::endl;
    }
    if (!sender_found) {
        std::cout << "Sender Account doesnot found" << std::endl;
    }
    if (!reciever_found) {
        std::cout << "Reciever Account doesnot found" << std::endl;
    }
    if (!sender_found || !reciever_found) {
        std::cout << "Transaction failed!!!" << std::endl;
    }
}