#include "LoanDoublyList.h"
#include <iostream>
using namespace std;

void initLoanDList(LoanDList& list) {
    list.head = NULL;
}

void insertLoanEnd(LoanDList& list, Loan value) {
    LoanNode* n = new LoanNode{ value, NULL, NULL };

    if (!list.head) {
        list.head = n;
        return;
    }

    LoanNode* cur = list.head;
    while (cur->next) cur = cur->next;

    cur->next = n;
    n->prev = cur;
}

void displayLoans(LoanDList list) {
    LoanNode* cur = list.head;
    while (cur) {
        cout << cur->data.loanID << " | "
            << cur->data.loanType << " | "
            << cur->data.principalAmount << " | "
            << cur->data.status << endl;
        cur = cur->next;
    }
}

void freeLoanDList(LoanDList& list) {
    LoanNode* current = list.head;
    while (current != NULL) {
        LoanNode* next = current->next;
        delete current;
        current = next;
    }
    list.head = NULL;
}
