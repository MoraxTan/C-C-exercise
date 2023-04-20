#include<stdio.h>

int main()
{
    int n;
    while(scanf("%d",&n)&&n)
    {
        if(n==-1)   break;
        long long F=1, M=0;
        for(int i=1;i<=n;i++)
        {
            long long tmp = M;
            M += F;
            F = tmp+1;
        }
        printf("%lld %lld\n", M, M+F);
    }
    return 0;
}