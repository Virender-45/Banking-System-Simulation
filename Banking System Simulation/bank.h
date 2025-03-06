#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>

class Bank {
private:
    int loggedInUser = -1;

public:
    struct Admin {
        int id;
        std::string password;
    };

    struct Customer {
        int accountNumber;
        std::string name;
        double balance;
        std::string password;
    };

    std::vector<Customer> customers;    //In place of cusHave[100]
    std::vector<Admin> admins;      //In place of adHave[10]

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
    void saveCustomersToFile();
    void saveAdminsToFile();
};
