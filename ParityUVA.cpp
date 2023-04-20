#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    
    while(scanf("%d",&i) && i)
    {
        int p = 0, k = 0;
        char a[50]={0};
        while(i>0)
        {
            if(i%2)
            {
                a[k]='1';
                p++;
            }
            else{
                a[k]='0';
            }
            k++;
            i/=2;
        }
        printf("The parity of ");
        for(int j=strlen(a)-1;j>=0;j--)
        {
            printf("%c", a[j]);
        }
        printf(" is %d (mod 2).\n", p);
    }
    return 0;
}