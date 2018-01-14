#include<stdio.h>
#include<stdlib.h>
//#pragma warning (disable:4996)

#define SIZE 5

int front = -1, rear = -1;
int queue[SIZE];

int isFull() {
    if (rear != -1 && (rear + 1) % SIZE == front + 1) {
        printf("FULL");
        return 1;
    }
    else {
        return 0;
    }
}
void inQueue(int data) {
    
    if (!isFull()) {
        rear = (rear + 1) % SIZE;
        queue[rear] = data;
    }
}

int isEmpty() {
    if (rear == front) {
        //if ((front + 1) % SIZE == 0) {
        // front = (front + 1) % SIZE;
        //}
        return 1;
    }
    else {
        return 0;
    }
}
int deQueue() {
    int tmp;
    if (!isEmpty()) {
        front = (front + 1) % SIZE;
        tmp = queue[front];
        queue[front] = -999; //deQueue할 때, 원래 값을 충분히 작은 값으로 바꿈
        return tmp;
    }
    else {
        printf("Empty");
        return 0;
    }
}

int main() {
    int count = 0;
    int* input;
    int n, target, tmp;
    int max = -9999;
    
    scanf("%d %d", &n, &target);
    
    input = (int*)malloc(sizeof(int) * n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &input[i]);
        inQueue(input[i]);
    }
    
    while (!isEmpty()) {
        max = -9999;
        tmp = deQueue();
        
        for (int i = 0; i < n; i++) { // 값을 비교해서 최대값을 구함
            if (max < queue[i]) {
                max = queue[i];
            }
        }
        
        if (tmp < max) {  //큐에  tmp 보다 큰 값이 하나라도 있으면 inQueue
            inQueue(tmp);
        }
        else {
            count++;
            
            if(tmp == input[target]){  //원하는 target에 도달 했을 때 출력
                printf("the order of the target value is: %d\n", count);
                free(input);
                return 0;
            }
        }
    }
    
    free(input);
    return 0;
}
