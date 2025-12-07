// EmployeeInterface.h
#ifndef EMPLOYEE_INTERFACE_H
#define EMPLOYEE_INTERFACE_H

#include <iostream>
#include "Account.h"
#include "Employee.h"
#include "LoanDoublyList.h"
#include "TransactionStack.h"
#include "LoanRequestQueue.h"
#include "EmployeeOps.h"
#include "AccountOps.h"
#include "LoanOps.h"

using namespace std;

// CORRECTED: Changed accountCount to int& (pass by reference)
void employeeMenu(Account accounts[], int& accountCount,
    Employee employees[], int& employeeCount,
    LoanDList loanLists[], TransactionStack transactionStacks[],
    LoanRequestQueue& loanQueue);

#endif