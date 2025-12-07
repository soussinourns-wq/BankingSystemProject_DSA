#include "EmployeeOps.h"
#include <iostream>
#include <string>
#include "Account.h"
#include "LoanDoublyList.h"
#include "TransactionStack.h"

const int MAX_ACCOUNTS = 100;

using namespace std;

int findEmployeeIndex(Employee employees[], int count, string id) {
    for (int i = 0; i < count; i++) {
        if (employees[i].id == id)
            return i;
    }
    return -1;
}

bool addEmployee(Employee employees[], int& count, Employee e) {
    if (count >= MAX_EMPLOYEES) {
        return false;
    }
    employees[count] = e;
    count++;
    return true;
}

bool deleteEmployee(Employee employees[], int& count, string id) {
    int index = findEmployeeIndex(employees, count, id);

    if (index != -1) {
        for (int j = index; j < count - 1; j++)
            employees[j] = employees[j + 1];
        count--;
        return true;
    }
    return false;
}

bool modifyEmployee(Employee& emp, Employee updated) {
    emp = updated;
    return true;
}

void sortEmployeesByLastName(Employee employees[], int count) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (employees[i].lastName > employees[j].lastName) {
                Employee temp = employees[i];
                employees[i] = employees[j];
                employees[j] = temp;
            }
        }
    }
}

void displayEmployees(Employee employees[], int count) {
    cout << "\n--- Employee List ---\n";
    for (int i = 0; i < count; i++) {
        cout << employees[i].id << " | "
            << employees[i].name << " " << employees[i].lastName
            << " | Branch: " << employees[i].branchCode << endl;
    }
}

bool addAccount(Account accounts[], int& count,
    LoanDList loanLists[], TransactionStack stacks[]) {

    if (count >= MAX_ACCOUNTS) {
        cout << "\nError: Maximum number of accounts reached.\n";
        return false;
    }

    string holderName;
    string pin;
    string accountType;
    string iban;
    string branchCode;
    float initialBalance;
    int day, month, year;

    cout << "\n--- ADD NEW CUSTOMER ACCOUNT ---\n";
    cout << "Enter account holder name: ";
    cin >> holderName;
    cout << "Enter account type (savings/checking): ";
    cin >> accountType;
    cout << "Enter IBAN: ";
    cin >> iban;
    cout << "Enter branch code: ";
    cin >> branchCode;
    cout << "Enter new 4-digit PIN: ";
    cin >> pin;
    cout << "Enter initial deposit amount: ";
    cin >> initialBalance;
    cout << "Enter opening date (D M Y): ";
    cin >> day >> month >> year;

    Account& newAcc = accounts[count];
    newAcc.accountNumber = "ACC" + to_string(1000 + count + 1);
    newAcc.PIN = pin;
    newAcc.accountType = accountType;
    newAcc.IBAN = iban;
    newAcc.branchCode = branchCode;
    newAcc.holderName = holderName;
    newAcc.status = "active";
    newAcc.balance = initialBalance;
    newAcc.openingDate = { day, month, year };
    newAcc.loansHead = NULL;
    newAcc.transactionsTop = NULL;

    initLoanDList(loanLists[count]);
    initTransactionStack(stacks[count]);

    count++;

    cout << "\nSuccess! New Account Created:\n";
    cout << "Account Number: " << newAcc.accountNumber << endl;
    cout << "Account Holder: " << newAcc.holderName << endl;
    cout << "Initial Balance: " << newAcc.balance << endl;
    return true;
}
