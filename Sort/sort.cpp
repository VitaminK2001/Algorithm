#include <iostream>
#include <vector>
using namespace std;

// 插入排序的交换版本
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

// 插入排序的非交换版本
void insertionsort2(vector<int>& arr, int n) {      
    int i, j;
    for(i = 1; i < n; ++i) {
        int target = arr[i];
        j = i;
        while(j > 0 && arr[j-1] > target) {
            arr[j] = arr[j-1];
            --j;
        }
        arr[j] = target;
    }
}

/*  不论pivot是从左边开始还是从右边开始 都要考虑一点 异端指针先行 */
 void quicksort_with_leftPivot(int arr[], int left, int right) {
    if(left >= right) return ;
    int pivot = left;
    int start = left;
    int end = right;
    while(left < right) {
        // 因为pivot选左端的数，最后要换只可能比原来更靠右，也就是说，和pivot换位置的数一定要小于等于pivot
        // 所以右端指针先行，right停下来的位置是小于pivot的数，或者和left重合（此时left没动就是pivot的位置）
        // 所以先移动right最后停下来的位置就是小于等于pivot的位置
        // 但是如果先移动left
        // 最后停下来的位置可能是大于pivot的位置
        while(left < right && arr[right] >= arr[pivot]) {
            right--;
        }
        while(left < right && arr[left] <= arr[pivot]) {
            left++;
        }
        swap(arr[left], arr[right]);
    }
    swap(arr[left], arr[pivot]);
    quicksort_with_leftPivot(arr, start, left-1);
    quicksort_with_leftPivot(arr, left+1, end);
 }

void quicksort_with_rightPivot(int arr[], int left, int right) {
    // 注意递归函数的终止条件是当只剩下一个元素的时候不拆分
    if(left >= right) return ;
    int pivot = right;
    int start = left;
    int end = right;
    while(left < right) {
        while(left < right && arr[left] <= arr[pivot]) { 
            left++;
        }
        while(left < right && arr[right] >= arr[pivot]) {
            right--;
        }
        swap(arr[left], arr[right]);
    }
    swap(arr[left], arr[pivot]);

    quicksort_with_rightPivot(arr, start, left-1);
    quicksort_with_rightPivot(arr, left+1, end);
}

// 冒泡排序 从后往前 每次将最大的挪到最后面
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

// 选择排序 从头开始 选择未排序的序列中最小的数插入到已排序的序列的末尾
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

// 归并排序 左中右
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

void heapify(vector<int>& arr, int heapsize, int i) { 
    if(i >= heapsize) return ;
    int left = i * 2 ;
    int right = i * 2 + 1;
    int largest = i;
    if(left < heapsize && arr[left] > arr[largest]) { // 把最大的结点放在前面 建立的是大根堆（比左右节点都大）
        largest = left;
    }
    if(right < heapsize && arr[right] > arr[largest]) {
        largest = right;
    }
    if(largest != i) { // 注意如果是左右没有子节点 或者 就是本身最大，则不需要换
        swap(arr[i], arr[largest]);
        heapify(arr, heapsize, largest); // 换了之后largest位置有变动，要接着往下换
    }
}

void buildheap(vector<int>& arr, int heapsize) {
    int n = heapsize / 2; // 最后一个非叶子节点（/2取整是下限）
    for(int i = n; i >= 0; --i) { // 从最后一个非叶子节点开始，往上直到根节点
        heapify(arr, heapsize, i);
    }
}

void heapsort(vector<int>& arr, int heapsize) {
    buildheap(arr, heapsize);
    for(int i = heapsize-1; i >= 1; --i) { // 每次都是最后一个元素和第一个元素交换（大根堆）
        swap(arr[i], arr[0]);
        heapify(arr, i, 0);
    }
}

/* 希尔排序法 */
/* 构造一个gap gap从大变小最后变成1*/
void shellsort(vector<int>& arr, int n) {
    for(int gap = n / 2; gap > 0; gap /= 2) { // gap终究变成1
        for(int i = gap; i < n; ++i) {
            int j = i;
            while(j - gap >= 0 && arr[j] < arr[j-gap]) {
                swap(arr[j], arr[j-gap]);
                j -= gap;
            }
        }
    }
}

void shellsort2(vector<int>& arr, int n) {
    for(int gap = n / 2; gap > 0; gap /= 2) {
        for(int i = gap; i < n; ++i) {
            int j = i - gap;
            int target = arr[i];
            while(j >= 0 && target < arr[j]) {
                arr[j+gap] = arr[j];
                j -= gap;
            }
            arr[j+gap] = target;
        }
    }
}



int main() {
    vector<int> nums = {5, 2, 8, 4, 7, 1, 9, 3, 10, 6, 22, 41, 27, 35, 60, 22, 33, 87};
    int n = nums.size();        
    int arr[nums.size()];
    std::copy(nums.begin(), nums.end(), arr);

    // 打印原始数组
    cout << "Original array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

      
    quicksort_with_rightPivot(arr, 0, n-1);

    // 打印排序后的数组
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}