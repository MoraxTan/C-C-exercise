//Triangle Wave UVA
#include<stdio.h>

int main()
{
    int triangleCount,theAmplitude,theFrequency;
    scanf("%d", &triangleCount);
    while (triangleCount--)
    {
        scanf("%d\n%d", &theFrequency, &theAmplitude);
        for(int i=0; i<theAmplitude;i++)
        {
            for(int j=1; j<=theFrequency; j++)
            {
                for(int k=0; k<j; k++)
                {
                    printf("%d",j);
                }
                printf("\n");
            }

            for(int j=theFrequency-1; j>=1; j--)
            {
                for(int k=0; k<j; k++)
                {
                    printf("%d",j);
                }
                printf("\n");
            }

            if(i != theAmplitude-1)
            {
                printf("\n");
            }
        }

        if(triangleCount)
        {
            printf("\n");
        }
        
    }
    
    return 0;
}