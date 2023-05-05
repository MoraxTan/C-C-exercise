#include <stdio.h>

int main()
{
    int y,i, x, t;
    int n, k[100], p;

    scanf("%d", &t);
    for(y=1; y<=t; y++)
    {

		for(i=0; i<10; i++)
        {
			scanf("%d", &k[i]);
		}

		if(y==1)
        {
			printf("Lumberjacks:\n");
		}

		if(k[0] > k[1])
        {
			for(x=1; x<9; x++)
            {
				if(k[x] < k[x+1])
                {
					break;
				}
			}
		}
		else if(k[0] < k[1])
        {
			for(x=1; x<9; x++)
            {
				if(k[x] > k[x+1])
                {
					break;
				}
			}
		}

		if(x==9)
        {
			printf("Ordered\n");
		}
		else 
        {
            printf("Unordered\n");
        }
    }
	return 0;
}