#include "CompletedLoanList.h"

void initCompletedLoanList(CompletedLoanList& list) {
    list.head = NULL;
}

void insertCompletedLoan(CompletedLoanList& list, Loan L) {
    CompletedLoanNode* n = new CompletedLoanNode{ L, NULL };

    if (!list.head) {
        list.head = n;
        return;
    }

    CompletedLoanNode* cur = list.head;
    while (cur->next) cur = cur->next;
    cur->next = n;
}