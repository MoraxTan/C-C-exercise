//Train swapping UVA
#include<stdio.h>

int main()
{
    int N,L,a[50];
    scanf("%d",&N);
    while(N--)
    {
        scanf("%d",&L);
        int i, j, temp;
        int count = 0;
        for(i=0;i<L;i++)
        {
            scanf("%d",&a[i]);
        } 

        for(i=0;i<L;i++)
        {
            for(j=L-1;j>i;j--)
            {
                if(a[j]<a[j-1])
                {
                    temp = a[j];
                    a[j] = a[j-1];
                    a[j-1] = temp;
                    count++;
                }
            }
        }
        printf("Optimal train swapping takes %d swaps.\n", count);
    }
    return 0;
}