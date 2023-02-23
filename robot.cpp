#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<iostream>

using namespace std;

int maps[55][55];
int dxy[4][2] = {0,1,1,0,0,-1,-1,0};

int main() {
	int n,m,x,y,xx,yy,towards[128];
	char start,steps[101],face[5] = "NESW";
	
	towards['N'] = 0;
	towards['E'] = 1;
	towards['S'] = 2;
	towards['W'] = 3;
	
	memset(maps,0,sizeof(maps));
	
	scanf("%d%d",&n,&m);
	while(~scanf("%d %d %c",&x,&y,&start)) {
		scanf("%s",&steps);
		
		int face_now = towards[start];
		int flag = 0;
		for(int i = 0;steps[i];++i) {
			if(steps[i] == 'L') face_now = (face_now + 3)%4;
			if(steps[i] == 'R') face_now = (face_now + 1)%4;
			if(steps[i] == 'F') {
				xx = x+dxy[face_now][0];
				yy = y+dxy[face_now][1];
				if(xx<0||xx>n||yy<0||yy>m) {
					if(maps[x][y]) continue;
					maps[x][y] = 1;
					flag = 1;
					break;
				}
			x = xx;
			y = yy;
			}
		}
		printf("%d %d %c",x,y,face[face_now]);
		if(flag) printf(" LOST");
		printf("\n");
	}
	return 0;
}
