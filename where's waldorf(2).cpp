#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 100
char str[N][N], a[N];
int t[8][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}, {-1,1}, {1,-1}, {1,1}, {-1,-1}};//for eight directions 
int  k, m, n, p, q, len;
 
int find(int x, int y) {
	int row = x, col = y;
	if (str[x][y] == a[0]) {
		for (k = 0; k < 8; k++) {
			int cnt = 0;
			while (1) {
				if (x < 0 || y < 0 || x >= m || y >= n || str[x][y] != a[cnt])
					break;
				if (cnt == len - 1)
					return 1;
				x += t[k][0];
			   	y += t[k][1];
				cnt++;
			}
			x = row; 
			y = col;
		}
		return 0;
	}
	else return 0;
}
 
int main() {
	scanf("%d", &q);
	while (q--) {
		scanf("%d %d", &m, &n);
		for (int i = 0; i < m; i++)
			scanf("%s", str[i]);
 
		for (int i = 0; i < m; i++) //turn word to capital           
			for (int j = 0; j < n; j++)
				str[i][j] = toupper(str[i][j]);
 
		scanf("%d", &p);
		while (p--) {
			scanf("%s", a);
			len = strlen(a);
			for (int i = 0; i < len; i++) //turn word to capital too
				a[i] = toupper(a[i]);
			int flag;
			for (int i = 0; i < m; i++) {
				for (int j = 0; j < n; j++) {
					flag = 0;
					if (find(i, j)) {
						flag = 1;		
						printf("%d %d\n", i + 1, j + 1);
						break;
					}
				}
				if (flag)
					break;
			}
		}
		if (q)
			printf("\n");
	}
	return 0;
}
