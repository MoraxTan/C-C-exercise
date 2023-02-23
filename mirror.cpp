#include<cstdio>
#include<iostream>
using namespace std;

void chg(char &m, char &n) {
	char temp = m;
	m=n;
	n=temp;
}

int main(void) {
	int T,cmd;
	int row=10;
	int column=21;
	char image[10][21];
	
	cin >> T;
	while (T--) {
		cin.get();  
		
		for (int i=0;i<10;i++) {  
			cin.getline(image[i], 21);
		}
		
		while (1) {
			cin >> cmd;
			if (!cmd) {
				break;
			}
			switch (cmd) {
				case 1:
					for (int j = 0; j < column; j++) {
						for (int t = 0, b = row-1; t < b; t++, b--) {  // vertical
							chg(image[t][j], image[b][j]);
						}
					}
					break;
				case 2:
					for (int i = 0; i < row; i++) {
						for (int t = 0, b = column-2; t < b; t++, b--) {  // horizontal
							chg(image[i][t], image[i][b]);
						}
					}
					break;
				default:
					break;
			}
		}
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column-1; j++) {
				cout << image[i][j];
			}
			cout << endl;
		}
	}
}
