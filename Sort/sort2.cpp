#include <iostream>
using namespace std;

void insertionsort(int arr[], int n) {
    int i, j;
    for(i = 1; i < n; ++i) {
        for(j = i; j > 0; --j) {
            if(arr[j-1] > arr[j]) {
                swap(arr[j-1], arr[j]);
            }
        }
    }
}

void quicksort(int arr[], int left, int right) {
    if(left >= right) return ;
    int pivot = right;
    // 注意需要保留排序的区间开始和结束的下标
    int start = left;
    int end = right;
    while(left < right) {
        while(left < right && arr[left] < arr[pivot]) {
            left++;
        }
        while(left < right && arr[right] >= arr[pivot]) {
            right--;
        }
        swap(arr[left], arr[right]);
    }
    swap(arr[left], arr[pivot]);

    quicksort(arr, start, left-1);
    quicksort(arr, left+1, end);
}

void bubblesort(int arr[], int n) {
    int i, j;
    for(i = n-1; i > 0; --i) {
        bool flag = false;
        for(j = 0; j < i; ++j) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(flag == false) break;
    }
}

void selectionsort(int arr[], int n) {
    int i, j;
    for(i = 0; i < n-1; ++i) {
        int min_idx = i;
        for(j = i+1; j < n; ++j) {
            if(arr[min_idx] > arr[j]) {
                min_idx = j;
            }
        }
        swap(arr[min_idx], arr[i]);
    }
}

int main() {
    int arr[] = {5, 2, 8, 4, 7, 1, 9, 3, 10, 6};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 打印原始数组
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 调用快速排序函数
    insertionsort(arr, n);

    // 打印排序后的数组
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}