#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdbool.h>

int main() {
	int n,m=0;
	int count=0;
	while(scanf("%d\n",&n)!=EOF) {
		getchar();
		char c;
		while(n--) {
			bool tag = false;
			int letter[26] = {};
			int length = 0;
			while((c=getchar())!='\n') {
				letter[c-'a']++;
				length++;
			}
			bool set[32] = {};
			bool coolWord = true;
			for(int i=0;i<26;i++) {
				if(letter[i]) {
					if(set[letter[i]]||length==letter[i]) {
						coolWord = false;
						break;
					}
					else {
						set[letter[i]] = true;
					}
				}
			}
			if(coolWord) count++;
		}
		printf("Case %d: %d\n",++m,count);
	}
	return 0;
}
