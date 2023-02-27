#include<stdio.h>
int main() {
	int a,b,x,m,n,c[10]={0,1,1,2,1,2,2,3,1,2};
	while(scanf("%d",&n)!=EOF) {
		while(n--) {
           scanf("%d",&x);
           m=x;
           // every numbers whatever decimal or hexadecimal type,
           //those change to binary and then find the counts of number '1'
           for(a=0;x;) { //gets the counts of number'1' in decimal
            if(x%2==1) a++;
            x=x/2;
           }

           printf("%d ",a);

           for(b=0;m;) { //gets the counts of number '1' in hexadecimal
            b+=c[m%10];
            m/=10;
           }
           
           printf("%d\n",b);
		}
	}
	return 0;
}
