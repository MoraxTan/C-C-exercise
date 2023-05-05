#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>

#define TOTAL 10000

using namespace std;

vector <int> v;
vector <int> v2;
map <int, int > s;

int prime[TOTAL];

void seive()
{
	int i;
	for(i=3; i<sqrt(TOTAL); i+=2)
    {
		if(!prime[i])
        {
			for(int j= i+i; j<= TOTAL; j+=i)
            {
				prime[j] = 1;
			}
		}
	}
	for(i=3; i<= TOTAL; i+=2)
    {
		if(!prime[i])
        {
			v.push_back(i);

		}
	}
}
int main()
{
    int i, t, Dsum, sum, number[20];
    string s;
    int index[] = {1, 3, 6, 8, 11, 13, 16, 18}; /* which undouble */
    int ind[] = {0, 2, 5, 7, 10, 12, 15, 17}; /* which will make double */

	cin >> t;
	getchar();

	while(t--)
    {
		getline(cin, s);
		int c = 0;
		Dsum = sum = 0;

		for(i=0; i<8; i++)
        {
			number[i] = (s[ind[i]] - '0')*2;
		}

		for(i=0; i<8 ; i++)
        {
			if(number[i] > 9)
            {
				Dsum += number[i] % 10;
				Dsum += number[i]/10;
			}
			else Dsum += number[i];
		}

		for(i=0; i<8 ; i++)
        {
			sum += s[index[i]] - '0';
		}

		if((Dsum+sum)%10 == 0)
        {
			cout << "Valid" << endl;
		}
		else{
            cout << "Invalid"<< endl;
        }
	}
    return 0;
}