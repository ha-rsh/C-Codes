#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
#define SIZE 100

char s[SIZE];
int top=-1;
void push(char);
char pop();
void infix_to_postfix(char infix[],char postfix[]);
int priority_operator(char);

int main()
{
    char infix[100],postfix[100],ch;
    do
    {
      printf("\n enter the infix expression : ");
      gets(infix);
      infix_to_postfix(infix,postfix);
      printf("\n postfix expression is : ");
      puts(postfix);
      printf("want to continue(y/n)........");
      scanf("%c",& ch);
      fflush(stdin);
    }
    while(ch=='y');
    return 0;
}

void infix_to_postfix(char infix[], char postfix[])
{
    int i=0,j=0;
    char temp;
    printf("\n\n");
    printf("\tSYMBOL");
    printf("\t\t\t\t\tSTACK \n");
    printf("    ---------------------------------------------------------\n");
    while(infix[i]!='\0')
    {
        if(infix[i]=='(')
        {
            push(infix[i]);
            printf("\t%c", infix[i]);
            printf("\t\t\t\t\tPUSH\t%c\n",infix[i]);
            i++;
        }
        else if(infix[i]==')')
        {
            while((top!=-1) && (s[top]!='('))
            {
                postfix[j]=pop();
                printf("\t\t\t\t\t\tPOP\t%c\n",postfix[j]);
                j++;
            }
            if(top==-1)
            {
                printf("stack is empty");
                exit(0);
            }
            temp=pop();
            i++;
        }
        else if(isdigit(infix[i]) || isalpha(infix[i]))
        {
            postfix[j]=infix[i];
            if(isdigit(infix[i]))
            {
                printf("\t%d", infix[i]);
                printf("\t\t\t\t\tPUSH\t%d\n",infix[i]);
            }
            else
            {
                printf("\t%c", infix[i]);
                printf("\t\t\t\t\tPUSH\t%c\n",infix[i]);
            }
            j++;
            i++;
        }
        else if(infix[i]=='+' || infix[i]=='-' || infix[i]=='*' || infix[i]=='/' || infix[i]=='%' || infix[i]=='^')
        {
            printf("\t%c",infix[i]);
            while((top!=-1) && (s[top]!='(') && (priority_operator(s[top])>=priority_operator(infix[i])))
            {
                postfix[j]=pop();
                printf("\t\t\t\t\tPOP\t%c\n",postfix[j]);
                j++;
            }
            push(infix[i]);
            printf("\t\t\t\t\tPUSH\t%c\n",infix[i]);
            i++;
        }
        else
        {
            printf("\n incorrect expression \n");
            exit(0);
        }
    }
    while((top!=-1) && (s[top]!='('))
    {
        postfix[j]=pop();
        if(isdigit(postfix[j]))
        {
            printf("\t\t\t\t\t\tPOP\t%d\n",postfix[j]);
        }
        else
        {
            printf("\t\t\t\t\t\tPOP\t%c\n",postfix[j]);
        }
        j++;
    }
    postfix[j]='\0';
}

int priority_operator(char op)
{
    if(op=='^')
        return (3);
    else if(op=='/' || op=='*' || op=='%')
        return (2);
    else if(op=='+' || op=='-')
        return (1);
    else
        return 0;
}

void push(char ele)
{
    if(top==SIZE-1)
        printf("\n stack overflow \n");
    else
    {
        top++;
        s[top]=ele;
    }
}

char pop()
{
    char ele;
    if(top==-1)
        printf("\n stack underflow \n");
    else
    {
        ele=s[top];
        top--;
    }
    return ele;
}
