/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0) return nullptr;
        return merge(lists, 0, lists.size() - 1);
    }
    
    ListNode* merge(vector<ListNode*>& lists, int start, int end) {
        if (start == end) return lists[start];
        int mid = start + (end - start) / 2;
        
        ListNode *left = merge(lists, start, mid);
        ListNode *right = merge(lists, mid + 1, end);
        return merge(left, right);
    }
    
    // merge two sorted list
    ListNode* merge(ListNode *l1, ListNode *l2) {
        ListNode *dummyNode = new ListNode(-1);
        ListNode *cur = dummyNode;

        while (l1 && l2) {
            if (l1->val <= l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        cur->next = (l1) ? l1 : l2;
        return dummyNode->next;
    }
};