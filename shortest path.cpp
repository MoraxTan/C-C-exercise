#include<iostream>
#include<string.h>
using namespace std;

int main() {
	int inputSize;
	
	cin >> inputSize;
	
	int** graph = new int* [inputSize];
	for (int i = 0; i < inputSize; ++i) {
		graph[i] = new int[inputSize];
	}
	
	for (int loopY = 0; loopY < inputSize; loopY++) {
		for (int loopX = 0; loopX < inputSize; loopX++) {
			cin >> graph[loopY][loopX];
		}
	}
	
	for (int loopY = 0; loopY < inputSize; loopY++) {
		for (int loopX = 0; loopX < inputSize; loopX++) {
			if (graph[loopY][loopX] != 0) {
				graph[loopX][loopY] = graph[loopY][loopX];
			}
		}
	}
	
	int* disCal = new int[inputSize];
	
	for (int loopY = 0; loopY < inputSize; loopY++) {
		memset(disCal, 0, inputSize * sizeof(disCal));
		if (loopY == 0) {
			memset(graph[loopY], 0, inputSize * sizeof(graph[loopY]));
			cout << "0 ";
		}
		else
		{
			for (int loopX = 0; loopX < loopY; loopX++) {
				if (graph[loopY][loopX] != 0) {
					int cur = graph[loopY][loopX];
					int nextY = loopX;
					while (true)
					{
						disCal[loopX] += cur;
						cur = 0;
						for (int getX = 0; getX < loopY; getX++) {
							if (graph[nextY][getX] != 0) {
								cur = graph[nextY][getX];
								nextY = getX;
								break;
							}
						}
						if (cur == 0) {
							break;
						}
					}
				}
			}
			int sPosX = 0;
			
			for (int loopX = 0; loopX < inputSize; loopX++) {
				if ((disCal[sPosX] == 0) || ((disCal[loopX] < disCal[sPosX]) && (disCal[loopX] != 0))) {
					sPosX = loopX;
				}
			}
			int temp = graph[loopY][sPosX];
			cout << disCal[sPosX] << " ";
			memset(graph[loopY], 0, inputSize * sizeof(graph[loopY]));
			graph[loopY][sPosX] = temp;
		}
	}
	
	for(int loopY = 0; loopY < inputSize; loopY++){
		delete[] graph[loopY];
	}
	delete[] graph;
	delete[] disCal;
	return 0;
}
