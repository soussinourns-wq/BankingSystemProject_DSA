#include <iostream>
#include <fstream>
#include "Account.h"
#include "Employee.h"
#include "Loan.h"
#include "Transaction.h"
#include "LoanRequest.h"
#include "LoanDoublyList.h"
#include "TransactionStack.h"
#include "LoanRequestQueue.h"
#include "AccountOps.h"

using namespace std;

void loadAccounts(Account accounts[], int& count) {
    ifstream fin("accounts.txt");
    count = 0;

    if (!fin) return;

    while (fin >> accounts[count].accountNumber
        >> accounts[count].PIN
        >> accounts[count].accountType
        >> accounts[count].IBAN
        >> accounts[count].branchCode
        >> accounts[count].holderName
        >> accounts[count].openingDate.day
        >> accounts[count].openingDate.month
        >> accounts[count].openingDate.year
        >> accounts[count].status
        >> accounts[count].balance)
    {
        accounts[count].loansHead = NULL;
        accounts[count].transactionsTop = NULL;
        count++;
    }

    fin.close();
}

void saveAccounts(Account accounts[], int count) {
    ofstream fout("accounts.txt");

    for (int i = 0; i < count; i++) {
        fout << accounts[i].accountNumber << " "
            << accounts[i].PIN << " "
            << accounts[i].accountType << " "
            << accounts[i].IBAN << " "
            << accounts[i].branchCode << " "
            << accounts[i].holderName << " "
            << accounts[i].openingDate.day << " "
            << accounts[i].openingDate.month << " "
            << accounts[i].openingDate.year << " "
            << accounts[i].status << " "
            << accounts[i].balance << "\n";
    }

    fout.close();
}

void loadEmployees(Employee employees[], int& count) {
    ifstream fin("employees.txt");
    count = 0;

    if (!fin) return;

    while (fin >> employees[count].id
        >> employees[count].name
        >> employees[count].lastName
        >> employees[count].address
        >> employees[count].salary
        >> employees[count].hireDate.day
        >> employees[count].hireDate.month
        >> employees[count].hireDate.year
        >> employees[count].branchCode)
    {
        count++;
    }

    fin.close();
}

void saveEmployees(Employee employees[], int count) {
    ofstream fout("employees.txt");

    for (int i = 0; i < count; i++) {
        fout << employees[i].id << " "
            << employees[i].name << " "
            << employees[i].lastName << " "
            << employees[i].address << " "
            << employees[i].salary << " "
            << employees[i].hireDate.day << " "
            << employees[i].hireDate.month << " "
            << employees[i].hireDate.year << " "
            << employees[i].branchCode << "\n";
    }

    fout.close();
}

void loadLoans(LoanDList loanLists[], Account accounts[], int accountCount) {
    ifstream fin("loans.txt");
    if (!fin) return;

    Loan temp;
    string accNum;

    while (fin >> accNum
        >> temp.loanID
        >> temp.loanType
        >> temp.principalAmount
        >> temp.interestRate
        >> temp.amountPaid
        >> temp.remainingBalance
        >> temp.termMonths
        >> temp.startDate.day
        >> temp.startDate.month
        >> temp.startDate.year
        >> temp.endDate.day
        >> temp.endDate.month
        >> temp.endDate.year
        >> temp.status)
    {
        for (int i = 0; i < accountCount; i++) {
            if (accounts[i].accountNumber == accNum) {
                insertLoanEnd(loanLists[i], temp);
                break;
            }
        }
    }

    fin.close();
}

void saveLoans(LoanDList loanLists[], int accountCount, Account accounts[]) {
    ofstream fout("loans.txt");

    for (int i = 0; i < accountCount; i++) {
        LoanNode* cur = loanLists[i].head;
        while (cur != NULL) {
            fout << accounts[i].accountNumber << " "
                << cur->data.loanID << " "
                << cur->data.loanType << " "
                << cur->data.principalAmount << " "
                << cur->data.interestRate << " "
                << cur->data.amountPaid << " "
                << cur->data.remainingBalance << " "
                << cur->data.termMonths << " "
                << cur->data.startDate.day << " "
                << cur->data.startDate.month << " "
                << cur->data.startDate.year << " "
                << cur->data.endDate.day << " "
                << cur->data.endDate.month << " "
                << cur->data.endDate.year << " "
                << cur->data.status << "\n";

            cur = cur->next;
        }
    }

    fout.close();
}

void loadTransactions(TransactionStack stacks[], Account accounts[], int accountCount) {
    ifstream fin("transactions.txt");
    if (!fin) return;

    Transaction t;

    while (fin >> t.accountNumber
        >> t.transactionID
        >> t.type
        >> t.amount
        >> t.date.day
        >> t.date.month
        >> t.date.year)
    {
        int idx = findAccountIndex(accounts, accountCount, t.accountNumber);

        if (idx != -1) {
            pushTransaction(stacks[idx], t);
        }
    }

    fin.close();
}

void saveTransactions(TransactionStack stacks[], int count, Account accounts[]) {
    ofstream fout("transactions.txt");
    if (!fout) return;

    for (int i = 0; i < count; i++) {
        TransactionNode* cur = stacks[i].top;
        while (cur != NULL) {
            fout << accounts[i].accountNumber << " "
                << cur->data.transactionID << " "
                << cur->data.type << " "
                << cur->data.amount << " "
                << cur->data.date.day << " "
                << cur->data.date.month << " "
                << cur->data.date.year << "\n";

            cur = cur->next;
        }
    }

    fout.close();
}

void loadLoanRequests(LoanRequestQueue& q) {
    ifstream fin("loan_requests.txt");
    if (!fin) return;

    LoanRequest R;

    while (fin >> R.accountNumber
        >> R.loanType
        >> R.amountRequested
        >> R.rate
        >> R.termMonths
        >> R.requestDate.day
        >> R.requestDate.month
        >> R.requestDate.year)
    {
        enqueueLoanRequest(q, R);
    }

    fin.close();
}

void saveLoanRequests(LoanRequestQueue q) {
    ofstream fout("loan_requests.txt");
    if (!fout) return;

    LoanRequestNode* cur = q.front;

    while (cur) {
        fout << cur->data.accountNumber << " "
            << cur->data.loanType << " "
            << cur->data.amountRequested << " "
            << cur->data.rate << " "
            << cur->data.termMonths << " "
            << cur->data.requestDate.day << " "
            << cur->data.requestDate.month << " "
            << cur->data.requestDate.year << "\n";
        cur = cur->next;
    }

    fout.close();
}
