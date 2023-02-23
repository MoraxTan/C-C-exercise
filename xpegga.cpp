#include<stdio.h>
#include<string.h>
int a[100000], b[100000], c[100000];

int main() {
    int i, j, m = 0, n = 0, t = 0, x = 0,Z=0;
    int q, w = 0;
    int max = 0, maxa = 0, maxb = 0;
    int flag = 1;

    scanf("%d", &t);

    int tempX, tempY;

    while (Z < t) {
    	memset(a, 0, sizeof(a));
   	 	memset(b, 0, sizeof(b));
    	memset(c, 0, sizeof(c));
    	
        Z++;
        scanf("%d", &x);
        q = x;
        for (int y = 0; y < x; y++) {
            scanf("%d", &tempX);
            scanf("%d", &tempY);
            if (y == 0)
                maxa = tempY;
            a[tempY] = tempX;
        }

        scanf("%d", &x);
        w = x;
        for (int y = 0; y < x; y++) {
            scanf("%d", &tempX);
            scanf("%d", &tempY);
            if (y == 0)
                maxb = tempY;
            b[tempY] = tempX;
        }
		
		//printf("\n");
        max = maxa + maxb;

        for (int o = 0; o <= maxa; o++) {
            for (int p = 0; p <= maxb; p++) {
                c[o+p] += a[o] * b[p];
            }
        }
        
        bool findhead = false;
        
        for (int tempZ = max; tempZ >= 0; tempZ--) {
        	if((c[tempZ] != 0)&&(!findhead)) {
        		findhead = true;
        		printf("%d %d", c[tempZ], tempZ);
			}
			else {
				if (c[tempZ] != 0)
                printf(" %d %d", c[tempZ], tempZ);
			}
        }
        if(Z!=t) printf("\n");
    }
  // printf("\n");
    return 0;
}
