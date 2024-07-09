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
    ListNode* deleteDuplicatesUnsorted(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1, head);
        unordered_map<int, int> freq;
        
        ListNode* temp = head;
        ListNode* cur = dummyNode->next;
        ListNode* pre = dummyNode;
        
        while (temp) {
            freq[temp->val]++;
            temp = temp->next;
        }
        
        while (cur) {
            if (freq[cur->val] >= 2) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        
        return dummyNode->next;
    }
};