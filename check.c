int f_flag=0,w_flag=0,b_flag=0,n_flag=0,b_max=0,f_max=0,n_max=0,w_max=0;
void display(int ,int [100],int [100]);
void firstfit_check(int ,int [100],int [100],int,int [100]);
void nextfit_check(int ,int [100],int [100],int,int [100]);
void bestfit_check(int ,int [100],int [100],int,int [100]);
void worstfit_check(int,int [100],int [100],int,int[100]);



int check(int npr, int hol[100], int pr[100], int nh, int used[100]){
    int best[4],max_best,temp[10],i;
    for(i=0;i<nh;i++)temp[i]=hol[i];

    firstfit_check(npr,temp,pr,nh,used);
    for(i=0;i<nh;i++)temp[i]=hol[i];

    worstfit_check(npr,temp,pr,nh,used);
for(i=0;i<nh;i++)temp[i]=hol[i];

    nextfit_check(npr,temp,pr,nh,used);
for(i=0;i<nh;i++)temp[i]=hol[i];

    bestfit_check(npr,temp,pr,nh,used);
    best[0]=f_max;best[1]=b_max;best[2]=n_max;best[3]=w_max;
    max_best=0;
    for(i=0;i<4;i++){
        if(max_best<best[i]){
            max_best=best[i];
        }
    }
    if(f_flag==0 && max_best==f_max){
        printf("\n\n_______Best Algorithm to be used for Your Example is First Fit______\n\n");
    }
    else if(b_flag==0 && max_best==b_max){
        printf("\n\n_______Best Algorithm to be used for Your Example is Best Fit_______\n\n");
    }
    else if(w_flag==0 && max_best==w_max){
        printf("\n\n_______Best Algorithm to be used for Your Example is Worst Fit_______\n\n");
    }
    else if(n_flag==0 && max_best==n_max){
        printf("\n\n_______Best Algorithm to be used for Your Example is Next Fit______\n\n");
    }
    else{
        printf("\n\nAll the given algorithm are not able to handle your example");
    }
}


void bestfit_check(int npr,int hol[100],int pr[100],int nh,int used[100]){
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
    {printf("\n\n*******Hole is not Available for Process %d : (%d) ********",i+1,pr[i]);
    b_flag=1;
    break;}
   }
   display(nh,hol,used);
    if(b_flag==1){
        b_max=-1;
    }
    else{
    for(j=0;j<nh;j++){
        if(b_max<hol[j]){
            b_max=hol[j];
        }
   }
    }





}




void worstfit_check(int npr,int hol[100],int pr[100],int nh,int used[100])
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
    {printf("\n\n******Hole is not Available for Process %d : (%d) *********",i+1,pr[i]);
    w_flag=1;
    break;}



      }
      display(nh,hol,used);

   if(w_flag==1){
        w_max=-1;
    }
    else{
    for(j=0;j<nh;j++){
        if(w_max<hol[j]){
            w_max=hol[j];
        }
   }
    }

}


void firstfit_check(int npr,int hol[100],int pr[100],int nh,int used[100])
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
    {printf("\n\n*******Hole is not Available for Process %d : (%d) *********",i+1,pr[i]);
    f_flag=1;
    break;}

   }


  display(nh,hol,used);
   if(f_flag==1){
        f_max=-1;
    }
    else{
    for(j=0;j<nh;j++){
        if(f_max<hol[j]){
            f_max=hol[j];
        }
   }
    }
}

void nextfit_check(int npr,int hol[100],int pr[100],int nh,int used[100]){
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
    {printf("\n\n******Hole is not Available for Process %d : (%d) ********",i+1,pr[i]);
    n_flag=1;
    break;}

}

    display(nh,hol,used);

if(n_flag==1){
        n_max=-1;
    }
    else{
    for(j=0;j<nh;j++){
        if(n_max<hol[j]){
            n_max=hol[j];
        }
   }
    }


 }







