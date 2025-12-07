#ifndef LOAN_REQUEST_QUEUE_H
#define LOAN_REQUEST_QUEUE_H

#include "LoanRequest.h"

struct LoanRequestNode {
    LoanRequest data;
    LoanRequestNode* next;
};

struct LoanRequestQueue {
    LoanRequestNode* front;
    LoanRequestNode* rear;
};

void initLoanRequestQueue(LoanRequestQueue& q);
bool isLoanRequestQueueEmpty(LoanRequestQueue q);
void enqueueLoanRequest(LoanRequestQueue& q, LoanRequest R);
bool dequeueLoanRequest(LoanRequestQueue& q, LoanRequest& out);
void displayLoanRequestQueue(LoanRequestQueue q);
void freeLoanRequestQueue(LoanRequestQueue& q);
#endif


