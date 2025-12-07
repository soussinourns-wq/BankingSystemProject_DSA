#include "TransactionStack.h"

void initTransactionStack(TransactionStack& s) {
    s.top = NULL;
}

bool isTransactionStackEmpty(TransactionStack s) {
    return (s.top == NULL);
}

void pushTransaction(TransactionStack& s, Transaction value) {
    TransactionNode* newNode = new TransactionNode;
    newNode->data = value;
    newNode->next = s.top;
    s.top = newNode;
}

bool popTransaction(TransactionStack& s, Transaction& value) {
    if (s.top == NULL)
        return false;

    TransactionNode* temp = s.top;
    value = temp->data;
    s.top = s.top->next;
    delete temp;
    return true;
}

void displayTransactionStack(TransactionStack s) {
    TransactionNode* temp = s.top;
    while (temp != NULL) {
        cout << temp->data.transactionID << " | "
            << temp->data.type << " | "
            << temp->data.amount << endl;
        temp = temp->next;
    }
}

void freeTransactionStack(TransactionStack& s) {
    TransactionNode* current = s.top;
    while (current != NULL) {
        TransactionNode* next = current->next;
        delete current;
        current = next;
    }
    s.top = NULL;
}