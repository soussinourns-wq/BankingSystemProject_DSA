#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
#include "Date.h"
using namespace std;

struct Employee {
    string id;
    string name;
    string lastName;
    string address;
    float salary;
    Date hireDate;
    string branchCode;
};
#endif
