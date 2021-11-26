#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int radix_sort(int a[],int size);
void counting_sort(int a[],int n, int place,int max, int j);

int main()
{
    int size,i,a[100],n,j,choice,max;
    char c;
    label:
    printf("enter the number of elements in the array: ");
    scanf("%d", &size);
    printf("enter the elements of the array:");
    for(i=0;i<size;i++)
    {
        scanf("%d", &a[i]);
        fflush(stdin);
    }
    max=radix_sort(a,size);
    printf("\n\t\t\t\tSORTED ARRAY IS---:\n");
    printf("\t\t\t\t\t\t\t\t");
    printf("  ");
    for(i=0;i<size;i++)
    {
        if(max<100)
            printf("---------");
        else if(max>100 && max<1000)
            printf("-----------");
        else
            printf("------------------");
    }
    printf("\n");
    printf("\t\t\t\t\t\t\t\t");
    printf("  |    ");
    for(i=0;i<size;i++)
    {
        printf("%d    |\t",a[i]);
    }
    printf("\n");
    printf("\t\t\t\t\t\t\t\t");
    printf("  ");
    for(i=0;i<size;i++)
    {
        if(max<100)
           printf("---------");
        else if(max>100 && max<1000)
            printf("------------");
        else
            printf("------------------");
    }
    printf("\n");
    printf("\nWant to sort more:\n");
    scanf("%c",&c);
    if(c=='y' || c=='Y')
        goto label;

return 0;
}

int radix_sort(int a[],int size)
{
    int max,place,i,j=0;
    max=a[0];
    for(i=0;i<size;i++)
    {
        if(a[i]>max)
        {
            max=a[i];
        }
    }
    for(place=1;(max/place)>0;place*=10)
    {
        counting_sort(a,size,place,max,j);
        j++;
    }
    return max;
}

void counting_sort(int a[],int size,int place,int max,int j)
{
    int i,b[size],bucket[10]={0};
    for(i=0;i<size;i++)
    {
        bucket[(a[i]/place)%10]++;
    }
    for(i=1;i<=10;i++)
    {
        bucket[i]=bucket[i]+bucket[i-1];
    }
    for(i=size-1;i>=0;i--)
    {
        b[--bucket[(a[i]/place)%10]]=a[i];
    }
    for(i=0;i<size;i++)
    {
        a[i]=b[i];
    }
    printf("\n");
    printf("pass-%d: \n",j+1);
    printf("  ");
    for(i=0;i<size;i++)
    {
        if(max<100)
            printf("---------");
        else if(max>100 && max<1000)
            printf("------------");
        else
            printf("------------------");
    }
    printf("\n");
    printf("  |    ");
    for(i=0;i<size;i++)
    {
        printf("%d    |\t",a[i]);
    }
    printf("\n");
    printf("  ");
    for(i=0;i<size;i++)
    {
        if(max<100)
            printf("---------");
        else if(max>100 && max<1000)
            printf("------------");
        else
            printf("------------------");
    }
    printf("\n");
}

