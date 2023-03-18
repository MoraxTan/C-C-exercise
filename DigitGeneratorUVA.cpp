#include "stdio.h"
#include "string.h"
#include "algorithm"

int A[131072];
int main()
{
    char c[1024];
    for(int i=1;i<131072;i++)
    {
        A[i]=0x3f3f3f3f;
    }
    for (int i=1;i<131072;i++)
    {
        sprintf(c,"%d",i);
        int sum=i;
        for(int j=0;c[j];j++)
        {
            sum+=c[j]-'0';
        }
        A[sum] = std::min(A[sum], i);
    }

    int testCase, n;
    scanf("%d",&testCase);
    while(testCase--)
    {
        scanf("%d",&n);
        printf("%d\n",A[n] == 0x3f3f3f3f ? 0 : A[n]);
    }
    
    return 0;
}