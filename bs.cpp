// Bs.cpp - Main Program
#include <iostream>
#include "Account.h"
#include "Employee.h"
#include "Loan.h"
#include "Transaction.h"
#include "LoanRequest.h"
#include "LoanDoublyList.h"
#include "TransactionStack.h"
#include "LoanRequestQueue.h"
#include "AccountOps.h"
#include "EmployeeOps.h"
#include "LoanOps.h"
#include "TransactionOps.h"
#include "CustomerInterface.h"
#include "EmployeeInterface.h"
#include "FileManager.h"

using namespace std;

const int MAX_ACCOUNTS = 100;
int globalTransactionIdCounter = 1000;

int main() {
    // DATA STRUCTURES
    Account accounts[MAX_ACCOUNTS];
    Employee employees[MAX_EMPLOYEES];

    int accountCount = 0;
    int employeeCount = 0;

    // One loan list PER ACCOUNT
    LoanDList loanLists[MAX_ACCOUNTS];

    // One transaction stack PER ACCOUNT
    TransactionStack transactionStacks[MAX_ACCOUNTS];

    // Queue of loan requests
    LoanRequestQueue loanQueue;
    initLoanRequestQueue(loanQueue);

    // INITIALIZE STRUCTURES
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        initLoanDList(loanLists[i]);
        initTransactionStack(transactionStacks[i]);
    }

    // LOAD ALL FILES
    loadAccounts(accounts, accountCount);
    loadEmployees(employees, employeeCount);
    loadLoans(loanLists, accounts, accountCount);
    loadTransactions(transactionStacks, accounts, accountCount);
    loadLoanRequests(loanQueue);

    cout << "\n*** DATA LOADED SUCCESSFULLY ***\n";

    // MAIN MENU
    int choice;
    do {
        cout << "\n========== BANK MANAGEMENT SYSTEM ==========\n"
            << "1. Customer Menu\n"
            << "2. Employee Menu\n"
            << "0. Exit and Save\n"
            << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            customerMenu(accounts, accountCount,
                loanLists, transactionStacks,
                loanQueue);
        }
        else if (choice == 2) {
            // CORRECTED: Pass accountCount by reference
            employeeMenu(accounts, accountCount,
                employees, employeeCount,
                loanLists, transactionStacks,
                loanQueue);
        }

    } while (choice != 0);

    // SAVE ALL FILES
    saveAccounts(accounts, accountCount);
    saveEmployees(employees, employeeCount);
    saveLoans(loanLists, accountCount, accounts);
    saveTransactions(transactionStacks, accountCount, accounts);
    saveLoanRequests(loanQueue);

    // CLEAN UP DYNAMIC MEMORY
    for (int i = 0; i < accountCount; i++) {
        freeLoanDList(loanLists[i]);
        freeTransactionStack(transactionStacks[i]);
    }
    freeLoanRequestQueue(loanQueue);

    cout << "\n*** ALL DATA SAVED. PROGRAM CLOSED. ***\n";

    return 0;
}