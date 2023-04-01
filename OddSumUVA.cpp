#include<stdlib.h>
#include<stdio.h>
int main()
{
    int t;
    int a,b;
    int count=1;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d\n%d",&a, &b);
        int ans=0;
        
        for(int i=a;i<=b;i++)
        {
            if(i%2==1){
                ans += i;    
            }
        }
        printf("Case %d: %d\n",count++,ans);
    }
    return 0;
}
/*
#include<stdlib.h>
int main(){

    int T;
    int sum;
    int a, b;
    int time = 0;

    scanf("%d", &T);

    for(int i = 0; i < T; i++){

        scanf("%d %d", &a, &b);

        time++;
        sum = 0;

        if(a == b && a % 2 == 0){
            printf("Case %d: 0\n", time);
            continue;
        }
        for(int j = a; j <= b; j++){
            if(j % 2 == 1){
                sum = sum + j;
            }
        }
        printf("Case %d: %d\n", time, sum);
    }

    return 0;
}
*/
