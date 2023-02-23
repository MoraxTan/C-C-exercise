#include<stdio.h>
#include<string.h>

int main()
{
	char line[101][101];
	int n=0,len[101],i,j;
	int maxLen = 0,upbound;
	
	while(gets(line[n]))
	{
		len[n]=(int)strlen(line[n]);
		if(len[n]>maxLen) maxLen = len[n];
		n++;
	}
	
	for(j=0;j<maxLen;j++)
	{
		upbound=0;
		while(j>=len[upbound]) upbound++;
		for(i=n-1;i>=len[upbound];i--)
			if(j<len[i])
				putchar(line[i][j]);
			else
				putchar(' ');
		printf("\n");	
	}
	return 0;
}
