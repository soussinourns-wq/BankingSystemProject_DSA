#ifndef CUSTOMER_INTERFACE_H
#define CUSTOMER_INTERFACE_H

#include <iostream>
#include "Account.h"
#include "Loan.h"
#include "Transaction.h"

#include "TransactionStack.h"
#include "LoanDoublyList.h"
#include "LoanRequestQueue.h"

#include "AccountOps.h"
#include "TransactionOps.h"
#include "LoanOps.h"

using namespace std;

void customerMenu(Account accounts[], int accountCount,
    LoanDList loanLists[], TransactionStack transactionStacks[],
    LoanRequestQueue& requestQueue);

#endif
