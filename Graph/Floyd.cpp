#include<stdio.h>

#pragma warning(disable:4996)
#define V 5


int data[V][V];

int main() {
	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			scanf("%d", &data[i][j]);
		}
	}

	for (int i = 0; i < V; i++) {
		for (int k = 0; k < V; k++) {
			for (int j = 0; j < V; j++) {
				if (data[i][k] + data[k][j] < data[i][j]) {
					data[i][j] = data[k][j] + data[i][k];
				}
			}
		}
	}

	for (int i = 0; i < V; i++) {
		for (int j = 0; j < V; j++) {
			printf("%d ", data[i][j]);
		}
		printf("\n");
	}
	return 0;
} 