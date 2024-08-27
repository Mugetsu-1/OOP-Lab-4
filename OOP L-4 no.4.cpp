#include <iostream>
#include <string>
using namespace std;


class Account {
protected:
    string customer_name;
    int account_number;
    string account_type;
    double balance;

public:
   
    Account() : balance(0.0) {}

    
    void createAccount() {
        cout << "Enter customer name: ";
        getline(cin, customer_name);
        cout << "Enter account number: ";
        cin >> account_number;
        cout << "Enter account type (Saving/Current): ";
        cin >> account_type;
    }

    
    void displayAccount() const {
        cout << "Customer Name: " << customer_name << endl;
        cout << "Account Number: " << account_number << endl;
        cout << "Account Type: " << account_type << endl;
        cout << "Balance: $" << balance << endl;
    }

   
    void deposit(double amount) {
        balance += amount;
        cout << "Deposited $" << amount << ". Updated Balance: $" << balance << endl;
    }

   
    double getBalance() const {
        return balance;
    }

  
    virtual void withdraw(double amount) = 0;
};


class Saving_account : public Account {
public:
   
    Saving_account() {
        account_type = "Saving";
    }

   
    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". Updated Balance: $" << balance << endl;
        } else {
            cout << "Insufficient balance. Withdrawal failed." << endl;
        }
    }
};


class Current_account : public Account {
private:
    const double overdraft_limit = 500.0;

public:
   
    Current_account() {
        account_type = "Current";
    }

   
    void withdraw(double amount) override {
        if (balance - amount >= -overdraft_limit) {
            balance -= amount;
            cout << "Withdrew $" << amount << ". Updated Balance: $" << balance << endl;
        } else {
            cout << "Overdraft limit exceeded. Withdrawal failed." << endl;
        }
    }
};


int main() {
    int choice;
    double amount;
    char accountType;

  
    cout << "Enter account type (S for Saving, C for Current): ";
    cin >> accountType;
   

   
    Account* account;
    if (accountType == 'S' || accountType == 's') {
        account = new Saving_account();
    } else if (accountType == 'C' || accountType == 'c') {
        account = new Current_account();
    } else {
        cout << "Invalid account type." << endl;
        return 1;
    }

    
    account->createAccount();

    do {
        cout << "\nMenu:\n1. Deposit\n2. Withdraw\n3. Display Balance\n4. Exit\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter amount to deposit: ";
            cin >> amount;
            account->deposit(amount);
            break;
        case 2:
            cout << "Enter amount to withdraw: ";
            cin >> amount;
            account->withdraw(amount);
            break;
        case 3:
            account->displayAccount();
            break;
        case 4:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    delete account; 
    return 0;
}

