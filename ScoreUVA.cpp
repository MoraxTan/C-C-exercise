#include "iostream"
#include "string.h"

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        string line;
        cin >> line;
        int count=0, previos = 0;

        for(int i=0;i<line.size();++i)
        {
            if(line[i]=='O')
            {
                ++previos;
                count+=previos;
            }
            else
            {
                previos=0;
            }
        }
        cout << count <<'\n';
    }
    
    return 0;
}