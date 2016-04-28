#include <stdio.h>
#include <stdlib.h>


void display(int ,int [100],int [100]);
void firstfit(int ,int [100],int [100],int,int [100]);
void nextfit(int ,int [100],int [100],int,int [100]);
void bestfit(int ,int [100],int [100],int,int [100]);
void worstfit(int,int [100],int [100],int,int[100]);
int check(int,int [100],int [100],int,int[100]);

int main()
{
  int npr,nh=0,i,j,k,pr[100],hol[100],ch,temp[100],used[100];
  do{
      printf("\n\n---Menu--- \n 1.INPUT\n2.FIRST-FIT \n3.BEST FIT\n4.NEXT FIT\n5.WORST FIT\n6.Suggest Algo.\n7.Exit\n\nENTER YOUR CHOICE: ");
      scanf("%d",&ch);
    for(i=0;i<nh;i++)temp[i]=hol[i];
    switch(ch)
      {
         case 1:
                printf("\n Enter the number of processes:");
                scanf("%d",&npr);
                printf("\nNumber of holes:");
                scanf("%d",&nh);
                for(i=0;i<npr;i++)
                  {
                     printf("\nProcess %d:",i+1);
                     scanf("%d",&pr[i]);
                  }
                for(i=0;i<nh;i++)
                  {
                     printf("\nHole %d:",i+1);
                     scanf("%d",&hol[i]);
                     used[i]=0;
                     temp[i]=hol[i];
                  }
                break;
        case 2:
                firstfit(npr,temp,pr,nh,used);
                break;
        case 3: bestfit(npr,temp,pr,nh,used);
                break;
         case 4:nextfit(npr,temp,pr,nh,used);
                break;
         case 5:worstfit(npr,temp,pr,nh,used);
                 break;
         case 6:check(npr,temp,pr,nh,used);
                break;
         case 7:exit(0);
        default:printf("\nPlease Enter a number between 1 to 7.....");
     }
   }while(ch!=6);
return 0;
}

