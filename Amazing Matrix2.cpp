#include<stdio.h>

int main () {
	int m; //columns
	//this is square matrix
	scanf("%d",&m);
	
	if(m >= 1 && m <= 7) {
		int a[m][m];//square matrix
		for(int i = 0 ; i < m ; i++) {
			for(int j = 0 ; j < m ; j++) {
				scanf("%d",&a[i][j]);
			}
		}
	
	
	int Count = 0;
	int x = m-1;
	int n = 0;
	
	for(int i = 0 ; i < m ; i++) {
		if(a[x][n] == a[n][x]) {
			Count++;
			x--;
			n++;	
		}
	}
	
	if(Count >= m) {
		printf("Symmetric ");
	}
	
	int Count2=0;
	for(int i=0;i<m;i++) {
		for(int j=0;j<m;j++) {
			if(a[i][j]==a[i+1][j+1]) {
				Count2++;
			}
		}
	}
	if(Count2 >= m) {
		printf("Asymmetric ");
	}
	
	int unit[m*m];
	
	for(int i = 1 ; i <= m*m ; i++) {
		unit[i]=i;
	}
	
	int Count3 = m*m;
	
	for(int k = 1 ; k <= m*m ; k++) {
		for(int i = 0 ; i < m ; i++) {
			for(int j = 0 ; j < m ; j++) {
				if(unit[k] == a[i][j]) {
					Count3--;
					unit[k]=0;
				}
			}
		}
	}
	
	int Count4[m];
	int Count5[m];
	
	for(int i = 0 ; i < m ; i++) {
		Count4[i] = 0;
		Count5[i] = 0;
	}
	for(int i = 0 ; i < m ; i++) {
		for(int j = 0 ; j < m ; j++) {
			Count4[i] = Count4[i] + a[i][j];
		}
	}
	for(int j = 0 ; j < m ; j++) {
		for(int i = 0 ; i < m ; i++) {
			Count5[i] = Count5[i] + a[i][j];
		}
	}
	int Count6 = 0;
	for(int i = 0 ; i < m ; i++) {
		if(Count4[i] == Count4[i+1] && Count5[i] == Count5[i+1]){
			Count6++;
		}
	}
	if(Count3 == 0 && Count6 == m-1) {
		printf("MAGIC SQUARE ");
		}
	}
}

