#include "LoanRequestQueue.h"
#include <iostream>
using namespace std;

void initLoanRequestQueue(LoanRequestQueue& q) {
    q.front = q.rear = NULL;
}

bool isLoanRequestQueueEmpty(LoanRequestQueue q) {
    return q.front == NULL;
}

void enqueueLoanRequest(LoanRequestQueue& q, LoanRequest R) {
    LoanRequestNode* n = new LoanRequestNode{ R, NULL };

    if (!q.rear)
        q.front = q.rear = n;
    else {
        q.rear->next = n;
        q.rear = n;
    }
}

bool dequeueLoanRequest(LoanRequestQueue& q, LoanRequest& out) {
    if (!q.front) return false;

    LoanRequestNode* temp = q.front;
    out = temp->data;

    q.front = q.front->next;
    if (!q.front) q.rear = NULL;

    delete temp;
    return true;
}

void displayLoanRequestQueue(LoanRequestQueue q) {
    LoanRequestNode* cur = q.front;
    while (cur) {
        cout << cur->data.accountNumber << " | "
            << cur->data.loanType << " | "
            << cur->data.amountRequested << " | "
            << cur->data.rate << "% | "
            << cur->data.termMonths << " months" << endl;
        cur = cur->next;
    }
}

void freeLoanRequestQueue(LoanRequestQueue& q) {
    LoanRequestNode* current = q.front;
    while (current != NULL) {
        LoanRequestNode* next = current->next;
        delete current;
        current = next;
    }
    q.front = q.rear = NULL;
}
