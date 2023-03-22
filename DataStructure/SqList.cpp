#include <iostream>
using namespace std;
#define maxsize 50
/* 线性表 */
typedef struct SqList{
    int *data; // 动态分配不是链式存储 ，依然是随机存储方式，只是分配的空间大小可以在运行时动态决定
    int length;
}SqList;  // 起到的作用 typedef (struct SqList) SqList

// 从顺序表删除最小值的元素，并且由函数返回被删除元素的值，空出的位置由最后一个元素填补
bool Del_Min(SqList &L, int &value) {
    if(L.length == 0) return false;
    int min = 0;
    for(int i = 1; i < L.length; ++i) {
        if(L.data[min] > L.data[i]) {
            min = i;
        }
    }
    value = L.data[min];
    L.data[min] = L.data[L.length-1];
    L.length--;
    return true;
}

// 设计一个高效算法 将L中的所有元素逆置 空间复杂度为O(1)
void reverse(SqList &L) {
    for(int i = 0; i < L.length / 2; ++i) {
        swap(L.data[i], L.data[L.length-i-1]);
    }
}

// 数组的不分逆置问题
// ab ==> a-1b-1 ==> ba
// 0~p-1 (0 + p-1) / 2
// p~l-1 (p + l-1) / 2
// 将前p个和后面l-p个调换顺序
void Reverse(SqList &L, int from, int to) {
    for(int i = 0; i < (to-from+1) / 2; ++i) {
        swap(L.data[from+i], L.data[to-i]);
    }
}

void reverse_partial(SqList &L, int p) {
    Reverse(L, 0, p-1);
    Reverse(L, p, L.length-1);
    Reverse(L, 0, L.length-1);
}

void printList(SqList& L) {
    for(int i = 0; i < L.length; ++i) {
        cout << L.data[i] << " ";
    }
    cout << endl;
}

int main() {
    SqList sq;
    // 如果多维数组是通过malloc函数开辟的
    sq.data = (int *) malloc(sizeof(int) * 10);
    cout << sizeof(sq.data) << endl; // 指针的大小是8字节
    cout << sizeof(int) << endl; // int的大小4字节
    sq.length = 10;
    memset(sq.data, 0, sizeof(sq.length * sizeof(int))); // 如果初始化数组应该用sizeof(数组的长度 * 元素的大小)
    sq.data = new int[9]{1,2,3,4,5,6,7,8,9}; // 将分配空间和初始化合成一步
    sq.length = 9;
    reverse(sq);
    printList(sq);
    reverse_partial(sq, 3);
    printList(sq);
}