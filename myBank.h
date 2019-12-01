#include <stdio.h>

enum boolean {FALSE,TRUE};

#define NUMBER_OF_ACCOUNTS 50

extern double bank[NUMBER_OF_ACCOUNTS][2];

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
