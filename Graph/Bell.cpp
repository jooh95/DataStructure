#include<stdio.h>

#pragma warning(disable:4996)

#define N 8
int data[N][N];
int dist[N];

typedef struct edge {
	int start;
	int root;
	int weight;
}Edg;

int main() {

	Edg edge[14];
	int max = 999;
	int E = 14;
	for (int i = 0; i < N; i++) {
		dist[i] = max;
	}

	for (int i = 0; i < E; i++) {
		scanf("%d %d %d", &edge[i].start, &edge[i].root, &edge[i].weight);
	}
	dist[0] = 0;

	for (int k = 0; k < N-1;k++) {

		for (int i = 0; i < E; i++) {

			int s = edge[i].start;
			int d = edge[i].root;

			if (dist[s] != max && dist[d] > edge[i].weight + dist[s]) {
				dist[d] = edge[i].weight + dist[s];
			}
		}

	//}
	for (int i = 0; i < N; i++) {
		printf("%d ", dist[i]);
	}


}