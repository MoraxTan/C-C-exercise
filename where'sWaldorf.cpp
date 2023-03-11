#include <bits/stdc++.h>
 
using namespace std;

int drow[] = {0, 1, 0, -1,   1, -1, -1, 1};
int dcol[] = {1, 0, -1, 0,   1, -1, 1, -1};
const int D = sizeof(drow) / sizeof(int);
 
const int N = 50;
char g[N][N], w[N + 1];
 
void find(int m, int n)
{
    int len = strlen(w);
 
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            if(g[i][j] == w[0]) {
                for(int k = 0; k < D; k++) {
                    int nextrow = i, nextcol = j, l = 0;
                    while(g[nextrow][nextcol] == w[l]) {
                        if(++l == len) {
                            cout << i + 1 << " " << j + 1 << endl;
                            return;
                        }
                        nextrow += drow[k];
                        nextcol += dcol[k];
                        if(nextrow < 0 || nextrow >= m || nextcol < 0 || nextcol >= n)
                            break;
                    }
                }
            }
        }
}
 
int main()
{
    int t, m, n, k;
    cin >> t;
    while(t--) {
        cin >> m >> n;
        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++) {
                cin >> g[i][j];
                g[i][j] = toupper(g[i][j]);
            }
 
        cin >> k;
        for(int i = 0; i < k; i++) {
            cin >> w;
            for(int j = 0; w[j]; j++)
                w[j] = toupper(w[j]);
            find(m, n);
        }
 
        if(t)
            cout << endl;
    }
 
    return 0;
}
