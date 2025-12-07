#ifndef LOAN_REQUEST_H
#define LOAN_REQUEST_H
#include <string>
#include "Date.h"
using namespace std;

struct LoanRequest {
    string accountNumber;
    string loanType;
    float amountRequested;
    float rate;
    int termMonths;
    Date requestDate;
};
#endif