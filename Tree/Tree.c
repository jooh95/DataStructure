#include<stdio.h>
#include<stdlib.h>
#pragma warning(disable:4996)


void preOrder(int* tree, int index);
void inOrder(int *tree, int index);
void postOrder(int *tree, int index);
int main() {
	int n;
	int* tree;
	int* input;

	scanf("%d", &n);
	tree = (int*)malloc(sizeof(int) * 500);
	input = (int*)malloc(sizeof(int) * (n + 1));

	for (int i = 0; i < 500; i++) {
		tree[i] = -1;
	}

	for (int i = 1; i <= n; i++) {
		scanf("%d", &input[i]);
	}

	tree[1] = input[1];

	//BST 만드는 코드

	int i = 1;
	int j = 2;
	while (j <= n) {
		printf("i: %d\n", i);
		printf("j: %d\n", j);
		if (tree[i] < input[j]) {
			if (tree[(2 * i) + 1] == -1) {
				tree[(2 * i) + 1] = input[j];
				j++;
				i = 1;
				continue;
			}
			else {
				i = (2 * i) + 1;
				continue;
			}
		}

		if (tree[i] > input[j]){
			if (tree[2 * i] == -1) {
				tree[2 * i] = input[j];
				j++;
				i = 1;
				continue;
			}
			else {
				i = 2 * i;
				continue;
			}
		}

	}


	preOrder(tree, 1);
	printf("\n");
	inOrder(tree, 1);
	printf("\n");
	postOrder(tree, 1);
	free(input);
	free(tree);
	return 0;

}

void preOrder(int* tree, int index) {
	if (tree[index] != -1) {
		printf("%d ", tree[index]);
		preOrder(tree, index * 2);
		preOrder(tree, (index * 2) + 1);
	}
	else {
		return;
	}
}

void inOrder(int *tree, int index) {
	if (tree[index] != -1) {
		inOrder(tree, index * 2);
		printf("%d ", tree[index]);
		inOrder(tree, (index * 2) + 1);
	}
	else {
		return;
	}
}

void postOrder(int *tree, int index) {
	if (tree[index] != -1) {
		postOrder(tree, index * 2);
		postOrder(tree, index * 2 + 1);
		printf("%d ", tree[index]);
	}
	else {
		return;
	}
}