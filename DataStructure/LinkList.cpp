#include <iostream>
using namespace std;

/* 线性表的链式表示 */
typedef struct Lnode{
    int data;
    struct Lnode *next;

    // 这是头插法
    Lnode* add_head(Lnode* &L, int elem) {
        Lnode *s;
        s = (Lnode*) malloc(sizeof(Lnode*));
        s->data = elem;
        s->next = L->next;
        L->next = s;
        return L;
    }

    // 尾插法
    Lnode* add_back(Lnode* &L, int elem) {
        Lnode *s, *r = L;
        s = (Lnode*) malloc(sizeof(Lnode*));
        while(r->next != nullptr) {
            r = r->next;
        }
        s->data = elem;
        r->next = s;
        r = s;
        r->next = nullptr;
        return L;
    }
    

    void print(Lnode* &L) {
        Lnode *s = L->next;
        while(s != nullptr) {
            cout << s->data << " ";
            s = s->next;    
        }
        cout << endl;
    }
}*LinkList;


/*
struct A{
    int data;
};
*/

// 设计一个递归删除不带头结点的单链表中的值为x的结点的操作
void Del_X_3(LinkList &L, int x) {
    LinkList p;
    if(L == nullptr) return ;
    if(L->data == x) {
        p = L;
        L = L->next;
        free(p);
        Del_X_3(L, x);
    }else {
        Del_X_3(L->next, x);
    }
}

// 在带头节点的链表中删除一个所有值为x的结点并释放空间
void dele(LinkList &L, int x) {
    LinkList p = L->next, pre = L;
    if(p == nullptr) return ;
    while(p != nullptr) {
        if(p->data == x) {
            LinkList q = p;
            pre->next = p->next;
            free(q);
        }
        pre = p;
        p = p->next;
    }
}

// L为带头节点的单链表 设计算法实现从尾到头反向输出每个节点的值
void backwardPrint(LinkList &L) {
    if(L->next != nullptr) {
        backwardPrint(L->next);
    }
    if(L != NULL) {
        cout << L->data << " ";
    }
}

void backwardPrintIgnoreHead(LinkList &L) {
    if(L->next != nullptr) backwardPrint(L->next);
    cout << endl;
}

// 将带头节点的链表就地逆置
void reverse(LinkList L) {
    LinkList p = L->next, pre = L;
    while(p != nullptr) {
        LinkList q = p;
        pre->next = q->next;
        L->add_head(L, p->data);
        free(q);
        pre = p;
        p = p->next;
    }
}

// 一个带头结点的链表，设计一个算法使其递增有序
void sortLinkList(LinkList &L) {
    LinkList pre, p = L->next;
    LinkList r = p->next;
    p->next = nullptr;
    p = r; // r现在赋值给p之后 p又回到L的链上
    while(p != nullptr) {
        r = p->next; // 将r移动到L中p的下一个位置
        pre = L;
        while(pre->next != nullptr && pre->next->data < p->data) {
            pre = pre->next;
        }
        p->next = pre->next;
        pre->next = p;
        p = r; // r现在赋值给p之后 p又回到L的链上
    }
}

// 给定一个带头结点的单链表 按递增次序输出单链表中各结点的数据元素，并释放结点所占的存储空间
void Min_Delete(LinkList& L) {
    while(L->next != nullptr) {
        LinkList p = L, pre = p;
        int min = INT_MAX;
        while(p->next != nullptr) {
            if(p->next->data < min) {
                min = p->next->data;
                pre = p;
            }
            p = p->next;
        }
        cout << pre->next->data << " ";
        LinkList after = pre->next;
        pre->next = after->next;
        free(after);
    }
    free(L);
    cout << endl;
}

// 已知一个带头结点的单链表 在不改变链表的前提下 设计一个查找链表中倒数第k个位置上的结点 k为正整数
// 若查找成功 则输出该节点data 并返回1 否则返回0
int search_last_k(LinkList &L, int k) {
    Lnode *p = L->next, *q = L->next;
    int count = 0;
    while(p != nullptr) {
        if(count < k) {
            count++;
        }else {q = q->next;}
        p = p->next;
    }
    if(count < k) return 0;
    else {
        cout << q->data << endl;
        return 1;
    }
}

int main() {
    // A a; // 注意这种写法在c中不成立 c中一定要struct A
    // LinkList l = calloc(1, sizeof(LinkList));
    LinkList l = (struct Lnode*)calloc(1, sizeof(struct Lnode));
    LinkList l2 = (LinkList)calloc(1, sizeof(LinkList)); // 这样也是可以的
    l->data = 4; // 在给指针指向的内存赋值之前，先要开辟内存 不然bus error
    l->add_head(l, 1);
    l->add_head(l, 2);
    l->add_head(l, 3);
    l->add_head(l, 4);
    l->add_head(l, 5);
    l->add_head(l, 6);
    l->add_head(l, 7);
    l->print(l);


    l2->add_back(l2, 1);
    l2->add_back(l2, 2);
    l2->add_back(l2, 3);
    l2->add_back(l2, 4);
    l2->print(l2);

    
    // dele(l, 3);
    // l->print(l);

    // backwardPrintIgnoreHead(l);
    
    reverse(l);
    l->print(l);

    LinkList l3 = (LinkList)calloc(1, sizeof(LinkList));
    l3->add_back(l3, 3);
    l3->add_back(l3, 2);
    l3->add_back(l3, 6);
    l3->add_back(l3, 10);
    l3->add_back(l3, 7);
    sortLinkList(l3);
    l3->print(l3);
    Min_Delete(l3);

    search_last_k(l2, 2);

}
