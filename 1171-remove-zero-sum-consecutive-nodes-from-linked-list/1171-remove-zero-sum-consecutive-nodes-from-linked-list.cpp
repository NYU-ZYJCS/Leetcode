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
    ListNode* removeZeroSumSublists(ListNode* head) {
        // 1 3 6 3
        unordered_map<int, ListNode*> prefix;
        
        ListNode* dummyNode = new ListNode(0, head);
        ListNode* cur = head;
        prefix[0] = dummyNode;
        int sum = 0;
        
        while (cur) {
            sum += cur->val;
            if (prefix.contains(sum)) {
                ListNode* start = prefix[sum]->next;
                int temp_sum = sum;
                while (start != cur) {
                    temp_sum += start->val;
                    prefix.erase(temp_sum);
                    start = start->next;
                }
                prefix[sum]->next = cur->next;
            } else {
                prefix[sum] = cur;
            }
            cur = cur->next;
        }
        
        return dummyNode->next;
    }
};