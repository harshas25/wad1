#include <stdio.h>

#include <math.h>
#include <conio.h>

int count=0,a[30];
int place(int pos)
{
    int i;
    for(i=1;i<pos;i++)
    {
        if((a[i]==a[pos]) || ((abs(a[i]-a[pos])==abs(i-pos))) )       //checking for same column and diagonal
            return 0;
    }
    return 1;
}

void print_sol(int n)
{
    int i,j;
    count++;
    printf("\n\nSolution #%d:\n",count);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(a[i]==j)
            {
                printf("Q\t");
            }
            else
            {
                printf("*\t");
            }
        }
        printf("\n");
    }
}

void queen(int n)
{
    int k=1;                //nth number of queen.
    a[k]=0;                 //k is the row and a[k] is column.

    while(k!=0)
    {
        do
        {
            a[k]++;
        }while((a[k]<=n)&&!place(k));
        if(a[k]<=n)
        {
            if(k==n)
                print_sol(n);

            else
            {
                k++;
                a[k]=0;
            }
        }
        else
            k--;


    }
}
void main()
{

    int n;
    printf("Enter the number of queens to be placed: ");
    scanf("%d",&n);
    queen(n);
    printf("Total solution are: %d",count);

}