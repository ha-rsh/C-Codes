#include<stdio.h>
#include<stdlib.h>
#include<process.h>
#define max 5
void push(int s[], int ele);
int pop(int s[]);
int peek(int s[]);
void display(int s[]);
int top=-1;

int main()
{
    int s[max];
    int ele,choice;
    do
    {
        printf("\n\n\n\t\t\t\t****LIST OF OPERATIONS****\n");
        printf("1. PUSH\n");
        printf("2. POP\n");
        printf("3. PEEK\n");
        printf("4. EXIT\n");
        printf("enter your choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: printf("enter the element to be pushed:");
                    scanf("%d",&ele);
                    push(s,ele);
                    display(s);
                    break;

            case 2: ele=pop(s);
                    if(ele!=-1)
                       printf("\n deleted value from stack is:%d\n",ele);
                    display(s);
                    break;

            case 3: ele=peek(s);
                    if(ele!=-1)
                        printf("\nvalue stored at the top of the stack is:%d\n",ele);
                    display(s);
                    break;

            case 4: exit(0);
                    break;
        }
    }while(choice!=5);
        return 0;
}

void push(int s[],int ele)
{
    if(top==max-1)
    {
        printf("\nstack overflow");
    }
    else
    {
        top++;
        s[top]=ele;
    }
}

int pop(int s[])
{
    int val;
    if(top==-1)
    {
        printf("\nstack underflow");
        return -1;
    }
    else
    {
        val=s[top];
        top--;
        return val;
    }
}

int peek(int s[])
{
    if(top==-1)
       {
           printf("\nstack is empty");
           return -1;
       }
    else
        return(s[top]);
}

void display(int s[])
{
    int i;
    if(top==-1)
        printf("\nstack is empty");
    else
    {

        printf("\t\t\t\t\t\t\t\t|");
        printf("%10d \t\t| <--TOP",s[top]);
        printf("\n");
        printf("\t\t\t\t\t\t\t\t|_______________________|");
        printf("\n");
        for(i=top-1;i>=0;i--)
        {
            printf("\t\t\t\t\t\t\t\t|");
            printf("%10d \t\t|",s[i]);
            printf("\n");
            printf("\t\t\t\t\t\t\t\t|_______________________|\n");
        }
    }
}

