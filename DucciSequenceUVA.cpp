#include "stdio.h"
#include "stdlib.h"
#include "math.h"
#include "vector"
#include "map"
#include "algorithm"
#include "assert.h"

using namespace std;

int nextSeq(int A[], int n)
{
    int B[32];
    A[n] = A[0];
    for(int i=0;i<n;i++)
    {
        B[i] = abs(A[i]-A[i+1]);
    }
    for(int i=0;i<n;i++)
    {
        A[i] = B[i];
    }
    return 1;
}

int main()
{
    int testCase, n, A[32];
    scanf("%d",&testCase);
    while(testCase--)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&A[i]);
        }
        map<int ,int > R;
        do{
            int ok = 1, hash = 0;
            int a = 63689, b = 378551;
            for(int i=0;i<n;i++)
            {
                hash = hash * a + A[i], a = a * b;
                ok &= A[i]==0;
            }
            if(ok)
            {
                puts("ZERO");
                break;
            }
            int &f = R[hash];
            if(f)
            {
                puts("LOOP");
                break;
            }
            f=1;
        }while(nextSeq(A, n));
    }
    return 0;
}