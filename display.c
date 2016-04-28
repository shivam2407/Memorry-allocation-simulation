void display(int nh,int hol[100],int used[100])
{
 printf("\nHoles:");
 int i=0;
 for(i=0;i<nh;i++)
    {
        printf("   %d | %d   ",used[i],hol[i]);

    }
}
