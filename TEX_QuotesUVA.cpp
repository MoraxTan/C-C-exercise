//TEX Quotes UVA

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main()
{
	char line[1024];
	bool openFile = true;
	while(gets(line))
	{
		int length = strlen(line);
		for(int i=0; i<length;i++)
		{
			if(line[i]=='"')
			{
				if(openFile)
					printf("``");
				else
					printf("''");
				openFile = !openFile;
			}
			else
			{
				printf("%c", line[i]);
			}
		}
		printf("\n");
	}
	return 0;
}
