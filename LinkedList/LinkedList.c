#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node* next;
}Node;

Node* createHead();
void insertNode(Node* head, int data, int index);
void deleteNode(Node* head, int index);
void searchList();  //try by yourself!!

int main(){

	Node* head;

	head = createHead();


	insertNode(head, 1, 0);
	insertNode(head, 2, 1);
	insertNode(head, 3, 1);
	deleteNode(head, 1);
	printf("%d\n", head->next->data);
	printf("%d\n", head->next->next->data);
	printf("%d\n", head->next->next->next->data);


	free(head);
	
	return 0;
}


Node* createHead(){
	Node* head = (Node*)malloc(sizeof(Node));
	head->data = NULL;
	head->next = NULL;

	return head;
}

void insertNode(Node* head, int data, int index){
	Node* node = (Node*)malloc(sizeof(Node));
	Node* search = (Node*)malloc(sizeof(Node));
	Node* first = (Node*)malloc(sizeof(Node));
	node->data = data;

	if (index < 0){
		printf("index is too small\n");
		return;
	}

	if (index == 0){
		node->next = head;
		head->next = node;
	}
	else{
		search = head;
		for (int i = 0; i < index; i++){
			search = search->next;
		}
		node->next = search->next;
		search->next = node;
	}
}

void deleteNode(Node* head, int index){

	Node* search = (Node*)malloc(sizeof(Node));
	Node* node = (Node*)malloc(sizeof(Node));

	search = head;

	if (index < 0){
		printf("index is too small\n");
		return;
	}

	if (index == 0){
		head = search->next;
		free(search);
	}
	else{
		for (int i = 0; i <= index - 1; i++){
			search = search->next;
		}

		node = search->next;
		search->next = search->next->next;
		free(node);
	}
}


void searchList(){
	//try by yourself!!
}