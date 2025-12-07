#include "AccountOps.h"

int findAccountIndex(Account accounts[], int count, string accountNumber) {
    for (int i = 0; i < count; i++) {
        if (accounts[i].accountNumber == accountNumber)
            return i;
    }
    return -1;
}

void displayAccount(const Account& a) {
    cout << "\n--- Account Information ---\n";
    cout << "Account Number: " << a.accountNumber << endl;
    cout << "Holder: " << a.holderName << endl;
    cout << "Balance: " << a.balance << endl;
    cout << "Status: " << a.status << endl;
}

void changeAccountStatus(Account& a, string newStatus) {
    a.status = newStatus;
}

bool deposit(Account& a, float amount) {
    if (amount <= 0) return false;
    a.balance += amount;
    return true;
}

bool withdraw(Account& a, float amount) {
    if (amount <= 0 || amount > a.balance) return false;
    a.balance -= amount;
    return true;
}
