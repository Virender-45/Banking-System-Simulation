#include "Bank.h"
#include <iostream>
#include <fstream>

Bank::Bank()
{
    cusHave[0] = { 10001, "Virender", 100, "Rana12" };
    cusHave[1] = { 10002, "Sahil", 1000, "Dhiman13" };
    cusHave[2] = { 10003, "Atul", 10000, "Rana14" };
    cusHave[3] = { 10004, "Nikhil", 100000, "Rana15" };
    cusHave[4] = { 10005, "Abhay", 20000, "Chandel16" };
    totalCustomers = 5;

    adHave[0] = { 100, "Virender123" };
    adHave[1] = { 101, "Hello12" };
    adHave[2] = { 102, "Pass3dd" };
    adHave[3] = { 103, "YellowCotton" };
    totalAdmins = 4;
}

void Bank::displayMainMenu()
{
    std::cout << "----------Welcome to Apna Bank----------" << std::endl;
    std::cout << "(1) Log in as Admin" << std::endl;
    std::cout << "(2) Log in as User." << std::endl;
    std::cout << "(3) Exit from bank." << std::endl;
    std::cout << "Enter your choice : ";
}
bool Bank::adminLogin() {
    int id;
    std::string pass;
    std::cout << "Enter ID : ";
    std::cin >> id;
    std::cout << "Enter Password : ";
    std::cin >> pass;

    for (int i = 0; i < totalAdmins; i++) {
        if (id == adHave[i].id) {
            if (pass == adHave[i].password) {
                std::cout << "\nLogin Successful." << std::endl << std::endl;
                return true;
            }
        }
    }
    std::cout << "Admin not found" << std::endl;
    return false;
}

void Bank::displayAdminMenu() {
        std::cout << "--------Good Morning Admin--------" << std::endl << std::endl;
        std::cout << "(1) Add Customer." << std::endl;
        std::cout << "(2) Display All Customers." << std::endl;
        std::cout << "(3) Search a Customer." << std::endl;
        std::cout << "(4) Deposit Money." << std::endl;
        std::cout << "(5) Log Out." << std::endl;
        std::cout << "(6) Exit From Bank." << std::endl;
        std::cout << "Enter Your Choice : ";
}
bool Bank::userLogin() {
    int ac;
    std::string pass;
    std::cout << "Enter Account Number : ";
    std::cin >> ac;
    std::cout << "Enter Password : ";
    std::cin >> pass;

    for (int i = 0; i < totalCustomers; i++) {
        if (ac == cusHave[i].accountNumber && pass == cusHave[i].password) {
            loggedInUser = ac;
            std::cout << "\nLogin successful!" << std::endl << std::endl;
            return true;
        }
    }
    std::cout << "User not found" << std::endl;
    return false;
}

void Bank::displayUserMenu() {
    std::cout << "--------Good Morning User--------" << std::endl;
    std::cout << "(1) Deposit Money." << std::endl;
    std::cout << "(2) Check balance." << std::endl;
    std::cout << "(3) Transfer Money." << std::endl;
    std::cout << "(4) Log Out." << std::endl;
    std::cout << "(5) Exit From Bank." << std::endl;
    std::cout << "Enter your choice : ";
}
void Bank::addCustomer()
{
    int n;
    std::cout << "How many customers you want to add: ";
    std::cin >> n;

    for (int i = totalCustomers; i < n + totalCustomers; i++) {
        std::cout << "Enter details of customer " << i + 1 << ":" << std::endl;
        std::cout << "Enter account number: ";
        std::cin >> cusHave[totalCustomers].accountNumber;
        std::cout << "Enter name: ";
        std::cin >> cusHave[totalCustomers].name;
        std::cout << "Enter the balance: ";
        std::cin >> cusHave[totalCustomers].balance;
        std::cout << "\nCustomer " << cusHave[totalCustomers].name << " added successfully.\n" << std::endl;
    }
        totalCustomers += n;
}
/*
void Bank::addCustomer()
{
    int n;
    std::cout << "How many customers you want to add: ";
    std::cin >> n;


    for (int i = totalCustomers; i < n + totalCustomers; i++) {
        std::cout << "Enter details of customer " << i + 1 << ":" << std::endl;
        std::cout << "Enter account number: ";
        std::cin >> cusHave[totalCustomers].accountNumber;
        std::cout << "Enter name: ";
        std::cin >> cusHave[totalCustomers].name;
        std::cout << "Enter the balance: ";
        std::cin >> cusHave[totalCustomers].balance;
        std::cout << "\nCustomer " << cusHave[totalCustomers].name << " added successfully.\n" << std::endl;
    }
    totalCustomers += n;

    // opeing file using constructor and writing it
    std::ofstream cusData("customer.txt", std::ios::app);
    //cusData.open("customer.txt");
    cusData << cusHave[totalCustomers].accountNumber;
    //cusData.close();
}*/

