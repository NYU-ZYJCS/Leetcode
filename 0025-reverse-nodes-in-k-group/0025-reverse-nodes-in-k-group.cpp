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
    ListNode* reverseKGroup(ListNode* head, int k) {
        // 1->2 -> 3 -> 4 -> 5
        // 1->2 -> 5 -> 4 -> 3
        
        ListNode* temp = head;
        for (int i = 0; i < k; ++i) {
            if (!temp) return head;
            temp = temp->next;
        }
        
        ListNode* nextStart = reverseKGroup(temp, k);
        ListNode *pre = nextStart;
        ListNode *cur = head;
        for (int i = 0; i < k; ++i) {
            ListNode *next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }

        return pre;
    }
};