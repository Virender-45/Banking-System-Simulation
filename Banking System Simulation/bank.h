#pragma once

#include <string>

class Bank {
private:
    int loggedInUser = -1;
public:
    struct Admin {
        int id;
        std::string password;
    };
    struct Customer {
        int accountNumber = 0;
        std::string name;
        double balance = 0;
        std::string password;
    };

    Customer cusHave[100];
    int totalCustomers;
    Admin adHave[10];
    int totalAdmins;

    Bank();
    void displayMainMenu();
    bool adminLogin();
    void displayAdminMenu();
    bool userLogin();
    void displayUserMenu();
    void addCustomer();
    void displayCustomers();
    void searchCustomer();
    void depositMoney();
    void withdrawMoney();
    void transferMoney();
    void checkBalance();
};