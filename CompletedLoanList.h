#ifndef COMPLETED_LOAN_LIST_H
#define COMPLETED_LOAN_LIST_H

#include "Loan.h"

struct CompletedLoanNode {
    Loan data;
    CompletedLoanNode* next;
};

struct CompletedLoanList {
    CompletedLoanNode* head;
};

void initCompletedLoanList(CompletedLoanList& list);
void insertCompletedLoan(CompletedLoanList& list, Loan L);

#endif


