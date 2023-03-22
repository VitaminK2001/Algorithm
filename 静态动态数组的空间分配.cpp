#include <iostream>
using namespace std;
void printList(int a[], int n) {
    for(int i = 0; i < n; ++i) {
        cout << a[i] << " ";
    }
    cout << endl;
}
int main() {
    /*              静态数组               */
    int a1[3]; // 1 58395696 1 
    cout << "a1 : " << endl;
    printList(a1, 3);

    int a2[3] = {}; // 初始化为0
    cout << "a2 : " << endl;
    printList(a2, 3); // 0 0 0


    // Sets the first num bytes of the block of memory pointed by ptr 
    // to the specified value (interpreted as an unsigned char).
    memset(a1, 0, sizeof(a1)); 
    cout << "a1 : " << endl;
    printList(a1, 3); // 0 0 0




    /*                 动态数组                */ 
    int num = 10;
    int arr0[num]; // 可以这样声明
    cout << "arr0 : " << endl;
    printList(arr0, num); // -1207623408 32759 132841545 1 3 3 -1207623224 32759 -1207623392 32759 
    // int arr0[num] = {}; // 不能这样初始化以变量为长度的数组
    

    /*                 malloc 动态申请一维数组                 */ 
    // malloc函数申请长度为size的空间，如果申请成功返回分配空间的首地址，失败返回NULL
    int *arr1 = (int*) malloc(sizeof(int) * num); // malloc
    cout << "arr1 : " << endl;
    printList(arr1, num); // 0 0 0 0 0 0 0 0 0 0 


    // malloc申请到的空间不一定会初始化，可以调用calloc其申请到的空间会初始化
    // calloc申请 num块大小为size的空间 申请成功返回分配区域的首地址 不成功返回NULL
    arr1 = (int*)calloc(num, sizeof(int));
    printList(arr1, num);


    // 用一次malloc或者new 申请多个地址（数组）, 得到的是连续地址 
    cout << &arr1[1] << endl;
    cout << &arr1[2] << endl;

    
    // 但是如果多次使用malloc申请空间是不连续的
    int* p;
    int i;
    for (i = 0; i < 10; i++) { //10、100、1000测试
        p = (int*)malloc(sizeof(int));
        // p = new int;
        *p = i;
        printf("%d-----%p----%p\n", *p, p, p-1);
        // 多次malloc或者new申请地址，通过对每一次申请的内存空间地址和上一块地址 (p-1)作比较发现，地址并不是连续的。
        // 原因是 堆分配的空间在逻辑地址上是连续的，但在物理地址上是不连续的
    }


    /*                 new 动态申请一维数组                 */ 
    int *arr2 = new int[3];


    /*                 new 动态申请多维数组                 */ 
    // int **arr2 = new int[3][4]; 这样动态分配二维数组的空间是错误的
    // 下面的是正确的
    int **arr3 = new int*[3];
    for(int i = 0; i < 3; ++i) {
        arr3[i] = new int[4];
    }


    // 分配空间和初始化合在一起
    // new 在动态分配类类型时，会调用类的构造函数，对内存空间进行初始化；
    // 在动态分配内置类型时，是否初始化取决于后面有没有括号（）
    int *arr4 = new int[3]{1,2,3};
    cout << " arr4 : " << endl;
    printList(arr4, 3);
    int *arr5 = new int[4]{}; // 初始化 
    int *arr6 = new int[4](); // 显式初始化
    int *arr7 = new int[3]; // 不初始化
    cout << " arr7 : " << endl;
    printList(arr7, 3);

    // new申请到的空间是连续的
    cout << &arr4[0] << "  " << &arr4[1] << endl;
}