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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int length = 0;
        ListNode *cur = head;
        while (cur != nullptr) {
            ++length;
            cur = cur->next;
        }
        
        int part_length = length / k;
        int part_remain = length % k;
        
        vector<ListNode*> result(k, nullptr);
        cur = head;
        int index = 0;
        
        while (cur != nullptr) {
            result[index++] = cur;
            int cur_length = part_length;
            if (part_remain-- > 0) cur_length++;
            
            for (int i = 0; i < cur_length - 1 && cur != nullptr; ++i) {
                cur = cur->next;
            }
            
            // disconnect
            ListNode* next = cur->next;
            cur->next = nullptr;
            cur = next;
        }
        
        return result;
    }
};