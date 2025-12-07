#ifndef ACCOUNT_OPS_H
#define ACCOUNT_OPS_H

#include <iostream>
#include "Account.h"
using namespace std;

int findAccountIndex(Account accounts[], int count, string accountNumber);
void displayAccount(const Account& a);
void changeAccountStatus(Account& a, string newStatus);

bool deposit(Account& a, float amount);
bool withdraw(Account& a, float amount);

#endif
