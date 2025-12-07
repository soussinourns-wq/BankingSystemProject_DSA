#include "CustomerInterface.h"
#include "LoanDoublyList.h"

extern int globalTransactionIdCounter;

void customerMenu(Account accounts[], int accountCount,
    LoanDList loanLists[], TransactionStack transactionStacks[],
    LoanRequestQueue& requestQueue)
{
    string accNumber;
    cout << "Enter your account number: ";
    cin >> accNumber;

    int index = findAccountIndex(accounts, accountCount, accNumber);
    if (index == -1) {
        cout << "Account not found.\n";
        return;
    }

    Account& acc = accounts[index];
    TransactionStack& stack = transactionStacks[index];
    LoanDList& loanList = loanLists[index];

    int choice;
    do {
        cout << "\n===== CUSTOMER MENU =====\n"
            << "1. View account information\n"
            << "2. Deposit money\n"
            << "3. Withdraw money\n"
            << "4. Show transactions (stack)\n"
            << "5. Request a loan\n"
            << "6. Show loan list\n"
            << "0. Exit\n"
            << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            displayAccount(acc);
        }
        else if (choice == 2) {
            float amount;
            cout << "Enter deposit amount: ";
            cin >> amount;

            if (deposit(acc, amount)) {
                Transaction t;
                t.transactionID = "TXD" + to_string(globalTransactionIdCounter++);
                t.accountNumber = acc.accountNumber;
                t.type = "deposit";
                t.amount = amount;
                t.date = { 7, 12, 2025 };
                pushTransaction(stack, t);
                cout << "Deposit successful.\n";
            }
            else {
                cout << "Invalid amount.\n";
            }
        }
        else if (choice == 3) {
            float amount;
            cout << "Enter withdrawal amount: ";
            cin >> amount;

            if (withdraw(acc, amount)) {
                Transaction t;
                t.transactionID = "TXW" + to_string(globalTransactionIdCounter++);
                t.accountNumber = acc.accountNumber;
                t.type = "withdraw";
                t.amount = amount;
                t.date = { 7, 12, 2025 };
                pushTransaction(stack, t);
                cout << "Withdrawal successful.\n";
            }
            else {
                cout << "Error: insufficient funds.\n";
            }
        }
        else if (choice == 4) {
            cout << "\n--- Recent Transactions ---\n";
            displayTransactionStack(stack);
        }
        else if (choice == 5) {
            LoanRequest r;
            r.accountNumber = acc.accountNumber;

            cout << "Enter loan type: ";
            cin >> r.loanType;

            cout << "Enter requested amount: ";
            cin >> r.amountRequested;

            cout << "Enter interest rate: ";
            cin >> r.rate;

            cout << "Enter term (months): ";
            cin >> r.termMonths;

            r.requestDate = { 7, 12, 2025 };

            enqueueLoanRequest(requestQueue, r);
            cout << "Loan request added to queue.\n";
        }
        else if (choice == 6) {
            cout << "\n--- Your Loans ---\n";
            displayLoans(loanList);
        }

    } while (choice != 0);
}
