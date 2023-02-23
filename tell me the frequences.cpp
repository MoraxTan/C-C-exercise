#include<stdio.h>
#include<string.h>

int main()
{
	int i,len,max,set=0;
	int freq[256];
	char str[9999],c;
	while(gets(str)!=NULL)
	{
		for(i=0;i<256;i++) 
			freq[i]=0;
			
		len=(int)strlen(str);
		
		for(i=0;i<len;i++) 
			freq[str[i]]++;
			
		set++;
		
		if(set>1) 
			printf("\n");
			
		for(i=1;i<=max;i++)
		{
			for(c=127;c>=1;c--)
			{
				if(freq[c]==i)
					printf("%d %d\n",c,freq[c]);
			}
		}
	}
	return 0;
}
