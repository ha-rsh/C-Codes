#include<stdio.h>
#include<stdlib.h>

int count;
int count_node();
void create_node();
void insert_beg();
void insert_end();
void insert_pos();
void delete_beg();
void delete_end();
void delete_pos();
void reverse();
void display();

struct node
{
    int data;
    struct node *next;
}*head;

int main()
{
    int choice;
    char option;
    create_node();
    printf("\n\n elements in the linked list are as follows..\n");
    display();
    count=count_node();
    printf("\n\ncount of nodes in linked list:%d",count);
    label:
    printf("\n\n\t\t****MAIN MENU****\n\n");
    printf("1. INSERT IN BEGINNING\n");
    printf("2. INSERT IN END\n");
    printf("3. INSERT AT POSITION\n");
    printf("4. DELETE FROM BEGINNING\n");
    printf("5. DELETE FROM END\n");
    printf("6. DELETE FROM POSITION\n");
    printf("7. REVERSE LINKED LIST\n");
    printf("8. EXIT\n");
    printf("enter you choice:");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: insert_beg();
                printf("\n\nlinked list after inserting node at the beginning....\n");
                display();
                count=count_node();
                printf("\n\ncount of nodes in linked list:%d",count);
                break;

        case 2: insert_end();
                printf("\n\nlinked list after inserting node at the end....\n");
                display();
                count=count_node();
                printf("\n\ncount of nodes in linked list:%d",count);
                break;

        case 3: insert_pos();
                printf("\n\nlinked list after inserting node at the given position....\n");
                display();
                count=count_node();
                printf("\n\ncount of nodes in linked list:%d",count);
                break;

        case 4: delete_beg();
                printf("\n\nlinked list after deleting node from the beginning....\n");
                display();
                count=count_node();
                printf("\n\ncount of nodes in linked list:%d",count);
                break;

        case 5: delete_end();
                printf("\n\nlinked list after deleting node from the end....\n");
                display();
                count=count_node();
                printf("\ncount of nodes in linked list:%d",count);
                break;

        case 6: delete_pos();
                printf("\n\nlinked list after deleting node from the given position....\n");
                display();
                break;

        case 7: reverse();
                printf("\n\nlinked list after reversing....\n");
                display();
                count=count_node();
                printf("\ncount of nodes in linked list:%d",count);
                break;

        case 8: exit(0);
                break;
    }
    printf("\nwant to continue(y/n)?....:");
    scanf("%c",&option);
    if(option=='y' || option=='Y')
        goto label;
return 0;
}

void create_node()
{
    struct node *temp,*newnode;
    char choice;
    head=temp=NULL;
    start:
    printf("enter the date for the node:");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    fflush(stdin);
    newnode->next=NULL;
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        temp->next=newnode;
        temp=newnode;
    }
    printf("want to enter more node(y/n):");
    scanf("%c",&choice);
    fflush(stdin);
    if(choice=='y' || choice =='Y')
        goto start;
}

void insert_beg()
{
    struct node *temp,*newnode;
    char choice;
    temp=head;
    start:
    printf("enter the data for the node:");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    fflush(stdin);
    if(head==NULL)
    {
        head=temp=newnode;
    }
    else
    {
        newnode->next=head;
        head=newnode;
    }
    printf("want to enter more node(y/n):");
    scanf("%c",&choice);
    fflush(stdin);
    if(choice=='y' || choice =='Y')
        goto start;
}

void insert_end()
{
    struct node *temp,*newnode;
    char choice;
    start:
    printf("enter the data for the node:");
    newnode=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&newnode->data);
    fflush(stdin);
    newnode->next=NULL;
    temp=head;
    if(head==NULL)
        head=temp=newnode;
    else
    {
        while(temp->next!=NULL)
        {
          temp=temp->next;
        }
        temp->next=newnode;
    }
    printf("want to enter more node(y/n):");
    scanf("%c",&choice);
    fflush(stdin);
    if(choice=='y' || choice =='Y')
        goto start;
}

void insert_pos()
{
    struct node *newnode,*temp;
    char choice;
    int pos,i=1;
    start:
    temp=head;
    count=count_node();
    printf("\ncount of nodes in linked list:%d",count);
    printf("\nenter the position where you want to insert the new node:");
    scanf("%d",&pos);
    fflush(stdin);
    fflush(stdin);
    if(pos==1)
        insert_beg();
    else if(pos==count)
        insert_end();
    else if(pos<=0 && pos>count)
        printf("\ninvalid position\n");
    else
    {
        while(i<pos-1)
        {
            temp=temp->next;
            i++;
        }
        printf("enter the data for the node:");
        newnode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&newnode->data);
        newnode->next=temp->next;
        temp->next=newnode;
    }
    printf("want to enter more node(y/n):");
    scanf("%c",&choice);
    fflush(stdin);
    if(choice=='y' || choice =='Y')
        goto start;
}

void delete_beg()
{
    struct node *temp;
    char choice;
    start:
    temp=head;
    head=head->next;
    free(temp);
    printf("want to delete more node(y/n):");
    scanf("%c",&choice);
    fflush(stdin);
    if(choice=='y' || choice =='Y')
        goto start;
}

void delete_end()
{
    struct node *temp,*prevnode;
    char choice;
    start:
    temp=head;
    while(temp->next!=NULL)
    {
        prevnode=temp;
        temp=temp->next;
    }
    if(temp==head)
    {
        head=NULL;
        free(temp);
    }
    else
    {
        prevnode->next=NULL;
    }
    free(temp);
    printf("want to delete more node(y/n):");
    scanf("%c",&choice);
    fflush(stdin);
    if(choice=='y' || choice =='Y')
        goto start;
}

void delete_pos()
{
    struct node *temp,*nextnode;
    int pos,i=1;
    char choice;
    start:
    temp=head;
    count=count_node();
    printf("\ncount of nodes in linked list:%d",count);
    printf("\nenter the position from where you want to delete the new node:");
    scanf("%d",&pos);
    fflush(stdin);
    if(pos==1)
        delete_beg();
    else if(pos==count)
        delete_end();
    else if(pos<=0 && pos>count)
        printf("\ninvalid position\n");
    else
    {
        while(i<pos-1)
        {
           temp=temp->next;
           i++;
        }
         nextnode=temp->next;
         temp->next=nextnode->next;
         free(nextnode);
    }
    printf("want to delete more node(y/n):");
    scanf("%c",&choice);
    fflush(stdin);
    if(choice=='y' || choice =='Y')
        goto start;
}

void reverse()
{
    struct node *prevnode,*currentnode,*nextnode;
    prevnode=NULL;
    currentnode=nextnode=head;
    while(nextnode!=NULL)
    {
        nextnode=nextnode->next;
        currentnode->next=prevnode;
        prevnode=currentnode;
        currentnode=nextnode;
    }
    head=prevnode;
}

int count_node()
{
    struct node *temp;
    int i;
    temp=head;
    while(temp!=NULL)
    {
        i++;
        temp=temp->next;
    }
    return i;
}

void display()
{
    struct node *temp;
    temp=head;
    printf("\t\t\t\t");
    if(head==NULL)
        printf("\nlist is empty\n");
    while(temp->next!=NULL)
    {
        printf("%d --> ",temp->data);
        temp=temp->next;
    }
    printf("%d",temp->data);
}
