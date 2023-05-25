#include <iostream>
#include <vector>
#include "ListNode.cpp"
using namespace std;
// https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/submissions/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        // 没有必要多个节点
        ListNode *dummyhead = new ListNode(0, head);
        ListNode *cur = dummyhead;
        while(cur->next && cur->next->next) {
            // 如果cur的后面只有一个节点或者没有节点则比较完成
            if(cur->next->val == cur->next->next->val) {
                int x = cur->next->val;
                while(cur->next && cur->next->val == x) {
                    // 跳过相同的结点
                    cur->next = cur->next->next; 
                }
            }
            else {
                cur = cur->next;
            }
        }
        return dummyhead->next; 
        // 因为head可能已经不是正确的链上的结点了所以return dummyhead->next
        // “可能”：如果开头不是重复的元素，则head指向的就是正确的链
        // 如果开头就是重复的元素，则一开始cur指向的是dummyhead，改变的是dummyhead->next，
        // 于是dummyhead->next的指向就不再是head，单独成为新的链，也就是head这条链上的部分没有被改动，返回head就是返回原来的链

    }
};