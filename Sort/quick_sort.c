#include<stdio.h>
#include<iostream>
#include <vector>

using namespace std;


void quick(int *data, int start, int end) {
    int l, r, key, tmp;
    
    if (start >= end) {
        return;
    }
    
    key = data[start];
    l = start + 1;
    r = end;
    
    while (l <= r) {
        while (data[l] < key) {
            l++;
        }
        printf("l:%d\n", l);
        while (data[r] > key) {
            r--;
        }
        printf("r:%d\n", r);
        
        if (l <= r) {
            tmp = data[l];
            data[l] = data[r];
            data[r] = tmp;
        }
        else {
            tmp = key;
            data[start] = data[r];
            data[r] = tmp;
        }
    }
    
    quick(data, start, r);
    quick(data, r+1,end );
}

int main() {
    int data[6] = { 5,4,3,10,2,20 };
    int temp;
    /*for (int i = 0; i < 5; i++) {
     for (int j = i; j < 5; j++) {
     if (data[i] < data[j]) {
     temp = data[i];
     data[i] = data[j];
     data[j] = temp;
     }
     }
     }*/
    /*for (int i = 5; i > 0; i--) {
     for (int j = 0; j < i; j++) {
     if (data[j] < data[j + 1]) {
     temp = data[j];
     data[j] = data[j + 1];
     data[j + 1] = temp;
     }
     }
     }*/
    
    //quick(data, 0, 5);
    /*vector<int> array;
     vector<int>::iterator it;
     
     array.reserve(100);
     
     array.push_back(data[0]);
     
     
     
     for (int i = 0; i < 6; i++) {
     for (int j = i; j < 6; j++) {
     array.insert(it+11, 1, 10);
     }
     }
     
     
     
     for (int i = 0; i < 6; i++) {
     printf("%d ", array.at(i));
     }*/
    return 0;
}
