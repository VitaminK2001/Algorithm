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
    // scanf在读入前会跳过空白字符
    scanf("%s", str); // 允许写自定义的空间，但是字符串字面量的空间不能随意改写
    // scanf读入的内容中不可能有空格，而且%s总会在末尾加上空字符
    printf("%s", str); // printf允许打印字符串，结束标志是空字符，如果没有则打印到内存中有空字符为止
    
    // gets在读入前不会跳过空白字符
    // 但是gets函数会持续读入知道遇到换行符，用空字符代替换行符存入数组，scanf是遇到空白字符就不读了
    // 在把字符读入数组时，scanf函数和gets函数都无法检测数组何时被填满。因此，它们存储字符时可能越过数组的边界，这会导致未定义的行为。
    // 通过用转换说明s代替%s可以使scanf函数更安全。可惜的是，gets函数天生就是不安全的，fgets函数则是一种好得多的选择
    char sentence[100+1];
    printf("Enter a sentence: \n");
    scanf("%s", sentence);
}