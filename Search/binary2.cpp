#include <stdio.h>
#include <iostream>
using namespace std;

int m1(int l, int r, int a[], int target) {
    // 查找第一个小于的数
    while(l <= r) {
        int m = (l + r) / 2;
        // 不要已经知道小于的 因为可能不是第一个
        if(a[m] < target) { 
            l = m+1;
        }else {
            // 不要大于等于的 因为要找小于的
            r = m-1;
        }
    }
    // 因为l在赌，所以应该是返回r 返回时的r是肯定不大于等于的 而l的作用就是超过r之后 判断出r是第一个小于的
    return r;
}

int m2(int l, int r, int a[], int target) {
    // 查找第一个小于等于的数
    while(l <= r) {
        int m = (l + r) / 2;
        // 不要已经知道小于等于的 因为可能不是第一个
        if(a[m] <= target) { 
            l = m+1;
        }else {
            // 不要大于的 因为要找小于的
            r = m-1;
        }
    }
    // 因为l在赌，所以应该是返回r 返回时的r是肯定不大于的 而l的作用就是超过r之后 判断出r是第一个小于等于的
    return r;
}

int m3(int l, int r, int a[], int target) {
    // 查找第一个大于的数
    while(l <= r) {
        int m = (l + r) / 2;
        // 不要已经知道大于的
        if(a[m] > target) {
            r = m-1;
        }else {
            // 不要小于等于的
            l = m+1;
        }
    }
    // 此时是r在赌 所以返回l 返回时的l肯定是不小于等于的 r的作用就是被l超过之后 判断出l是第一个大于的
    return l;
}

int m4(int l, int r, int a[], int target) {
    // 查找第一个大于等于的数
    while(l <= r) {
        int m = (l + r) / 2;
        // 不要已经知道大于等于的
        if(a[m] >= target) {
            r = m-1;
        }else {
            // 不要小于的
            l = m+1;
        }
    }
    // 此时是r在赌 所以返回l 返回时的l肯定是不小于的 r的作用就是被l超过之后 判断出l是第一个大于的
    return l;
}



int main() {
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    cout << m2(0, 9, a, 7) << endl;
    cout << m4(0, 9, a, 9) << endl;
}