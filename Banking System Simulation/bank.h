#pragma once

#include <string>

class Bank {
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
    int totalCustomer;
    Admin adHave[10];
    int totalAdmin;

    Bank();
    void displayMainMenu();
    void displayAdminMenu();
    void displayUserMenu();
    void addCustomer();
    void displayCustomers();
    void searchCustomer();
    void depositMoney();
    void withdrawMoney();
    void transferMoney();
};