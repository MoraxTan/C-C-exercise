#include<stdio.h>
int main()
{
	int t=1;
	int n;
	while(scanf("%d",&n)==1&&n>0)
	{
		int count;
		int temp;
		for(temp=1,count=0;temp<n;temp<<=1,count++);
		printf("Case %d: %d\n",t++,count);
	}
	return 0;
}
