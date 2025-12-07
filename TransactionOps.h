#ifndef TRANSACTION_OPS_H
#define TRANSACTION_OPS_H

#include <iostream>
#include "Transaction.h"
#include "Account.h"
#include "TransactionStack.h"
#include "AccountOps.h"
using namespace std;

bool applyTransaction(Account& acc, Transaction t);
bool undoLastTransaction(Account& acc, TransactionStack& stack);

#endif


