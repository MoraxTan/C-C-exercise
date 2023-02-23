#include<stdio.h>

int main () {
	int n;
	int h; //numbers of column

	scanf("%d",&n);
	while(n--){
		scanf("%d",&h);

		for(int i = 1; i <= h; i++) {
			for(int j = 0; j<h-i ;j++) {
				printf(" ");
			}
			
			for(int k = 0; k<2*i-1; k++) {
				printf("*");
			}
			
			for(int j = 0; j<h-i ;j++) {
				printf(" ");
			}
			
			printf("\n");
		}
	}
	return 0;
} 
