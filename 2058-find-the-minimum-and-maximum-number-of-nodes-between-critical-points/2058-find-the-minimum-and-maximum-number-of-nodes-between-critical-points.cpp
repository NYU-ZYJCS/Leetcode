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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int min_distance = INT_MAX;
        int max_distance = INT_MIN;
        
        ListNode* cur = head->next;
        int pre_val = head->val;
        
        int pos = 1;
        int first_pos = -1;
        int pre_pos = -1;
        
        while (cur && cur->next) {
            ++pos;
            if ((cur->val > pre_val && cur->val > cur->next->val)
               || (cur->val < pre_val && cur->val < cur->next->val)) {
                if (first_pos == -1) first_pos = pos;
                else {
                    min_distance = min(min_distance, pos - pre_pos);
                }
                pre_pos = pos;
            }
            pre_val = cur->val;
            cur = cur->next;
        }
        
        if (min_distance == INT_MAX) return {-1, -1};
        max_distance = pre_pos - first_pos;
        return {min_distance, max_distance};
    }
};