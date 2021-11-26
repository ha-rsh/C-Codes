#include <stdio.h>
#include<stdlib.h>
#define MAX 10

void insert();
void delete_ele();
int peek();
void display();
int queue_array[MAX];
int rear=-1;
int front=-1;
int main()
{
    int choice,ele;
    do
    {
        printf("\n\n\t\t\t\t****OPERATIONS LIST****\n\n");
        printf("1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.PEEK\n");
        printf("4.QUIT \n");
        printf("Enter your choice : ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1: insert();
                    display();
                    break;

            case 2: delete_ele();
                    display();
                    break;

            case 3: ele=peek();
                    if(ele!=-1)
                        printf("element at the front of the queue:%d\n",ele);
                    display();
                    break;

            case 4: exit(1);

        }
    }
    while(choice!=5);
}

void insert()
{
    int add_item;
    if (rear==MAX-1)
      printf("Queue Overflow \n");
    else
    {
        if (front==-1)
          front=0;
        printf("enter the element to be inserted in the queue : ");
        scanf("%d", &add_item);
        rear=rear+1;
        queue_array[rear]=add_item;
    }
}

void delete_ele()
{
    if (front==-1)
    {
        printf("\nQueue Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from queue is : %d\n\n", queue_array[front]);
        front++;
    }
}

int peek()
{
    int val;
    if(front==-1 && rear==-1)
        printf("\n queue if empty\n");
    else
        val=queue_array[front];
    return val;
}

void display()
{
    int i,k=0;
    if (front == - 1)
        printf("Queue is empty \n");
    else if(front==rear)
    {
        printf("queue is :\n\n");
        printf("\t\t\t\t\t\t REAR --> %d <-- FRONT",queue_array[rear]);
    }
    else
    {
        printf("queue is :\n\n");
        printf("\t\t\t\t\t\t %d <-- FRONT\n", queue_array[front]);
        for(i=front+1;i<=rear;i++)
        {
          if(i<rear)
            printf("\t\t\t\t\t\t %d\n", queue_array[i]);
          else
            printf("\t\t\t\t\t\t %d <-- REAR\n",queue_array[rear]);
        }
    }
}
