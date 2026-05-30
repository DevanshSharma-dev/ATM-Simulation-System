#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;


class Account {
private:
    string accountNo;
    string pin;
    string accountHolderName;
    double balance;
    vector<string> transactionHistory;

public:
    Account(string accNo, string p, string name, double initialBalance) {
        accountNo = accNo;
        pin = p;
        accountHolderName = name;
        balance = initialBalance;
        transactionHistory.push_back("Account opened with balance: ₹" + to_string((int)initialBalance));
    }

    string getAccountNo() { return accountNo; }
    string getAccountHolderName() { return accountHolderName; }
    
    bool validatePIN(string enteredPin) {
        return pin == enteredPin;
    }

    double getBalance() { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back("Deposited: ₹" + to_string((int)amount));
            cout << "\n[SUCCESS] ₹" << amount << " deposited successfully!\n";
        } else {
            cout << "\n[ERROR] Invalid deposit amount!\n";
        }
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "\n[ERROR] Invalid withdrawal amount!\n";
        } else if (amount > balance) {
            cout << "\n[ERROR] Insufficient balance! Current Balance: ₹" << balance << "\n";
        } else {
            balance -= amount;
            transactionHistory.push_back("Withdrawn: ₹" + to_string((int)amount));
            cout << "\n[SUCCESS] ₹" << amount << " withdrawn successfully!\n";
        }
    }

    void displayHistory() {
        cout << "\n--- Transaction History for " << accountHolderName << " ---\n";
        if (transactionHistory.empty()) {
            cout << "No transactions yet.\n";
        } else {
            for (const string& tx : transactionHistory) {
                cout << "- " << tx << "\n";
            }
        }
        cout << "-------------------------------------------\n";
    }
};


class ATM {
private:
    vector<Account> accounts;

public:
    void addAccount(Account acc) {
        accounts.push_back(acc);
    }

    Account* findAccount(string accNo) {
        for (int i = 0; i < accounts.size(); i++) {
            if (accounts[i].getAccountNo() == accNo) {
                return &accounts[i];
            }
        }
        return nullptr;
    }

    void start() {
        string accNo, pin;
        cout << "===========================================\n";
        cout << "       WELCOME TO THE ATM SIMULATION       \n";
        cout << "===========================================\n";
        cout << "Enter Account Number: ";
        cin >> accNo;

        Account* currentAcc = findAccount(accNo);

        if (currentAcc == nullptr) {
            cout << "\n[ERROR] Account not found!\n";
            return;
        }

        cout << "Enter 4-Digit PIN: ";
        cin >> pin;

        if (!currentAcc->validatePIN(pin)) {
            cout << "\n[ERROR] Incorrect PIN! Access Denied.\n";
            return;
        }

        int choice;
        do {
            cout << "\n===========================================\n";
            cout << "WELCOME " << currentAcc->getAccountHolderName() << " (Acc: " << currentAcc->getAccountNo() << ")\n";
            cout << "===========================================\n";
            cout << "1. Check Balance\n";
            cout << "2. Deposit Money\n";
            cout << "3. Withdraw Money\n";
            cout << "4. Transaction History\n";
            cout << "5. Exit\n";
            cout << "Choose an option (1-5): ";
            cin >> choice;

            switch (choice) {
                case 1:
                    cout << "\nYour Current Balance is: ₹" << fixed << setprecision(2) << currentAcc->getBalance() << "\n";
                    break;
                case 2: {
                    double depAmt;
                    cout << "Enter amount to deposit: ₹";
                    cin >> depAmt;
                    currentAcc->deposit(depAmt);
                    break;
                }
                case 3: {
                    double witAmt;
                    cout << "Enter amount to withdraw: ₹";
                    cin >> witAmt;
                    currentAcc->withdraw(witAmt);
                    break;
                }
                case 4:
                    currentAcc->displayHistory();
                    break;
                case 5:
                    cout << "\nThank you for using our ATM service. Have a great day!\n";
                    break;
                default:
                    cout << "\n[ERROR] Invalid Choice! Try again.\n";
            }
        } while (choice != 5);
    }
};

int main() {
    ATM myATM;

    
    Account acc1("1001", "4321", "Devansh Sharma", 25000.0);
    Account acc2("1002", "1111", "Divya Sharma", 15000.0);

    myATM.addAccount(acc1);
    myATM.addAccount(acc2);

    myATM.start();

    return 0;
}