#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

#define MAX 4
#pragma warning(disable:4996)

int graph[MAX][MAX] = { {0, } };
int visit[MAX] = { 0, };

stack<int> st;
queue<int> qu;

void dfs() {
    //st.push();
    int adjacent = 0;
    
    visit[0] = 1;
    st.push(0);
    printf("%d",0);
    
    while (!st.empty()) {
        //adjacent = st.top();
        
        for (int i = 0; i < MAX; i++) {
            if (graph[st.top()][i] == 1 && visit[i] == 0) {
                adjacent = i;
                break;
            }
        }
        
        if (graph[st.top()][adjacent] == 1 && graph[adjacent][st.top()] == 1 && visit[adjacent] == 0) {
            printf("%d ", adjacent);
            st.push(adjacent);
            
            visit[adjacent] = 1;
        }
        else {
            st.pop();
            
        }
    }
    
}

void bfs() {
    for (int i = 0; i < MAX; i++) {
        visit[i] = 0;
    }
    int adjacent=0;
    visit[0] = 1;
    qu.push(0);
    
    while (!qu.empty()) {
        adjacent = qu.front();
        for(int i=0;i<MAX;i++){
            if (graph[adjacent][i] == 1 && visit[i] == 0) {
                visit[i] = 1;
                qu.push(i);
            }
        }
        printf("%d ", adjacent);
        qu.pop();
    }
}



int main() {
    graph[0][1] = 1;
    graph[1][0] = 1;
    graph[1][3] = 1;
    graph[3][1] = 1;
    graph[2][3] = 1;
    graph[3][2] = 1;
    graph[2][0] = 1;
    graph[0][2] = 1;
    
    
    dfs();
    
    printf("\n");
    
    bfs();
    
    
    
}
