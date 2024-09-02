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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> exists(nums.begin(), nums.end());
        
        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* cur = dummyNode;
        while (cur && cur->next) {
            if (exists.contains(cur->next->val)) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        
        return dummyNode->next;
    }
};