#include<stdio.h>

int main() {
	int t,n,i,j,a[51]={0},flag,high_jumps,low_jumps;
	scanf("%d\n",&t); //loop t times
	flag=1; //case numbers
	while(t--) {
		scanf("%d\n",&n);
		for(i=0;i<n;i++) {
			scanf("%d",&a[i]); //save in array
		}
		if(n==1) //wall has only one,so can't decide it high and low for the height of wall
			high_jumps=low_jumps=0; 
		for(high_jumps=low_jumps=i=0,j=1;j<n;i++,j++) {
			if(a[i]-a[j]<0) high_jumps++;
			else if(a[i]>a[j]) low_jumps++; 
		}
		printf("Case %d:%d %d\n",flag,high_jumps,low_jumps); //print out data
		flag++;
	}
	return 0;
}
