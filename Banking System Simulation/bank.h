#pragma once

#include <string>

class Bank {
public:
    struct Customer {
        int accountNumber = 0;
        std::string name;
        double balance = 0;
    };

    Customer cusHave[100];
    int totalCustomer;

    Bank();
    void displayMenu();
    void addCustomer();
    void displayCustomers();
    void searchCustomer();
    void depositMoney();
    void withdrawMoney();
    void transferMoney();
};
