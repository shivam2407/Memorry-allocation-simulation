void worstfit(int npr,int hol[100],int pr[100],int nh,int used[100])
{

printf("\n\n_____________________Worst Fit_________________________\n\n");
int i,j,k,max,flag;
   for(i=0;i<nh;i++)
    {
        used[i]=0;

    }

for(i=0;i<npr;i++)
   {
     flag=0;
     display(nh,hol,used);
       for(j=0;j<nh;j++)
        {

            if(pr[i]<=hol[j])
     {
                printf("\n\nMemory is Allocated to Process %d :(%d)",i+1,pr[i]);
                flag=1;
                max=j;
                 for(k=j;k<nh;k++)
                 {
                   if((hol[max]<hol[k])&&(pr[i]<=hol[k]))
                   {
                     max=k;
                   }
                 }
               if(pr[i]<=hol[max])
               {
                    hol[max]=hol[max]-pr[i];
                    used[max]+=pr[i];
                    break;
               }
       }
          }

     if(flag==0)
    {printf("\n\n*********Hole is not Available for Process %d : (%d) ***********",i+1,pr[i]);
    break;}



      }
      display(nh,hol,used);


}
