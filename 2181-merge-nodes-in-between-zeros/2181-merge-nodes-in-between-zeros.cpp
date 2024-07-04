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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;

        
        while (head) {
            int sum = 0;
            
            if (head->val == 0) {
                head = head->next;
                continue;
            }
            
            while (head && head->val != 0) {
                sum += head->val;
                head = head->next;
            }
            
            cur->next = new ListNode(sum);
            cur = cur->next;
        }
        
        return dummy->next;
    }
};