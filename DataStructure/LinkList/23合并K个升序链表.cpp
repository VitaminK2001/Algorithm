#include <iostream>
#include <vector>
#include "ListNode.cpp"
using namespace std;

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if((!l1) || (!l2)) return l1 ? l1 : l2;
        ListNode head, *tail = &head, *aPtr = l1, *bPtr = l2;
        while(aPtr && bPtr) {
            if(aPtr->val < bPtr->val) {
                tail->next = aPtr;
                aPtr = aPtr->next;
            }else {
                tail->next = bPtr;
                bPtr = bPtr->next;
            }
            tail = tail->next;
        }
        tail->next = (aPtr ? aPtr : bPtr);
        return head.next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *ans = nullptr;
        for(size_t i = 0; i < lists.size(); ++i) {
            ans = mergeTwoLists(ans, lists[i]);
        }
        return ans;
    }
};

// 对上面的方法进行改进，减少合并的次数
class Solution2 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if((!l1) || (!l2)) return l1 ? l1 : l2;
        ListNode head, *tail = &head, *a = l1, *b = l2;
        while(a && b) {
            tail->next = (a->val < b->val) ? a : b;
            if(tail->next == a) {
                a = a->next;
            }else {
                b = b->next;
            }
            tail = tail->next;
        }
        tail->next = a ? a : b;
        return head.next;
    }
    ListNode *merge(vector<ListNode*> &lists, int l, int r) {
        if(l == r) return lists[l];
        if(l > r) return nullptr;
        int mid = (l + r) >> 1;
        return mergeTwoLists(merge(lists, l, mid), merge(lists, mid+1, r));
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        merge(lists, 0, lists.size()-1);
    }
};
