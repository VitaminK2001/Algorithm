#include <iostream>
#include <vector>
using namespace std;

int binarySearch(vector<int>& arr, int left, int right, int target) {
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

int main() {
    vector<int> arr = {1, 3, 4, 6, 8, 9, 11};
    int target = 6;

    int index = binarySearch(arr, 0, arr.size() - 1, target);

    if (index != -1) {
        cout << "Target found at index " << index << endl;
    } else {
        cout << "Target not found in the array" << endl;
    }

    return 0;
}