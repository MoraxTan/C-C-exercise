#include<cstdio>
using namespace std;

int main(){
	long a,b;
	int carry,sum,count;
	scanf("%ld%ld",&a,&b);
	
	while(a||b)
	{
		carry=count=0;
		while(a||b)
		{
			sum = a%10 + b%10 + carry;
			carry=sum>9;
			count+=carry;
			a/=10;
			b/=10;
		}
		if(count == 0)
			printf("No carry operation.\n");
		else if(count==1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operation.\n",count);
		
		scanf("%ld%ld",&a,&b);
	}
	return 0;
}
