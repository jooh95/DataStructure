#include <stdio.h>
#include <stdlib.h>
#include<Windows.h>
#pragma warning (disable:4996)



int top;
char* stack;

int isEmpty() {
    if (top != 0) {
        return 0;
    }
    else {
        return 1;
    }
}

int isFull() {
    if (top == 9) {
        return 1;
    }
    else {
        //stack = (char*)realloc(sizeof(stack) * 2);
        
        //return 0;
    }
}
void push(char data) {
    if (top != 9 ) {
        stack[top] = data;
        top++;
        
    }
    else {
        //realloc
        
        //push
        
        
    }
}
int pop() {
    if (isEmpty() != 1) {
        int tmp = top;
        top--;
        return stack[tmp];
    }
    else {
        return ERROR;
    }
    
}
int main() {
    char input[10];
    scanf("%s",input);
    
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == '(') {
            push(input[i]);
        }
        else if (input[i] == ')') {
            if (pop() == ERROR) {
                printf("No");
                system("pause");
                return 0;
            }
        }
        
    }
    
    if (isEmpty()) {
        printf("Yes");
    }
    else {
        printf("No");
    }
    
    
    system("pause");
    return 0;
}
