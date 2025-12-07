#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include "Date.h"
using namespace std;

struct LoanNode;
struct TransactionNode;

struct Account {
    string accountNumber;
    string PIN;
    string accountType;
    string IBAN;
    string branchCode;
    string holderName;
    Date openingDate;
    string status;
    float balance;
    LoanNode* loansHead;
    TransactionNode* transactionsTop;
};
#endif
