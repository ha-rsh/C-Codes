#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<string.h>
#include<ctime>

using namespace std;
int main()
{
    char player_name[15];
    int player_score=0,computer_score=0;
    cout<<"\tenter your name:";
    gets(player_name);
    int rounds;
    cout<<"\t"<<player_name<<" how many rounds you want to play....";
    cin>>rounds;
     for(int i=1;i<rounds;i++)
     {
         int player_choice,computer_choice;
         cout<<"\nround no:"<<i<<"/"<<rounds<<endl;
         cout<<player_name<<" 's score="<<player_score<<endl;
         cout<<"computer's score="<<computer_score<<endl;
         cout<<"\t1.ROCK"<<endl;
         cout<<"\t2.PAPER"<<endl;
         cout<<"\t3.SCISSOR"<<endl;
         do
         {
            cout<<"\tenter your choice:";
            cin>>player_choice;
         }
         while(player_choice!=1 && player_choice!=2 && player_choice!=3);
         srand(time(0));
         computer_choice=(rand()%3)+1;
         cout<<"\tcomputer's choice :"<<computer_choice;
         if(player_choice==1 && computer_choice==3)
         {
             cout<<"\n\tplayer win...\n"<<endl;
             player_score++;
         }
         else if(player_choice==2 && computer_choice==1)
         {
             cout<<"\n\tplayer win...\n"<<endl;
             player_score++;
         }
         else if(player_choice==3 && computer_choice==2)
         {
             cout<<"\n\tplayer win...\n"<<endl;
             player_score++;
         }
         else if(player_choice==computer_choice)
         {
             cout<<"\n\tdraw..\n"<<endl;
         }
         else
         {
             cout<<"\n\tcomputer win...\n"<<endl;
             computer_score++;
         }
        cout<<"\tpress enter to continue.....\n";
        getch();
     }
if(computer_score==player_score)
    cout<<"\tgame draw"<<endl;
else if(player_score>computer_score)
{
    cout<<"\tplayer_score="<<player_score<<"\t\t"<<"computer_score"<<computer_score<<endl;
    cout<<endl<<player_name<<" you won the game....."<<endl;
}
else
{
    cout<<"\tplayer_score="<<player_score<<"\t\t"<<"computer_score"<<computer_score<<endl;
    cout<<"\tyou loose..computer won the game..";
}
return 0;
}
