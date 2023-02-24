#include<stdio.h>
#include<string.h>

int finger[14][11] = 
{
	{0,0,1,1,1,0,0,1,1,1,1},
	{0,0,1,1,1,0,0,1,1,1,0},
	{0,0,1,1,1,0,0,1,1,0,0},
	{0,0,1,1,1,0,0,1,0,0,0},
	{0,0,1,1,1,0,0,0,0,0,0},
	{0,0,1,1,0,0,0,0,0,0,0},
	{0,0,1,0,0,0,0,0,0,0,0},
	{0,0,0,1,0,0,0,0,0,0,0},
	{0,1,1,1,1,0,0,1,1,1,0},
	{0,1,1,1,1,0,0,1,1,0,0},
	{0,1,1,1,1,0,0,1,0,0,0},
	{0,1,1,1,1,0,0,0,0,0,0},
	{0,1,1,1,0,0,0,0,0,0,0},
	{0,1,1,0,0,0,0,0,0,0,0},
};

int code[255];
int state[11];
int num[11];

void counting(char song[])
{
	int l,i,j,t;
	memset(num, 0, sizeof(num));
	memset(state, 0, sizeof(state));
	l=(int)strlen(song);
	
	for(i = 0; i < l; i++)
	{
		t = code[song[i]];
		for(j = 1; j < 11; j++)
		{
			if(state[j] == 0 && finger[t][j] == 1)
			{
				num[j]++;
				state[j] = 1;
			}
			
			if(finger[t][j] == 0) state[j] = 0;
		}
	}
	
	for(i = 1; i <= 10; i++)
	{
		printf("%d", num[i]);
		if(i == 10) printf("\n");
		else printf(" ");
	}
}

int main()
{
	int t,i;
	char song[205];
	code['c'] = 0, code['d'] = 1, code['e'] = 2;
	code['f'] = 3, code['g'] = 4, code['a'] = 5;
	code['b'] = 6, code['C'] = 7, code['D'] = 8;
	code['E'] = 9, code['F'] = 10, code['G'] = 11;
	code['A'] = 12, code['B'] = 13;
	
	scanf("%d\n",&t);
	for(i = 1; i <= t; i++)
	{
		gets(song);
		counting(song);
	}
	return 0;
}
