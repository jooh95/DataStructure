#include<stdio.h>


void merge(int* list, int l, int m, int r);

void merge_sort(int* list, int left, int right) {
    int mid=(left+right)/2;
    
    if (left<right) {
        merge_sort(list, left, mid);
        merge_sort(list, mid+1, right);
        merge(list, left, mid, right);
    }
    else { return; }
    
    
    
}

void merge(int* list, int left, int mid, int right) {
    int lList[8];
    int rList[8];
    int i, j, k;
    
    int lLength = mid - left + 1;
    int rLength = right - mid;
    
    
    for (i = 0; i < lLength; i++) {
        lList[i] = list[left + i];
    }
    
    for (j = 0; j < rLength; j++) {
        rList[j] = list[mid + 1 + j];
    }
    
    i = 0;
    j = 0;
    k = left;
    
    while (i < lLength && j < rLength) {
        if (lList[i] <= rList[j]) {
            list[k] = lList[i];
            i++;
        }
        else {
            list[k] = rList[j];
            j++;
        }
        k++;
    }
    
    while (i < lLength) {
        list[k] = lList[i];
        i++;
        k++;
    }
    
    while (j < rLength) {
        list[k] = rList[j];
        j++;
        k++;
    }
}


int main() {
    int data[8] = { 69,10,30,2,16,8,31,22 };
    
    merge_sort(data, 0, 7);
    
    for (int i = 0; i < 8; i++) {
        printf("%d ", data[i]);
    }
    
    
    return 0;
}
