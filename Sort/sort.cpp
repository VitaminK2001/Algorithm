#include <iostream>
using namespace std;

void bubblesort(int arr[], int n) {
    for(int i = 0; i < n - 1; ++i) { // 标记已经排好序的个数
        bool flag = false;
        for(int j = 0; j < n - 1 - i; ++j) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }
        if(!flag) {
            break;
        }
    }
}

void insertionsort(int arr[], int n) {
    for(int i = 1; i < n; ++i) {
        int j = i;
        while(j > 0 && arr[j] < arr[j-1]) {
            swap(arr[j], arr[j-1]);
            j--;
        }
    }
}

void quicksort(int arr[], int left, int right) {
    if(left >= right) {
        return ;
    }
    // int pivot = arr[left];
    // int i = left, j = right;
    // while(i < j) {
    //     while(i < j && arr[j] > pivot) { // 为什么需要先找大于pivot的数: 因为最后swap的时候最左边的数到中间来不能和大于它的数交换，所以先要过滤大于它的数
    //         --j;
    //     }
    //     while(i < j && arr[i] <= pivot) { // 从哪里开始等号就在哪边
    //         ++i;
    //     }
    //     swap(arr[i], arr[j]);
    // }
    // swap(arr[i], arr[left]);

    int pivot = arr[right];
    int i = left, j = right;
    while(i < j) {
        while(i < j && arr[i] < pivot) {  // 为什么需要先找小于pivot的数: 因为最后swap的时候最右边的数到中间来不能和小于它的数交换 所以要先把小于它的数过滤掉
            ++i;
        }
        while(i < j && arr[j] >= pivot) { // 从哪里开始等号就在哪边
            --j;
        }
        swap(arr[i], arr[j]);
    }
    swap(arr[i], arr[right]);
    quicksort(arr, i+1, right);
    quicksort(arr, left, i-1);
}

void selectionsort(int arr[], int n) {
    int i, j, min_idx;
    for(i = 0; i < n-1; ++i) {
        min_idx = i;
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
    selectionsort(arr, n);

    // 打印排序后的数组
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}