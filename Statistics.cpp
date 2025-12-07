#include "Statistics.h"
#include "LoanDoublyList.h"
#include "TransactionStack.h"

int countActiveAccounts(Account accounts[], int count) {
    int active = 0;
    for (int i = 0; i < count; i++) {
        if (accounts[i].status == "active")
            active++;
    }
    return active;
}

float totalBankBalance(Account accounts[], int count) {
    float sum = 0;
    for (int i = 0; i < count; i++)
        sum += accounts[i].balance;
    return sum;
}

int countEmployees(int employeeCount) {
    return employeeCount;
}

float averageSalary(Employee employees[], int count) {
    if (count == 0) return 0;

    float total = 0;
    for (int i = 0; i < count; i++)
        total += employees[i].salary;

    return total / count;
}

float highestSalary(Employee employees[], int count) {
    if (count == 0) return 0;

    float max = employees[0].salary;
    for (int i = 1; i < count; i++)
        if (employees[i].salary > max)
            max = employees[i].salary;

    return max;
}

int countAllLoans(LoanDList loanLists[], int accountCount) {
    int total = 0;

    for (int i = 0; i < accountCount; i++) {
        LoanNode* cur = loanLists[i].head;
        while (cur != NULL) {
            total++;
            cur = cur->next;
        }
    }
    return total;
}

int countApprovedLoans(LoanDList loanLists[], int accountCount) {
    int total = 0;

    for (int i = 0; i < accountCount; i++) {
        LoanNode* cur = loanLists[i].head;
        while (cur != NULL) {
            if (cur->data.status == "approved")
                total++;
            cur = cur->next;
        }
    }
    return total;
}

float highestLoanAmount(LoanDList loanLists[], int accountCount) {
    float max = 0;

    for (int i = 0; i < accountCount; i++) {
        LoanNode* cur = loanLists[i].head;
        while (cur != NULL) {
            if (cur->data.principalAmount > max)
                max = cur->data.principalAmount;
            cur = cur->next;
        }
    }
    return max;
}

int countLoanRequests(LoanRequestQueue q) {
    int count = 0;
    LoanRequestNode* cur = q.front;

    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

int countTransactions(TransactionStack stacks[], int accountCount) {
    int total = 0;

    for (int i = 0; i < accountCount; i++) {
        TransactionNode* cur = stacks[i].top;
        while (cur != NULL) {
            total++;
            cur = cur->next;
        }
    }

    return total;
}

void showStatistics(Account accounts[], int accountCount,
    Employee employees[], int employeeCount,
    LoanDList loanLists[],
    TransactionStack stacks[],
    LoanRequestQueue q) {

    cout << "\n======= STATISTICS =======\n";

    cout << "Total Accounts: " << accountCount << endl;
    cout << "Active Accounts: " << countActiveAccounts(accounts, accountCount) << endl;

    cout << "Total Bank Balance: " << totalBankBalance(accounts, accountCount) << " DT\n";

    cout << "Employee Count: " << countEmployees(employeeCount) << endl;
    cout << "Average Salary: " << averageSalary(employees, employeeCount) << " DT\n";
    cout << "Highest Salary: " << highestSalary(employees, employeeCount) << " DT\n";

    cout << "Total Loans: " << countAllLoans(loanLists, accountCount) << endl;
    cout << "Approved Loans: " << countApprovedLoans(loanLists, accountCount) << endl;
    cout << "Highest Loan Amount: " << highestLoanAmount(loanLists, accountCount) << " DT\n";

    cout << "Pending Loan Requests: " << countLoanRequests(q) << endl;

    cout << "Total Transactions: " << countTransactions(stacks, accountCount) << endl;
}
