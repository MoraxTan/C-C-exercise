#include <stdio.h>
	int count;
void hanoi(int n, char A, char B, char C) { 
	count++;
	printf("%d\n", count);
	if(n == 1) {
		printf("Move sheet %d from %c to %c\n", n, A, C);
	}
	else {
		hanoi(n-1, A, C, B);
		printf("Move sheet %d from %c to %c\n", n, A, C); hanoi(n-1, B, A, C);
	}
	
}
int main() {
	int n;
	while(scanf("%d", &n)!=EOF){
		hanoi(n, 'A', 'B', 'C');
	}
	return 0;
}

