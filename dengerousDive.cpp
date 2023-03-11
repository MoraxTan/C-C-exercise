#include<stdio.h>
#include<iostream>
using namespace std;
int f[20000] = {0};
int main() {
	int count=0,n,m,sum,x;
	while(scanf("%d %d",&n,&m)!=EOF) {
		count++;
		for(int i=1;i<=m;i++) {
			cin>>x;
			f[x]=count;
		}
		sum = 0;
		for(int i=1;i<=n;i++) {
			if(f[i]!=count) {
				sum++;
				cout<<i<<" ";
			}
		}
		if(sum == 0) cout<<"*";
		cout << endl;
	}
}
