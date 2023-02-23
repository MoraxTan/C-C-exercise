#include<stdio.h>
#include<math.h>

int main() {
	int N,D,count;
	while(scanf("%d %d",&N,&D)!=EOF) {
		int y=0,m=0,day=0;
		
		count=pow(2,N)-1;
		day=count/D;
		y=day/365;
		m=(day%365)/30;
		day=day-y*365-m*30;
		
		printf("%d %d %d\n",y,m,day);
	
	}
}
