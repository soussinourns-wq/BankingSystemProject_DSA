#ifndef FILE_MANAGER_H
#define FILE_MANAGER_H

#include <iostream>
#include <fstream>
#include "Account.h"
#include "Employee.h"
#include "Loan.h"
#include "Transaction.h"
#include "LoanRequest.h"

#include "LoanDoublyList.h"
#include "TransactionStack.h"
#include "LoanRequestQueue.h"

using namespace std;

// Loaders
void loadAccounts(Account accounts[], int& accountCount);
void loadEmployees(Employee employees[], int& employeeCount);
void loadLoans(LoanDList loanLists[], Account accounts[], int accountCount);
void loadTransactions(TransactionStack stacks[], Account accounts[], int accountCount);
void loadLoanRequests(LoanRequestQueue& q);

// Savers
void saveAccounts(Account accounts[], int accountCount);
void saveEmployees(Employee employees[], int employeeCount);
void saveLoans(LoanDList loanLists[], int accountCount, Account accounts[]);
void saveTransactions(TransactionStack stacks[], int accountCount, Account accounts[]);
void saveLoanRequests(LoanRequestQueue q);

#endif

