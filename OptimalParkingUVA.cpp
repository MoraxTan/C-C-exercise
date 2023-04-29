#include "iostream"
using namespace std;

int main()
{
    long long int testCAses, nmax, nmin, n, value;
    cin >> testCAses;
    while(testCAses--)
    {
        cin >> value;
        cin >> n;
        value--;
        nmax = nmin = n;
        while(value--)
        {
            cin >> n;
            if(n > nmax)    nmax = n;
            if(n < nmin)    nmin = n; 
        }

        cout << (nmax - nmin)*2 << endl;
    }
    return 0;
}