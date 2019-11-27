#include <stdio.h>

enum boolean {FALSE,TRUE};


int isFull();

int indexOpenBack();

void openAccountOfBank(double amount);

void balance(int numberAccount);

void depositToAccount(int numberAccount,double amount);

int indexOfAccount(int numberAccount);

void withdrawal(int numberAccount,double amount);

void closeAccount(int numberAccount);

int isOpenAccount(int accountIndex);

void addInterest(double percentage);

double roundToFirstTwoDigits(double num);

void printOpenAccounts();

void closeAccounts();
