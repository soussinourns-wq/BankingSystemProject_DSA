#ifndef LOAN_DOUBLY_LIST_H
#define LOAN_DOUBLY_LIST_H

#include "Loan.h"

struct LoanNode {
    Loan data;
    LoanNode* prev;
    LoanNode* next;
};

struct LoanDList {
    LoanNode* head;
};

void initLoanDList(LoanDList& list);
void insertLoanEnd(LoanDList& list, Loan value);
void displayLoans(LoanDList list);
void freeLoanDList(LoanDList& list);
#endif

