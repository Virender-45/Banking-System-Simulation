#include "Bank.h"

#include <fstream>  // Include for file handling

Bank::Bank() {
    loadCustomersFromFile();
    loadAdminsFromFile();

    if (totalCustomers == 0) {
        cusHave[0] = { 10001, "Virender", 100, "Rana12" };
        cusHave[1] = { 10002, "Sahil", 1000, "Dhiman13" };
        cusHave[2] = { 10003, "Atul", 10000, "Rana14" };
        cusHave[3] = { 10004, "Nikhil", 100000, "Rana15" };
        cusHave[4] = { 10005, "Abhay", 20000, "Chandel16" };
        totalCustomers = 5;
        saveCustomersToFile();
    }

    if (totalAdmins == 0) {
        adHave[0] = { 100, "Virender123" };
        adHave[1] = { 101, "Hello12" };
        adHave[2] = { 102, "Pass3dd" };
        adHave[3] = { 103, "YellowCotton" };
        totalAdmins = 4;
        saveAdminsToFile();
    }
}

void Bank::displayMainMenu() {
    std::cout << "----------Welcome to Apna Bank----------\n";
    std::cout << "(1) Log in as Admin\n";
    std::cout << "(2) Log in as User\n";
    std::cout << "(3) Exit from bank\n";
    std::cout << "Enter your choice: ";
}

bool Bank::adminLogin() {
    int id;
    std::string pass;
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    std::cin >> pass;

    for (int i = 0; i < totalAdmins; i++) {
        if (id == adHave[i].id && pass == adHave[i].password) {
            std::cout << "\nLogin Successful.\n\n";
            return true;
        }
    }
    std::cout << "Admin not found\n";
    return false;
}

void Bank::displayAdminMenu() {
    std::cout << "--------Good Morning Admin--------\n";
    std::cout << "(1) Add Customer\n";
    std::cout << "(2) Display All Customers\n";
    std::cout << "(3) Search a Customer\n";
    std::cout << "(4) Deposit Money\n";
    std::cout << "(5) Log Out\n";
    std::cout << "(6) Exit From Bank\n";
    std::cout << "Enter Your Choice: ";
}

void Bank::saveCustomersToFile() {
    std::ofstream file("customers.txt");
    if (!file) {
        std::cout << "Error opening customers file!\n";
        return;
    }

    file << totalCustomers << "\n";
    for (int i = 0; i < totalCustomers; i++) {
        file << cusHave[i].accountNumber << " "
            << cusHave[i].name << " "
            << cusHave[i].balance << " "
            << cusHave[i].password << "\n";
    }
    file.close();
}

void Bank::saveAdminsToFile() {
    std::ofstream file("admins.txt");
    if (!file) {
        std::cout << "Error opening admins file!\n";
        return;
    }

    file << totalAdmins << "\n";
    for (int i = 0; i < totalAdmins; i++) {
        file << adHave[i].id << " "
            << adHave[i].password << "\n";
    }
    file.close();
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
void Bank::addCustomer() {
    std::cout << "Enter new customer details:\n";

    Customer newCustomer;
    std::cout << "Account Number: ";
    std::cin >> newCustomer.accountNumber;
    std::cout << "Name: ";
    std::cin >> newCustomer.name;
    std::cout << "Initial Balance: ";
    std::cin >> newCustomer.balance;
    std::cout << "Password: ";
    std::cin >> newCustomer.password;

    cusHave[totalCustomers] = newCustomer;
    totalCustomers++;

    saveCustomersToFile();  // Update file after adding a customer
}


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

void Bank::loadCustomersFromFile() {
    std::ifstream file("customers.txt");  // Open file in read mode
    if (!file) {
        std::cout << "No customer data found. Using predefined customers." << std::endl;
        return;  // If file does not exist, use hardcoded values
    }

    file >> totalCustomers;

    for (int i = 0; i < totalCustomers; i++) {
        file >> cusHave[i].accountNumber
            >> cusHave[i].name
            >> cusHave[i].balance
            >> cusHave[i].password;
    }

    file.close();
}

void Bank::loadAdminsFromFile() {
    std::ifstream file("admins.txt");
    if (!file) {
        std::cout << "No admin data found. Using predefined admins." << std::endl;
        return;
    }

    file >> totalAdmins;

    for (int i = 0; i < totalAdmins; i++) {
        file >> adHave[i].id >> adHave[i].password;
    }

    file.close();
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
    double amt, senderBalance = -1;

    std::cout << "Enter the receiver's Account No: ";
    std::cin >> r_ac;
    std::cout << "Enter the amount you want to transfer: ";
    std::cin >> amt;

    bool receiverFound = false;

    for (int i = 0; i < totalCustomers; i++) {
        if (cusHave[i].accountNumber == loggedInUser) {
            senderBalance = cusHave[i].balance;
        }
        if (cusHave[i].accountNumber == r_ac) {
            receiverFound = true;
        }
    }

    if (!receiverFound) {
        std::cout << "Receiver account does not exist!" << std::endl;
        return;
    }

    if (senderBalance < amt) {
        std::cout << "Insufficient balance! Transaction failed." << std::endl;
        return;
    }

    for (int i = 0; i < totalCustomers; i++) {
        if (cusHave[i].accountNumber == s_ac) {
            cusHave[i].balance -= amt;
        }
        if (cusHave[i].accountNumber == r_ac) {
            cusHave[i].balance += amt;
        }
    }

    std::cout << "Transaction Successful!" << std::endl;

    // ✅ Save updated balances
    std::ofstream outFile("customer.txt");

    for (int i = 0; i < totalCustomers; i++) {
        outFile << cusHave[i].accountNumber << " "
            << cusHave[i].name << " "
            << cusHave[i].balance << std::endl;
    }

    outFile.close();
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