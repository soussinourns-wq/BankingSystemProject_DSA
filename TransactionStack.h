#ifndef TRANSACTION_STACK_H
#define TRANSACTION_STACK_H

#include <iostream>
#include "Transaction.h"
using namespace std;

struct TransactionNode {
    Transaction data;
    TransactionNode* next;
};

struct TransactionStack {
    TransactionNode* top;
};

// DECLARATIONS ONLY
void initTransactionStack(TransactionStack& s);
bool isTransactionStackEmpty(TransactionStack s);
void pushTransaction(TransactionStack& s, Transaction value);
bool popTransaction(TransactionStack& s, Transaction& value);
void displayTransactionStack(TransactionStack s);
void freeTransactionStack(TransactionStack& s);
#endif


