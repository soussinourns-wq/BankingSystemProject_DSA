#ifndef STATISTICS_H
#define STATISTICS_H

#include <iostream>
#include "Account.h"
#include "Employee.h"

#include "LoanDoublyList.h"
#include "LoanRequestQueue.h"
#include "TransactionStack.h"

using namespace std;

// Accounts
int countActiveAccounts(Account accounts[], int count);
float totalBankBalance(Account accounts[], int count);

// Employees
int countEmployees(int employeeCount);
float averageSalary(Employee employees[], int count);
float highestSalary(Employee employees[], int count);

// Loans
int countAllLoans(LoanDList loanLists[], int accountCount);
int countApprovedLoans(LoanDList loanLists[], int accountCount);
float highestLoanAmount(LoanDList loanLists[], int accountCount);

// Loan Requests
int countLoanRequests(LoanRequestQueue q);

// Transactions
int countTransactions(TransactionStack stacks[], int accountCount);

void showStatistics(Account accounts[], int accountCount,
    Employee employees[], int employeeCount,
    LoanDList loanLists[],
    TransactionStack stacks[],
    LoanRequestQueue q);



#endif

