#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

int compare_string(char str1[], char str2[]);

int main()
{
    int size,i,n,name[10][10],temp[10],j,choice;
    char c;
    label:
    printf("\n enter the number of strings you want to enter:");
    scanf("%d", &n);
    fflush(stdin);
    for(i=0;i<n;i++)
    {
        printf("enter the string-%d: ",i+1);
        scanf("%s",&name[i]);
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(compare_string(name[j],name[j+1])>0)
            {
                strcpy(temp,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],temp);
            }
        }
    }
    printf("\n names of the students in alphabetical order are:\n");
    for(i=0;i<n;i++)
    {
        puts(name[i]);
    }
    printf("\nWant to sort more:\n");
    scanf("%c",&c);
    if(c=='y' || c=='Y')
        goto label;

return 0;
}

int compare_string(char s1[], char s2[])
{
   int i = 0;
   while (s1[i] == s2[i] && s1[i] != '\0')
      i++;
   if (s1[i] > s2[i])
      return 1;
   else if (s1[i] < s2[i])
      return -1;
   else
      return 0;
}


