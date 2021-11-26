#include<stdio.h>
#include<stdlib.h>

struct queue
{
    int data;
    struct queue *next;
}*front=NULL,*rear=NULL;

struct queue *insert(struct queue*,int);
struct queue *delete_ele(struct queue*);
int peek (struct queue*);
struct queue *display(struct queue*);

int main()
{
    int ele,choice;
    do
    {
        printf("\n\n\t\t\t\t****MAIN OPERATIONS****\n\n");
        printf("1.INSERT\n");
        printf("2.DELETE\n");
        printf("3.PEEK\n");
        printf("4.EXIT\n");
        printf("enter your choice:");
        scanf("%d", &choice);
        switch(choice)
        {
            case 1: printf("enter the element to be inserted:");
                    scanf("%d", &ele);
                    front=insert(front,ele);
                    front=display(front);
                    break;

            case 2: front=delete_ele(front);
                    front=display(front);
                    break;

            case 3: ele=peek(front);
                    if(ele!=-1)
                        printf("element at the front of queue:%d",ele);
                    front=display(front);
                    break;

            case 4: exit(0);
        }
    }
    while(choice!=5);
    return 0;
}

struct queue *insert(struct queue *front,int ele)
{
  struct queue *newnode;
  newnode=(struct queue*)malloc(sizeof(struct queue));
  newnode->data=ele;
  if(front==NULL)
  {
      front=newnode;
      rear=newnode;
      front->next=rear->next=NULL;
  }
  else
  {
      rear->next=newnode;
      rear=newnode;
      rear->next=NULL;
  }
  return front;
}

struct queue *delete_ele(struct queue *front)
{
  struct queue *temp;
  temp=front;
  if(front==NULL)
  {
      printf("\n queue underflow \n");
  }
  else
  {
      front=front->next;
      printf("value deleted from the queue:%d",temp->data);
      free(temp);
  }
  return front;
}

int peek(struct queue *front)
{
    if(front==NULL)
    {
        printf("\n queue is empty \n");
        return -1;
    }
    else
        return front->data;
}

struct queue *display(struct queue *front)
{
  struct queue *temp;
  temp=front;
  if(temp==NULL)
  {
      printf("\n queue is empty \n");
  }
  else
  {
      printf("\n");
      while(temp!=rear)
      {
        printf("\t\t\t\t%d\n",temp->data);
        temp=temp->next;
      }
      printf("\t\t\t\t%d\n",temp->data);
  }
  return front;
}
