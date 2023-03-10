#include <iostream>
#include <vector>
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

void merge(vector<int>& arr, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    vector<int> a(n1);
    vector<int> b(n2);
    for(int i = 0; i < n1; ++i) {
        a[i] = arr[left + i];
    }
    for(int i = 0; i < n2; ++i) {
        b[i] = arr[middle + i + 1];
    }
    int k = left, i = 0, j = 0;
    while(i < n1 && j < n2) {
        if(a[i] < b[j]) {
            arr[k++] = a[i++];
        }else {
            arr[k++] = b[j++];
        }
    }
    while(i < n1) {
        arr[k++] = a[i++];
    }
    while(j < n2)  {
        arr[k++] = b[j++];
    }
}

void mergesort(vector<int>& arr, int left, int right) {
    if(left < right) {
        int middle = left + (right - left) / 2;
        mergesort(arr, left ,middle);
        mergesort(arr, middle+1, right);

        merge(arr, left, middle, right);
    }
}



int main() {
    vector<int> arr = {5, 2, 8, 4, 7, 1, 9, 3, 10, 6};
    int n = arr.size();

    // 打印原始数组
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 调用快速排序函数
    mergesort(arr, 0, n-1);

    // 打印排序后的数组
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}