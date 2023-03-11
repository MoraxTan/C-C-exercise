#include<iostream>
#include<algorithm>

using namespace std;

int countDigit[11];

void initCount(void)
{
    for(int k=0; k<10; k++)
    {
        countDigit[k] = 0;
    }
}

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        initCount();
        int N;
        cin>>N;

        for(int i=1; i<=N; i++)
        {
            int score = i;
            while(score)
            {
                countDigit[score%10]++;
                score /= 10;
            }
        }
        
        for(int j=0; j<10; j++)
        {
            cout<<countDigit[j];
            if(j<9)
                cout<<" ";
            else
                cout<<endl;
        }
    }

	return 0;
}