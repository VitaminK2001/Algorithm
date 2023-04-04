#include <iostream>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    pair<ListNode*, ListNode*> myReverse(ListNode *head, ListNode *tail) {
        ListNode *tail_next = tail->next;
        ListNode *p = head; // 将head取下链表
        while(tail_next != tail) {
            ListNode *nex = p->next; // 防止不断链
            // 将p取下链表
            p->next = tail_next;
            
            tail_next = p;
            p = nex;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *hair = new ListNode(0);
        hair->next = head;
        ListNode *pre = hair;
        // 如果还剩不到k个节点
        while(head) {
            ListNode *tail = pre;
            for(int i = 0; i < k; ++i) {
                tail = tail->next;
                if(tail == nullptr) return hair->next; // 结束
            }
            // 翻转head ~ test节点
            ListNode *nex = tail->next;
            pair<ListNode*, ListNode*> result = myReverse(head, tail);
            head = result.first;
            tail = result.second;
            pre->next = head;
            tail->next = nex;
            pre = tail;
            head = tail->next;
        }
        return hair->next; // 防止head本身为空
    }
};