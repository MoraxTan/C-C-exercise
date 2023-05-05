#include <stdio.h>

int main()
{
    int y,i, x, t;
    int n, k[100], p;

    scanf("%d", &t);
    for(i=1; i<=t; i++)
    {
		x=0;
		y=0;
        scanf("%d", &n);

        for(p=0; p<n; p++)
        {
			scanf("%d", &k[p]);
        }
		for(p=0; ; p++)
        {
			if(p==n-1)  break;
			if(k[p]==k[p+1])    continue;

			if(k[p]>k[p+1])
            {
				x++;
			}
			else 
            {
                y++;
            }
        }
        printf("Case %d: %d %d\n",i, y, x);
	}
    return 0;
}