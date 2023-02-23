#include<stdio.h>

int main() {
	while(1) {
		int h1,m1,h2,m2;
		int ans;
		int t,t1;
		scanf("%d %d %d %d",&h1,&m1,&h2,&m2);
		if(h1==0 && m1==0 && h2==0 && m2==0) return 0;
		else {
			if(m1 > m2) {
				h2 = h2-1;
				m2 = m2+60;
			}
			if(h1 > h2) {
				h2 = h2+24;
			}
			t = m1+h1*60;
			t1 = m2+h2*60;
			if(t >= t1) ans=t-t1;
			else ans = t1-t;
			printf("%d\n", ans);
		}
	}
	return 0;
}
