#include <stdio.h>
#include <string.h>

int main()
{
	int l, i, sum;
	char c[1005];


	while(1){
		sum =0;
		scanf("%s", c);
		l = strlen(c);
		if(l==1 && c[0]=='0')
			break;


		for(i=0;i<l;i++){
			sum= (sum*10+ c[i]-'0')% 11;
        }
        if(sum==0){
			printf("%s is a multiple of 11.\n", c);
        }
        else printf("%s is not a multiple of 11.\n", c);

	}
    return 0;
}
