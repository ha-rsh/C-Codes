#include<stdio.h>

int main(void) {
	// your code goes here
	int amount;
	float balance=120;
	printf("INPUT:\n");
	scanf("%d \t %f", &amount,&balance);
	//printf("%f",balance);
	if(amount%5==0)
	{
	    printf("\nOUTPUT:\n");
	    balance=balance-(float)amount-0.50;
	    printf("%f",balance);
	}
	else if((float)amount>balance)
	{
	    printf("OUTPUT:\n");
	    printf("%f",balance);
	}
	else
	{
	    printf("OUTPUT:\n");
	    printf("%f",balance);
	}
	return 0;
}
