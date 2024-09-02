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
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* dummyNode = new ListNode(-1, head);
        ListNode* cur = head;
        
        while (cur && cur->next) {
            int divisor = gcd(cur->val, cur->next->val);
            ListNode* next = cur->next;
            cur->next = new ListNode(divisor, next);
            cur = next;
        }
        
        return dummyNode->next;
    }
    
    int gcd(int a, int b) {
        if (a == 0) return b;
        return gcd(b % a, a);
    }
};