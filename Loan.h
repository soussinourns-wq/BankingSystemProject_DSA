#ifndef LOAN_H
#define LOAN_H
#include <string>
#include "Date.h"
using namespace std;

struct Loan {
    string loanID;
    string loanType;
    float principalAmount;
    float interestRate;
    float amountPaid;
    float remainingBalance;
    int termMonths;
    Date startDate;
    Date endDate;
    string status;
};
#endif