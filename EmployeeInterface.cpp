#include "EmployeeInterface.h"
#include "LoanRequestQueue.h"
#include "LoanDoublyList.h"
#include "Statistics.h"
#include "AccountOps.h"
#include "EmployeeOps.h"
#include <iostream>
#include <limits>

using namespace std;

void employeeMenu(Account accounts[], int& accountCount,
    Employee employees[], int& employeeCount,
    LoanDList loanLists[], TransactionStack transactionStacks[],
    LoanRequestQueue& loanQueue)
{
    int choice;
    do {
        cout << "\n===== EMPLOYEE MENU =====\n"
            << "1. Show all accounts\n"
            << "2. Show all employees\n"
            << "3. Add employee\n"
            << "4. Delete employee\n"
            << "5. Modify employee\n"
            << "6. Process next loan request\n"
            << "7. View all loan requests (queue)\n"
            << "8. View statistics\n"
            << "9. Add New Customer Account\n"
            << "0. Exit\n"
            << "Choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }

        if (choice == 1) {
            cout << "\n--- ALL ACCOUNTS ---\n";
            for (int i = 0; i < accountCount; i++)
                displayAccount(accounts[i]);
            cout << "\nPress Enter to return to Employee Menu...";
            cin.ignore(100, '\n');
            cin.get();
        }
        else if (choice == 2) {
            cout << "\n--- ALL EMPLOYEES ---\n";
            displayEmployees(employees, employeeCount);
            cout << "\nPress Enter to return to Employee Menu...";
            cin.ignore(100, '\n');
            cin.get();
        }
        else if (choice == 3) {
            Employee e;
            cout << "Enter ID: "; cin >> e.id;
            cout << "Enter name: "; cin >> e.name;
            cout << "Enter last name: "; cin >> e.lastName;
            cout << "Enter address: "; cin >> e.address;
            cout << "Enter salary: "; cin >> e.salary;
            cout << "Enter branch code: "; cin >> e.branchCode;
            e.hireDate = { 7, 12, 2025 };

            if (addEmployee(employees, employeeCount, e))
                cout << "\nEmployee added successfully.\n";
            else
                cout << "\nError: Could not add employee (array full).\n";
        }
        else if (choice == 4) {
            string id;
            cout << "Enter employee ID to delete: ";
            cin >> id;

            if (deleteEmployee(employees, employeeCount, id))
                cout << "Employee removed.\n";
            else
                cout << "Error: Employee ID not found.\n";
        }
        else if (choice == 5) {
            string id;
            cout << "Enter employee ID to modify: ";
            cin >> id;

            int idx = findEmployeeIndex(employees, employeeCount, id);

            if (idx != -1) {
                string newAddress;
                cout << "Employee found. Enter new address: ";
                cin >> newAddress;
                employees[idx].address = newAddress;
                cout << "Employee address updated.\n";
            }
            else {
                cout << "Error: Employee ID not found.\n";
            }
        }
        else if (choice == 6) {
            if (isLoanRequestQueueEmpty(loanQueue)) {
                cout << "\nNo loan requests in the queue.\n";
            }
            else {
                LoanRequest req;
                dequeueLoanRequest(loanQueue, req);

                cout << "\nProcessing loan request for account " << req.accountNumber << endl;

                int idx = findAccountIndex(accounts, accountCount, req.accountNumber);

                if (idx != -1) {
                    Loan newLoan;
                    newLoan.loanID = "LOAN" + to_string(1000 + idx);
                    newLoan.loanType = req.loanType;
                    newLoan.principalAmount = req.amountRequested;
                    newLoan.interestRate = req.rate;
                    newLoan.amountPaid = 0;
                    newLoan.remainingBalance = req.amountRequested;
                    newLoan.termMonths = req.termMonths;
                    newLoan.startDate = { 7, 12, 2025 };
                    newLoan.endDate = { 7, 12, 2025 + (req.termMonths / 12) };
                    newLoan.status = "approved";

                    insertLoanEnd(loanLists[idx], newLoan);
                    cout << "Success! Loan approved and added to account " << req.accountNumber << ".\n";
                }
                else {
                    cout << "Error: Account not found for loan request.\n";
                }
            }
            cout << "\nPress Enter to return to Employee Menu...";
            cin.ignore(100, '\n');
            cin.get();
        }
        else if (choice == 7) {
            cout << "\n--- PENDING LOAN REQUESTS ---\n";
            displayLoanRequestQueue(loanQueue);
            cout << "\nPress Enter to return to Employee Menu...";
            cin.ignore(100, '\n');
            cin.get();
        }
        else if (choice == 8) {
            showStatistics(
                accounts, accountCount,
                employees, employeeCount,
                loanLists,
                transactionStacks,
                loanQueue
            );
            cout << "\nPress Enter to return to Employee Menu...";
            cin.ignore(100, '\n');
            cin.get();
        }
        else if (choice == 9) {
            addAccount(accounts, accountCount, loanLists, transactionStacks);
            cout << "\nPress Enter to return to Employee Menu...";
            cin.ignore(100, '\n');
            cin.get();
        }
        else if (choice == 0) {
            cout << "Logging out of Employee Interface.\n";
        }
        else {
            cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 0);
}
