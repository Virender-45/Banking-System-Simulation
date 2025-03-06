#include "Bank.h"

Bank::Bank() {

    if (customers.empty()) {
        // Predefined Users
        customers.push_back({ 10001, "Virender", 100, "Rana12" });
        customers.push_back({ 10002, "Sahil", 1000, "Dhiman13" });
        customers.push_back({ 10003, "Atul", 10000, "Rana14" });
        customers.push_back({ 10004, "Nikhil", 100000, "Rana15" });
        customers.push_back({ 10005, "Abhay", 20000, "Chandel16" });
        saveCustomersToFile();
    }
    
    if (admins.empty()) {
        // Predefined admins
        admins.push_back({ 100, "Virender123" });
        admins.push_back({ 101, "Hello12" });
        admins.push_back({ 102, "Pass3dd" });
        admins.push_back({ 103, "YellowCotton" });
        saveAdminsToFile();
    }
}

// Function to save customer data
void Bank::saveCustomersToFile() {
    std::ofstream file("customers.txt");
    if (!file) {
        std::cout << "Error saving customer data!\n";
        return;
    }

    for (const auto& customer : customers) {
        file << customer.accountNumber << " "
            << customer.name << " "
            << customer.balance << " "
            << customer.password << "\n";
    }
    file.close();
}

// Function to save admin data
void Bank::saveAdminsToFile() {
    std::ofstream file("admins.txt"); // Overwrites the file to prevent duplicates
    if (!file) {
        std::cout << "Error saving admin data!\n";
        return;
    }

    for (const auto& admin : admins) {
        file << admin.id << " "
            << admin.password << "\n";
    }
    file.close();
}


// Display the main menu
void Bank::displayMainMenu() {
    std::cout << "----------Welcome to Apna Bank----------\n";
    std::cout << "(1) Log in as Admin\n";
    std::cout << "(2) Log in as User\n";
    std::cout << "(3) Exit\n";
    std::cout << "Enter your choice: ";
}

// Admin login
bool Bank::adminLogin() {
    int id;
    std::string pass;
    std::cout << "Enter ID: ";
    std::cin >> id;
    std::cout << "Enter Password: ";
    std::cin >> pass;

    for (const auto& admin : admins) {
        if (admin.id == id && admin.password == pass) {
            std::cout << "\nLogin Successful.\n\n";
            return true;
        }
    }
    std::cout << "Admin not found\n";
    return false;
}

// Display admin menu
void Bank::displayAdminMenu() {
    std::cout << "--------Admin Panel--------\n";
    std::cout << "(1) Add Customer\n";
    std::cout << "(2) Display All Customers\n";
    std::cout << "(3) Search a Customer\n";
    std::cout << "(4) Deposit Money\n";
    std::cout << "(5) Withdraw Money\n";
    std::cout << "(6) Transfer Money\n";
    std::cout << "(7) Log Out\n";
    std::cout << "(8) Exit\n";
    std::cout << "Enter Your Choice: ";
}

// User login
bool Bank::userLogin() {
    int ac;
    std::string pass;
    std::cout << "Enter Account Number: ";
    std::cin >> ac;
    std::cout << "Enter Password: ";
    std::cin >> pass;

    for (const auto& customer : customers) {
        if (customer.accountNumber == ac && customer.password == pass) {
            loggedInUser = ac;
            std::cout << "\nLogin successful!\n\n";
            return true;
        }
    }
    std::cout << "User not found\n";
    return false;
}

// Display user menu
void Bank::displayUserMenu() {
    std::cout << "--------User Panel--------\n";
    std::cout << "(1) Deposit Money\n";
    std::cout << "(2) Withdraw Money\n";
    std::cout << "(3) Transfer Money\n";
    std::cout << "(4) Check Balance\n";
    std::cout << "(5) Log Out\n";
    std::cout << "(6) Exit\n";
    std::cout << "Enter your choice: ";
}

// Add a new customer
void Bank::addCustomer() {
    Customer newCustomer;
    std::cout << "Enter Account Number: ";
    std::cin >> newCustomer.accountNumber;
    std::cout << "Enter Name: ";
    std::cin >> newCustomer.name;
    std::cout << "Enter Initial Balance: ";
    std::cin >> newCustomer.balance;
    std::cout << "Enter Password: ";
    std::cin >> newCustomer.password;

    customers.push_back(newCustomer);
    std::cout << "Customer Added Successfully\n";
    saveCustomersToFile();
}

// Display all customers
void Bank::displayCustomers() {
    for (const auto& customer : customers) {
        std::cout << "Account No.: " << customer.accountNumber << "\n";
        std::cout << "Name: " << customer.name << "\n";
        std::cout << "Balance: " << customer.balance << "\n";
        std::cout << "--------------------\n";
    }
}

// Search for a customer
void Bank::searchCustomer() {
    int ac;
    std::cout << "Enter Account No: ";
    std::cin >> ac;

    for (const auto& customer : customers) {
        if (customer.accountNumber == ac) {
            std::cout << "Account No.: " << customer.accountNumber << "\n";
            std::cout << "Name: " << customer.name << "\n";
            std::cout << "Balance: " << customer.balance << "\n";
            return;
        }
    }
    std::cout << "Customer not found.\n";
}

// Deposit money
void Bank::depositMoney() {
    int ac;
    double amount;
    std::cout << "Enter Account No.: ";
    std::cin >> ac;
    std::cout << "Enter Deposit Amount: ";
    std::cin >> amount;

    for (auto& customer : customers) {
        if (customer.accountNumber == ac) {
            customer.balance += amount;
            std::cout << "Deposit Successful. New Balance: " << customer.balance << "\n";
            saveCustomersToFile();
            return;
        }
    }
    std::cout << "Account not found.\n";
}

// Withdraw money
void Bank::withdrawMoney() {
    int ac;
    double amount;
    std::cout << "Enter Account No.: ";
    std::cin >> ac;
    std::cout << "Enter Withdraw Amount: ";
    std::cin >> amount;

    for (auto& customer : customers) {
        if (customer.accountNumber == ac) {
            if (customer.balance >= amount) {
                customer.balance -= amount;
                std::cout << "Withdrawal Successful. Remaining Balance: " << customer.balance << "\n";
                saveCustomersToFile();
                return;
            } else {
                std::cout << "Insufficient Balance.\n";
                return;
            }
        }
    }
    std::cout << "Account not found.\n";
}

// Transfer money
void Bank::transferMoney() {
    int sender = loggedInUser, receiver;
    double amount;
    std::cout << "Enter Receiver's Account No: ";
    std::cin >> receiver;
    std::cout << "Enter Transfer Amount: ";
    std::cin >> amount;

    auto senderIt = std::find_if(customers.begin(), customers.end(), [&](const Customer& c) {
        return c.accountNumber == sender;
    });

    auto receiverIt = std::find_if(customers.begin(), customers.end(), [&](const Customer& c) {
        return c.accountNumber == receiver;
    });

    if (senderIt != customers.end() && receiverIt != customers.end() && senderIt->balance >= amount) {
        senderIt->balance -= amount;
        receiverIt->balance += amount;
        std::cout << "Transaction Successful!\n";
        saveCustomersToFile();
    } else {
        std::cout << "Transaction Failed.\n";
    }
}

// Check balance
void Bank::checkBalance() {
    for (const auto& customer : customers) {
        if (customer.accountNumber == loggedInUser) {
            std::cout << "Your Balance: " << customer.balance << "\n";
            return;
        }
    }
    std::cout << "Account not found.\n";
}
