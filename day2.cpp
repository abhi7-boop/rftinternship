#include <iostream>
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::fixed;
using std::setprecision;

class BankAccount {
private:
    string accountNumber; // Data: Account Number
    string holderName;    // Data: Holder Name
    double balance;       // Data: Balance
    const double MIN_BALANCE = 500.0; // Bonus: Add minimum balance rule

public:
    BankAccount(string accNum, string name, double initialBalance) {
        accountNumber = accNum;
        holderName = name;
        balance = (initialBalance >= MIN_BALANCE) ? initialBalance : MIN_BALANCE;
    }

    // Function: Deposit(Amount)
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << " | New Balance: $" << balance << endl;
        }
    }

    // Function: Withdraw(Amount)
    void withdraw(double amount) {
        // Bonus: Prevent withdrawal if balance < amount
        if (amount > balance) {
            cout << "Error: Insufficient funds." << endl;
        } else if (balance - amount < MIN_BALANCE) {
            cout << "Error: Must maintain minimum balance of $" << MIN_BALANCE << endl;
        } else {
            balance -= amount;
            cout << "Withdrew: $" << amount << " | New Balance: $" << balance << endl;
        }
    }

    // Function: DisplayBalance()
    void displayBalance() {
        cout << "\n--- Account Summary ---" << endl;
        cout << "Holder: " << holderName << " | Account: " << accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

int main() {
    // State Management: Initializing account
    BankAccount myAcc("889911", "Alex Smith", 1200.0);
    int choice;
    double amt;

    // Program should allow multiple transactions
    do {
        cout << "\n1. Deposit\n2. Withdraw\n3. Balance\n4. Exit\nChoice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Amount: "; cin >> amt; myAcc.deposit(amt);
        } else if (choice == 2) {
            cout << "Amount: "; cin >> amt; myAcc.withdraw(amt);
        } else if (choice == 3) {
            myAcc.displayBalance();
        }
    } while (choice != 4);

    return 0;
}