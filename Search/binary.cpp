#include <iostream>
#include <vector>
using namespace std;

// 寻找数
int binarySearch(vector<int>& arr, int n, int target) {
    int left = 0, right = n-1;
    int middle = left + (right - left) / 2;
    while(left <= right) {
        if(arr[middle] == target) {
            return middle;
        }else if(arr[left] < target) {
            left++;
        }else {
            right--;
        }
    }
    return -1;
}

// 寻找下界
int binarySearchLower(vector<int>& arr, int target) {
    int n = arr.size();
    int left = 0, right = arr.size()-1;
    while(left <= right) { // 结束条件 left = right+1
        int mid = left+(right-left)/2;
        if(arr[mid] < target) {
            left = mid+1;
        }else if(arr[mid] >= target) { // mid及以后的区间都是不需要的
            right = mid-1;
        }
    }
    if(left >= n || arr[left] != target) return -1;
    return left;
}

// 寻找上界
int binarySearchUpper(vector<int>& arr, int target) {
    int n = arr.size();
    int left = 0, right = arr.size()-1;
    while(left <= right) { // 结束条件 left = right+1
        int mid = left+(right-left)/2;
        if(arr[mid] <= target) { // mid及之前的区间都是不需要的
            left = mid+1;
        }else if(arr[mid] > target) {
            right = mid-1;
        }
    }
    if(right < 0 || arr[right] != target) return -1;
    return right;
}

int main() {
    vector<int> arr = {1, 3, 4, 6, 6, 6, 6, 8, 9, 11, 11, 12};
    int target = 6;

    int lower = binarySearchLower(arr, target);

    int upper = binarySearchUpper(arr, target);

    cout << "lower bound index is : " << lower << endl;

    cout << "upper bound index is : " << upper << endl;

    return 0;
}