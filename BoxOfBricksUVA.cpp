//Box of bricks UVA
#include<stdio.h>

int main()
{
    int n, sum, hi_avg, x[55], ans;
    int count = 1;
    while(scanf("%d",&n), n)
    {
        sum = 0;

        for(int i = 0; i < n; i++)
        {
            scanf("%d",&x[i]);
            sum += x[i];
        }

        hi_avg = sum / n;
        ans = 0;

        for(int i = 0;i < n; i++)
        {
            if(x[i] > hi_avg)
            {
                ans += x[i] - hi_avg;
            }
        }
        printf("Set #%d\nThe minimum number of moves is %d.\n\n", count++, ans);
    }
    return 0;
}