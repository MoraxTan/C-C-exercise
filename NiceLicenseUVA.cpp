#include <bits/stdc++.h>

using namespace std;

map <char, int> myMap;

int main()
{
    int i, x, n;
    int num, sum;
    int tc;
    char cha[5];
    char c;

    c = 'A';
    for(i=0; i<=26; i++)
    {
        myMap[c] = i;
        c++;
    }

    cin >> tc;
    while(tc--)
    {
        sum = 0;
        scanf("%3s-%d", &cha, &num);

        sum = myMap[cha[0]] * pow(26, 2);
        sum += myMap[cha[1]] * 26;
        sum += myMap[cha[2]] ;
        
        if(abs(sum-num) <= 100)
        {
            cout << "nice" << endl;
        }
        else 
        {
            cout << "not nice" << endl;
        }
    }
	return 0;
}