#include <iostream>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    /* 什么时候需要返回值 */
    ListNode* dfs(ListNode *p) {
        if(p == nullptr) return nullptr; // 当前节点为空 没有交换结果
        ListNode *q = p->next;
        if(q == nullptr) return p; // 当前节点为最后一个节点 交换结果为其本身
        p->next = dfs(q->next);
        q->next = p;
        return q;
    }
    ListNode* swapPairs(ListNode* head) {
        dfs(head);
    }
};