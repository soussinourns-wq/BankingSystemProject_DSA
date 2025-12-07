#include "TransactionOps.h"

bool applyTransaction(Account& acc, Transaction t) {
    if (t.type == "deposit")
        return deposit(acc, t.amount);
    else if (t.type == "withdraw")
        return withdraw(acc, t.amount);

    return false;
}

bool undoLastTransaction(Account& acc, TransactionStack& stack) {
    Transaction last;

    if (!popTransaction(stack, last))
        return false;

    if (last.type == "deposit")
        acc.balance -= last.amount;
    else if (last.type == "withdraw")
        acc.balance += last.amount;

    return true;
}