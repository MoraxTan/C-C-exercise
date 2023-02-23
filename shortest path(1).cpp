#include<iostream>
using namespace std;

int minimumDist(int dist[], bool Tset[], int n) {
	int min = 100000,index;

	for(int i = 0;i < n;i++) {
		if(Tset[i]==false && dist[i]<=min) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void Dijkstra(int graph[10][10], int src, int n) {
	int dist[10];                           
	bool Tset[10];
	
	for(int i = 0; i < n; i++) {
		dist[i] = 100000;
		Tset[i] = false;	
	}
	
	dist[src] = 0;
	
	for(int i = 0; i < n; i++) {
		int m = minimumDist(dist,Tset,n); 
		Tset[m] = true;
		for(int i = 0; i < n; i++) {
			if(!Tset[i] && graph[m][i] && dist[m]!=100000 && dist[m]+graph[m][i]<dist[i])
				dist[i] = dist[m] + graph[m][i];
		}
	}
	for(int i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	int graph[10][10];
	for(int i = 0; i < n; i++) {
		for(int j = 0; j < n; j++) {
			cin >> graph[i][j];
		}
	}
	
	Dijkstra(graph,0,n);
	return 0;	                        
}
