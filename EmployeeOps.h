#ifndef EMPLOYEE_OPS_H
#define EMPLOYEE_OPS_H

#include <iostream>
#include "Employee.h"
#include "Account.h"
#include "LoanDoublyList.h"
#include "TransactionStack.h"
const int MAX_EMPLOYEES = 100;
using namespace std;

bool addEmployee(Employee employees[], int& count, Employee e);
bool deleteEmployee(Employee employees[], int& count, string id);
bool modifyEmployee(Employee& emp, Employee updated);
int findEmployeeIndex(Employee employees[], int count, string id);
void sortEmployeesByLastName(Employee employees[], int count);
void displayEmployees(Employee employees[], int count);
bool addAccount(Account accounts[], int& count, LoanDList loanLists[], TransactionStack stacks[]);
#endif
