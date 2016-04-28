void bestfit(int npr,int hol[100],int pr[100],int nh,int used[100]){
int i,j,k,min,flag;
   for(i=0;i<nh;i++)
    {
        used[i]=0;

    }

printf("\n\n___________________Best Fit_______________________\n\n");
for(i=0;i<npr;i++)
   {
     flag=0;
     display(nh,hol,used);
       for(j=0;j<nh;j++)
        {

            if(pr[i]<=hol[j])
              {
                flag=1;
                min=j;
                for(k=j;k<nh;k++)
                {
                   if((hol[min]>hol[k])&&(pr[i]<=hol[k]))
                   {
                        min=k;
                   }

                }
               if(pr[i]<=hol[min])
               {
                   printf("\n\nMemory is Allocated to Process %d :(%d)",i+1,pr[i]);
                   hol[min]=hol[min]-pr[i];
                   used[min]+=pr[i];
                   break;
               }
}
    }

     if(flag==0)
    {printf("\n\n**********Hole is not Available for Process %d : (%d) *************",i+1,pr[i]);
    break;}
   }
   display(nh,hol,used);

    }





