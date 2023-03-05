#include<bits/stdc++.h>

using namespace std;
int main()
{
    int n, count, temp, it;
    bool a[35];
    while(1)
    {
        scanf("%d", &n);
        if(!n)  return 0;
        count = 0;
        temp = n;
        it = 0;

        while(temp)
        {
            if(temp%2==0)
            {
                count++;
                a[it++]=1;
            }
            else{
                a[it++]=0;
            }
            temp/=2;
        }
        printf("The parity of ");
        for(int i = it - 1; i >= 0; i--)
        {
            printf("%d", a[i]);
        }
        printf(" is %d (mod 2).\n", count);
    }
    return 0;
}