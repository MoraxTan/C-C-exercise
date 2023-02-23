#include<stdio.h>
#include<math.h>

int main() {
	long n;
	while(scanf("%ld",&n)!=EOF) {
		int a,b;
		a=floor((sqrt(8*n+1)-1)/2-1e-9)+1;
		b=a*(a+1)/2;
		
		if(a%2==0) {
			printf("TERM %d IS %d/%d\n",n,a-b+n,b-n+1);
		}
		else {
			printf("TERM %d IS %d/%d\n",n,b-n+1,a-b+n);
		}
	}
	return 0;
}
