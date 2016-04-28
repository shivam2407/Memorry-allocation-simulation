
void nextfit(int npr,int hol[100],int pr[100],int nh,int used[100]){
int i,j=0,k,flag=0,cnt;
   for(i=0;i<nh;i++)
    {
        used[i]=0;

    }

printf("\n\n__________________Next Fit____________________\n\n");
for(i=0;i<npr;i++)
   {
     flag=0;
     cnt=0;
    display(nh,hol,used);
       while(j<nh)
        {

               if(pr[i]<=hol[j])
               {
                hol[j]=hol[j]-pr[i];
                used[j]+=pr[i];
                flag=1;
                printf("\n\nMemory is Allocated to Process %d :(%d)",i+1,pr[i]);
                break;
               }

              j=(j+1)%nh;
              cnt+=1;
              if(cnt==nh){
                break;
              }

          }


    if(flag==0)
    {printf("\n\n*********Hole is not Available for Process %d : (%d) **********",i+1,pr[i]);
    break;}

}

    display(nh,hol,used);



 }

