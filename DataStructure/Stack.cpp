#include <iostream>
using namespace std;
#define Elemtype int
#define MaxSize 50

typedef struct {
    Elemtype data[MaxSize];
    int top;
}SqStack;

void InitStack(SqStack &S) {
    S.top = -1;
}

bool Push(SqStack &S, Elemtype x) {
    if(S.top == MaxSize-1) {
        return false;
    }else {
        S.data[++S.top] = x;
        return true;
    }
}

bool Pop(SqStack &S, Elemtype &x) {
    if(S.top == -1) return false;
    x = S.data[S.top--];
    return true;
}

bool GetTop(SqStack S, Elemtype &x) {
    if(S.top == -1) {
        return false;
    }
    x = S.data[S.top];
    return true;
}

// 入栈和出栈的操作都在栈的表头进行
typedef struct Linknode {
    Elemtype data;
    struct Linknode *next;
}*LinkStack;
