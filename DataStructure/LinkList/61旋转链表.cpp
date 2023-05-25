#include <iostream>
#include <vector>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // 旋转k次之后 倒数第k个结点变成链表的头 倒数第k+1个节点变成链表的尾
        // 这是在0 <= k <= n的情况下 如果k = n则链表保持原样 和 k = 0 效果一样
        // 所以将链表连成环状
        // 因为k在整除n的时候 链表保持原样，在 k % n 属于 [1, n-1]的时候
        // 符合 倒数第k个结点变成链表的头 倒数第k+1个节点变成链表的尾 
        if(k == 0 || head == nullptr || head->next == nullptr) {
            // 需要考虑 k = 0 和链表无法连成环的情况
            return head;
        }
        ListNode *iter = head;
        int n = 0;
        while(iter->next != nullptr) {
            iter = iter->next;
            n++;
        }
        iter->next = head;
        int add = n - k % n;
        if(add == n) return head;
        while(add--) {
            iter = iter->next;
        }
        ListNode *ret = iter->next;
        iter->next = nullptr;
        return ret;
        
    }
};