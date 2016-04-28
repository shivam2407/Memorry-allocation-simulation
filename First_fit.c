
void firstfit(int npr,int hol[100],int pr[100],int nh,int used[100])
{

printf("\n\n___________________First Fit______________________\n\n");
   int i,j,k,flag=0;
   for(i=0;i<nh;i++)
    {
        used[i]=0;

    }

   for(i=0;i<npr;i++)
   {
      display(nh,hol,used);
      flag=0;
      for(j=0;j<nh;j++)
      {
             if(pr[i]<=hol[j])
              {
                hol[j]=hol[j]-pr[i];
                used[j]=used[j]+pr[i];
                printf("%d \n",used[j]);
            printf("\n\nMemory is Allocated to Process %d :(%d)",i+1,pr[i]);
                flag=1;
                break;
              }

        }

    if(flag==0)
    {printf("\n\n*******Hole is not Available for Process %d : (%d) ***********",i+1,pr[i]);
    break;}

   }


  display(nh,hol,used);
}
