#include "Bank.h"
#include <iostream>
using namespace std;

Bank::Bank() {
    cusHave[0] = { 10001, "Virender", 100 };
    cusHave[1] = { 10002, "Sahil", 1000 };
    cusHave[2] = { 10003, "Atul", 10000 };
    cusHave[3] = { 10004, "Nikhil", 100000 };
    cusHave[4] = { 10005, "Abhay", 1000000 };
    totalCustomer = 5;
}

void Bank::displayMenu() {
    cout << "----------Welcome to Apna Bank----------" << endl;
    cout << "(1) Add Customer." << endl;
    cout << "(2) Display All Customers." << endl;
    cout << "(3) Search a Customer." << endl;
    cout << "(4) Deposit Money." << endl;
    cout << "(5) Withdraw Money." << endl;
    cout << "(6) Transfer Money." << endl;
    cout << "(7) Exit From Bank." << endl;
    cout << "Enter your choice : ";
}

void Bank::addCustomer() {
    int n;
    cout << "How many customers you want to add: ";
    cin >> n;

    for (int i = totalCustomer; i < n + totalCustomer; i++) {
        cout << "Enter details of customer " << i + 1 << ":" << endl;
        cout << "Enter account number: ";
        cin >> cusHave[totalCustomer].accountNumber;
        cout << "Enter name: ";
        cin >> cusHave[totalCustomer].name;
        cout << "Enter the balance: ";
        cin >> cusHave[totalCustomer].balance;
        cout << "\nCustomer " << cusHave[totalCustomer].name << " added successfully.\n" << endl;
    }
        totalCustomer += n;
}
// Hello
/*void Bank::addCustomer() {    //This may cause data overwriting
    int n;
    cout << "How many customers you want to add: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter details of customer " << i + 1 << ":" << endl;
        cout << "Enter account number: ";
        cin >> cusHave[totalCustomer].accountNumber;
        cout << "Enter name: ";
        cin >> cusHave[totalCustomer].name;
        cout << "Enter the balance: ";
        cin >> cusHave[totalCustomer].balance;
        cout << "\nCustomer " << cusHave[totalCustomer].name << " added successfully.\n" << endl;
        totalCustomer++;
    }
}*/

void Bank::displayCustomers() {
    for (int i = 0; i < totalCustomer; i++) {
        cout << "Customer " << i + 1 << " :" << endl;
        cout << "Account No.: " << cusHave[i].accountNumber << endl;
        cout << "Name: " << cusHave[i].name << endl;
        cout << "Balance: " << cusHave[i].balance << endl;
    }
}

void Bank::searchCustomer() {
    int ac;
    cout << "Enter the Account No. of Customer: ";
    cin >> ac;

    bool found = false;
    for (int i = 0; i < totalCustomer; i++) {
        if (ac == cusHave[i].accountNumber) {
            cout << "Customer with Acc. No. " << ac << " is:" << endl;
            cout << "Name: " << cusHave[i].name << endl;
            cout << "Balance: " << cusHave[i].balance << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Not found..." << endl;
    }
}

void Bank::depositMoney() {
    int ac;
    double amt;
    cout << "Enter the Account No.: ";
    cin >> ac;
    cout << "Enter the amount to deposit: ";
    cin >> amt;

    bool found = false;
    for (int i = 0; i < totalCustomer; i++) {
        if (ac == cusHave[i].accountNumber) {
            cusHave[i].balance += amt;
            cout << "Deposit successful. Updated balance: " << cusHave[i].balance << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "Account not found." << endl;
    }
}

void Bank::withdrawMoney() {
    int ac;
    double amt;
    cout << "Enter the Account No.: ";
    cin >> ac;
    cout << "Enter the amount to withdraw: ";
    cin >> amt;

    bool found = false;
    for (int i = 0; i < totalCustomer; i++) {
        if (ac == cusHave[i].accountNumber) {
            if (amt <= cusHave[i].balance) {
                cusHave[i].balance -= amt;
                cout << "Withdrawal successful. Remaining balance: " << cusHave[i].balance << endl;
            }
            else {
                cout << "Insufficient balance." << endl;
            }
            found = true;
        }
    }
    if (!found) {
        cout << "Account not found." << endl;
    }
}
void Bank::transferMoney() {
    int s_ac, r_ac;
    double amt, bal;
    cout << "Enter the sender Account No. : ";
    cin >> s_ac;
    cout << "Enter the reciever's Account No : ";
    cin >> r_ac;
    cout << "Enter the amount you want to transfer : ";
    cin >> amt;

    bool sender_found = false;
    bool reciever_found = false;

    for (int i = 0;i < totalCustomer;i++) {
        if (s_ac == cusHave[i].accountNumber) {
            sender_found = true;
            bal = cusHave[i].balance;
            if (bal < amt) {
                cout << "Insufficient Balance in Sender Account" << endl;
            }
        }
        else if (r_ac == cusHave[i].accountNumber) {
            reciever_found = true;
        }
    }
    if (sender_found == true && reciever_found == true && bal >= amt) {
        for (int i = 0; i < totalCustomer;i++) {
            if (s_ac == cusHave[i].accountNumber) {
                cusHave[i].balance -= amt;
                cout << "Money Debited form " << cusHave[i].name << " Account " << endl;
            }
            if (r_ac == cusHave[i].accountNumber) {
                cusHave[i].balance += amt;
                cout << "Money Credited to " << cusHave[i].name << " Account " << endl;
            }
        }
        cout << "Transaction Successful" << endl;
    }
    if (!sender_found) {
        cout << "Sender Account doesnot found" << endl;
    }
    if (!reciever_found) {
        cout << "Reciever Account doesnot found" << endl;
    }
    else if (!sender_found || !reciever_found) {
        cout << "Transaction failed!!!" << endl;
    }
}
/*void Bank::transferMoney() {  //Alternate for better apprach
    int s_ac, r_ac;
    double amt;
    cout << "Enter the sender Account No.: ";
    cin >> s_ac;
    cout << "Enter the receiver's Account No.: ";
    cin >> r_ac;
    cout << "Enter the amount to transfer: ";
    cin >> amt;

    int senderIndex = -1, receiverIndex = -1;

    for (int i = 0; i < totalCustomer; i++) {
        if (cusHave[i].accountNumber == s_ac) senderIndex = i;
        if (cusHave[i].accountNumber == r_ac) receiverIndex = i;
    }

    if (senderIndex != -1 && receiverIndex != -1) {
        if (cusHave[senderIndex].balance >= amt) {
            cusHave[senderIndex].balance -= amt;
            cusHave[receiverIndex].balance += amt;
            cout << "Transfer successful." << endl;
        }
        else {
            cout << "Insufficient balance in sender's account." << endl;
        }
    }
    else {
        cout << "One or both accounts not found." << endl;
    }
}*/
