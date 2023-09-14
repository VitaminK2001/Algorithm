#include <iostream>
using namespace std;

char digit_to_hex_char(int digit) { 
    return "0123456789ABCDEF"[digit];
}

int main() {
    char *p = "abc"; // 在c语言中将字符串字面量当做char *指针
    cout << *p << endl; // a
    // c语言允许对指针取下标
    cout << "abcd"[2] << endl; // c

    cout << digit_to_hex_char(12) << endl; // C

    char str[] = "efjsk";
    scanf("%s", str); // 允许写自定义的空间，但是字符串字面量的空间不能随意改写
    // scanf读入的内容中不可能有空格，而且%s总会在末尾加上空字符
    printf("%s", str); // printf允许打印字符串，结束标志是空字符，如果没有则打印到内存中有空字符为止
    
}