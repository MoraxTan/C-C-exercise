#include<iostream>
using namespace std;

int main() {
	int inputSize;
	int graph[10][10], dis[10], temp[10];
	bool visited[10];
	
	cin >> inputSize;
	for (int loopY = 0; loopY < 10; loopY++) {
		visited[loopY] = false;
		dis[loopY] = 10000;
		temp[loopY] = 0;
		for (int loopX = 0; loopX < 10; loopX++) {
			graph[loopY][loopX] = 0;
		}
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

	int root = 0;
	for (int loopY = 0; loopY < inputSize; loopY++) {
		int sPosX = 0;
		for (int loopX = 0; loopX < inputSize; loopX++) {
			if (visited[sPosX]) {
				sPosX = loopX;
			}
			else if ((dis[loopX] < dis[sPosX]) && !visited[loopX]) {
				sPosX = loopX;
			}
		}
		if (loopY == 0) {
			sPosX = root;
		}
		for (int loopX = 0; loopX < inputSize; loopX++) {
			if (graph[sPosX][loopX] == 0) {
				temp[loopX] = 10000;
			}
			else
			{
				if(loopY == 0) {
					temp[loopX] = graph[sPosX][loopX];
				}
				else
				{
					temp[loopX] = dis[sPosX] + graph[sPosX][loopX];
				}
			}
		}
		for (int loopX = 0; loopX < inputSize; loopX++) {
			if (temp[loopX] < dis[loopX]) {
				dis[loopX] = temp[loopX];
			}
		}
		if (loopY == root) {
			dis[root] = 0;
		}
		visited[sPosX] = true;
	}

	for (int loopY = 0; loopY < inputSize; loopY++) {
		if (dis[loopY] == 10000) {
			dis[loopY] = 0;
		}
		cout << dis[loopY] << " ";
	}
	return 0;
}