void Bank::displayCustomers()
{
    std::ofstream outFile("custoemr.txt"); // open file for writing

    if (!outFile) {
        std::cout << "Error opening customer.txt file!" << std::endl;
        return;
    }

    for (int i = 0; i < totalCustomers; i++) {
        std::cout << "Customer " << i + 1 << " :" << std::endl;
        std::cout << "Account No.: " << cusHave[i].accountNumber << std::endl;
        std::cout << "Name: " << cusHave[i].name << std::endl;
        std::cout << "Balance: " << cusHave[i].balance << std::endl;
        std::cout << "--------------------" << std::endl;

        outFile << cusHave[i].accountNumber << " "
            << cusHave[i].name << " "
            << cusHave[i].balance;
    }

    outFile.close();
}

void Bank::searchCustomer() {
    int ac;
    std::cout << "Enter the Account No. of Customer: ";
    std::cin >> ac;

    bool found = false;
    for (int i = 0; i < totalCustomers; i++) {
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
    for (int i = 0; i < totalCustomers; i++) {
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
    for (int i = 0; i < totalCustomers; i++) {
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
    int s_ac = loggedInUser, r_ac;
    double amt, bal;
    std::cout << "Enter the reciever's Account No : ";
    std::cin >> r_ac;
    std::cout << "Enter the amount you want to transfer : ";
    std::cin >> amt;

    bool reciever_found = false;

    for (int i = 0; i < totalCustomers; i++) {
        if (cusHave[i].accountNumber == loggedInUser) {
            bal = cusHave[i].balance;
        }
        if (cusHave[i].accountNumber == r_ac) {
            reciever_found = true;
        }
    }

    if (reciever_found == true && bal >= amt) {
        for (int i = 0; i < totalCustomers; i++) {
            if (s_ac == cusHave[i].accountNumber) {
                cusHave[i].balance -= amt;
                std::cout << "\nMoney Debited form " << cusHave[i].name << " Account " << std::endl;
            }
            if (r_ac == cusHave[i].accountNumber) {
                cusHave[i].balance += amt;
                std::cout << "\nMoney Credited to " << cusHave[i].name << " Account " << std::endl;
            }
        }
        std::cout << "\nTransaction Successful" << std::endl << std::endl;
    }
    if (!reciever_found) {
        std::cout << "Reciever Account doesnot found" << std::endl;
    }
}

void Bank::checkBalance() {
    if (loggedInUser == -1) {  // Check if no user is logged in
        std::cout << "No user is logged in!" << std::endl;
        return;
    }

    for (int i = 0; i < totalCustomers; i++) {
        if (cusHave[i].accountNumber == loggedInUser) {  // Find the logged-in user's account
            std::cout << "Your balance is: " << cusHave[i].balance << std::endl;
            return;
        }
    }
    std::cout << "Error: User not found in database!" << std::endl;
}
