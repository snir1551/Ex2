 /**
 *Class main
 *
 * @version 27/11/2019
 * @author (Snir Okashi) 
 * 
 */

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "myBank.h"


int main()
{
	//Deaclaration of variables
	double amount = 0;
	int accountNumber = 0;
	double percentage = 0;
	int stop = FALSE;
	char choose = 48;
	while(!stop)
	{
		printf("Transaction type?: ");
		scanf("%c",&choose); //Allow the user to choose that action
		fflush(stdin);
		switch(choose)
		{
 
			case 'O':
				printf("Initial deposit?: ");
				amount = 0;
				scanf("%lf",&amount);
				openAccountOfBank(amount);
				break;
			case 'B':
				printf("Account number?: ");
				accountNumber = 0;
				scanf("%d",&accountNumber);
				balance(accountNumber);
				break;
			case 'D':
				accountNumber = 0;
				amount = 0;
				printf("Account number?: ");
				scanf("%d",&accountNumber);
				printf("amount?: ");
				scanf("%lf",&amount);

				depositToAccount(accountNumber,amount);
			
				break;
			case 'W':
				accountNumber = 0;
				amount = 0;
			
				printf("Account number?: ");
				scanf("%d",&accountNumber);
				printf("amount?: ");
				scanf("%lf",&amount);
				withdrawal(accountNumber,amount);
				break;
			case 'C':
				accountNumber = 0;
				printf("Account number?: ");
				scanf("%d",&accountNumber);
				closeAccount(accountNumber);
				break;
			case 'I':
				percentage = 0;
				printf("interest_rate: ");
				scanf("%lf",&percentage);
				addInterest(percentage);
				break;
			case 'P':
				printOpenAccounts();
				break;
			case 'E':
				closeAccounts();
				stop = TRUE;
				break;
			default: printf("you choose wrong char\n");
		}

		getchar();

	}

	return 0;
}
