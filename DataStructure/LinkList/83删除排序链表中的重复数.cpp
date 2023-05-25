#include <iostream>
#include <vector>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = head;
        if(head == nullptr) return nullptr;
        ListNode* cur = head->next;
        while(cur != nullptr) {
            if(cur->val == pre->val) {
                pre->next = cur->next;
                cur = cur->next;
            }else {
                pre = pre->next;
                cur = cur->next;
            } 
        }
        return head;
    }
};