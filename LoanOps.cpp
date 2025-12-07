#include "LoanOps.h"
#include "CompletedLoanList.h"

void changeLoanStatus(Loan& loan, string newStatus) {
    loan.status = newStatus;
}

void completeLoan(Loan& loan, CompletedLoanList& list) {
    loan.status = "completed";
    insertCompletedLoan(list, loan);
}