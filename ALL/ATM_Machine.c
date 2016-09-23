#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

#define MAX_STATES 7

unsigned long amount= 10000;

enum state_codes{
	ENTER_PIN,
	CHECK_BALANCE,
	WITHDRAW_CASH,
	DEPOSIT_CASH,
	QUIT,
	ENTER_CHOICE,
	CONTINUE	
};


static int enter_pin(void)
{
	system("cls");
    int pin=0; 
    printf("Enter your pin \n");
	scanf("%d", &pin);
	if(pin != 1234)
	 {   
	   printf("Invalid pin no \n");
	   sleep(2);
	   return ENTER_PIN; //repeat
     }
   
    return ENTER_CHOICE;
}

static int enter_choice(void)
{
	//clrscr(); //doesnt work with dev c++
	system("cls");
	printf("********Welcome to ATM Service**************\n");
	printf("1. Check Balance\n");
	printf("2. Withdraw Cash\n");
	printf("3. Deposit Cash\n");
	printf("4. Quit\n");
	printf("******************?**************************?*\n\n");
	printf("Enter your choice: ");
	int choice;
	scanf("%d", &choice);
	if(choice <= 0 || choice >MAX_STATES)
	{
		 printf("Invalid Choice \n");
		 return ENTER_CHOICE;
	}
	return choice;
}

static int check_balance(void)
{
  printf("The aount is: %lu \n", amount);	
  return CONTINUE;
}

static int withdraw_cash(void)
{
	unsigned long withdraw =0;
	printf("Eneter the amout to be withdrawn \n");
	scanf("%lu", &withdraw);
	if(withdraw%10 != 0)
	{
	   printf("Please enter amount in multiples of 10\n");
	   return WITHDRAW_CASH;
    }
	else if(withdraw > amount- 300)
	{
	   printf("Insufficient Balance \n");
	   return WITHDRAW_CASH;
    }
	else{
		amount -= withdraw;
		printf("Please collect your cash \n");
		printf("Your balance is : %lu \n", amount);
	}
	return CONTINUE;
}

static int deposit_cash(void)
{
	unsigned long deposit =0;
	printf("Enter the amount to be deposited \n");
	scanf("%ul", &deposit);
	amount += deposit;
	printf("Your balance is : %lu \n", amount);
	return CONTINUE;
}

static int continue_transaction(void)
{
	char transaction;
	printf("\n\n\nDO U WISH TO HAVE ANOTHER TRANSCATION?(y/n): \n");
	fflush(stdin);
	scanf("%c", &transaction);
	if(transaction == 'n' || transaction == 'N')
	  return QUIT;
	else 
	  return ENTER_CHOICE;
}

static int quit(void)
{
	printf("Thank you for using the atm \n***************************************\n\n\n");
	sleep(2);
	return ENTER_PIN;
}


//array and enum need to be in sync
int (*state[])(void) = {enter_pin, check_balance, withdraw_cash, deposit_cash, quit, enter_choice,continue_transaction };


int main()
{
	enum state_codes curr_state = ENTER_PIN;
	int (*state_function)(void);
	for(;;)
	{
		state_function = state[curr_state];
		curr_state = state_function();
	}
		
	return 0;//should not get here
}











