#include <stdio.h>
#include "myBank.h"



#define ACCOUNT_IS_NOT_OPEN "the account is not open\n"

double bank[NUMBER_OF_ACCOUNTS][2];
int counter = 0;


void openAccountOfBank(double amount)
{	
	int indexOfNewAccount = 0;
	if(counter < NUMBER_OF_ACCOUNTS)
	{
		indexOfNewAccount = indexOpenBack();
		bank[indexOfNewAccount][0] = roundToFirstTwoDigits(amount);
		bank[indexOfNewAccount][1] = (double)TRUE;
	 	printf("The number of the bank account: %d\n",indexOfNewAccount+901);
		counter++;
		 
	}
	else
	{
		printf("bank is full\n");
	}
}

void balance(int numberAccount)
{	
	int accountIndex = indexOfAccount(numberAccount);
	int openAccount = isOpenAccount(accountIndex);
	double amountOfTheNumberAccount = 0.0;
	if(openAccount == TRUE)
	{
		amountOfTheNumberAccount = bank[accountIndex][0];
		printf("the balance is: %.2f\n",amountOfTheNumberAccount);
	}
	else
	{
		printf(ACCOUNT_IS_NOT_OPEN);
	}
	
}



void depositToAccount(int numberAccount,double amount)
{
	int accountIndex = indexOfAccount(numberAccount);
	int openAccount = isOpenAccount(accountIndex);
	if(openAccount == TRUE)
	{
		bank[accountIndex][0] += roundToFirstTwoDigits(amount);
		printf("the balance is: %.2lf\n", bank[accountIndex][0]);
	}
	else
	{
		printf(ACCOUNT_IS_NOT_OPEN);
	}
}


void withdrawal(int numberAccount,double amount)
{
	int accountIndex = indexOfAccount(numberAccount);
	int openAccount = isOpenAccount(accountIndex);
	if(openAccount == TRUE)
	{
		if(amount <= bank[accountIndex][0])
		{
			bank[accountIndex][0] -= roundToFirstTwoDigits(amount);
			printf("the balance is: %.2lf\n", bank[accountIndex][0]);
		}
		else
		{
			printf("not enough of cash in the number of bank\n");
		}
	}
	else
	{
		printf(ACCOUNT_IS_NOT_OPEN);
	}
}

void closeAccount(int numberAccount)
{
	int accountIndex = indexOfAccount(numberAccount);
	int openAccount = isOpenAccount(accountIndex);
	if(openAccount == TRUE)
	{
		bank[accountIndex][1] = FALSE;
	}
	else
	{
		printf(ACCOUNT_IS_NOT_OPEN);
	}
	
}

void addInterest(double percentage)
{
	double balance = 0;
	//((percentage/100)+1)*balance
	for(int i = 0; i<NUMBER_OF_ACCOUNTS; i++)
	{
		
		if(isOpenAccount(i))
		{
			balance = bank[i][0];
			bank[i][0] = roundToFirstTwoDigits(((percentage/100)+1)*balance);
		}
		
	}
	
}


void printOpenAccounts()
{
	for(int i = 0; i<NUMBER_OF_ACCOUNTS; i++)
	{
		
		if(isOpenAccount(i))
		{
			int numberOfAccount = i+901;
			double cashInTheAccount = bank[i][0];
			printf("the number of the account: %d\n the balance is:%.2lf\n",numberOfAccount,cashInTheAccount);
		}

	}	
}

void closeAccounts()
{
	for(int i = 0; i<NUMBER_OF_ACCOUNTS; i++)
	{
		
		if(isOpenAccount(i))
		{
			bank[i][1] = FALSE;
		}

	}	
}

//privates
int indexOfAccount(int numberAccount)
{
	int accountIndex = (numberAccount%100)-1;
	return accountIndex;
}

int isOpenAccount(int accountIndex)
{
	int openAccount = (int)(bank[accountIndex][1] + 0.1);
	return openAccount;
}

int indexOpenBack()
{
     for(int i = 0; i < NUMBER_OF_ACCOUNTS; i++)
     {
         if(!isOpenAccount(i))
            return i;
     }
     return 0;
}

double roundToFirstTwoDigits(double num)
{
	return ((int)(num * 100.0)) / 100.0;
}


