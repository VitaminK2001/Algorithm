#include <iostream>
using namespace std;

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
    l->print(l);


    l2->add_back(l2, 1);
    l2->add_back(l2, 2);
    l2->add_back(l2, 3);
    l2->add_back(l2, 4);
    l2->print(l2);
}
