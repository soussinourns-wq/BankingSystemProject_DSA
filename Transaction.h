#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <string>
#include "Date.h"
using namespace std;

struct Transaction {
    string transactionID;
    string accountNumber;
    string type;
    float amount;
    Date date;
};
#endif