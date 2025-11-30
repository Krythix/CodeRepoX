#include <iostream>
#include <vector>
using namespace std;

// small root
void up(int arr[], int pos) {
    int i=pos;
    while(i>0 && arr[(i-1)/2] > arr[i]) {
        swap(arr[(i-1)/2], arr[i]);
        i = (i-1)/2;
    }
}

void down(int arr[], int size, int pos) {
    int i=pos, j;
    while(2*i+1 < size) {
        int lc = i*2+1, rc = i*2+2;
        j=lc;
        if(rc < size && arr[rc] < arr[i]) j=rc;
        else if(arr[lc] < arr[i]) j = lc;
        else break;
        swap(arr[i], arr[j]);
        i = j;
    }
}

// 下沉法建堆， 更高效
void buildHeap(int arr[], int size) {
    for(int i=size/2; i>=0; i--) {
        down(arr, size, i);
    }
}

int main() {
    int arr[10] = {3,5,1,4,6,8,2,0};
    buildHeap(arr, 8);
    arr[8] = -1;
    up(arr, 8);

    return 0;
}