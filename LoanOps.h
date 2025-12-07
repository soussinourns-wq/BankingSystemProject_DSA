#ifndef LOAN_OPS_H
#define LOAN_OPS_H

#include <iostream>
#include "Loan.h"
#include "LoanDoublyList.h"
#include "CompletedLoanList.h"
using namespace std;

void changeLoanStatus(Loan& loan, string newStatus);
void completeLoan(Loan& loan, CompletedLoanList& list);

#endif


