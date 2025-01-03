/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if (!root) return res; 
        
        queue<TreeNode*> q;
        q.push(root);
        
        while (!q.empty()) {
            int max_val = INT_MIN;
            int n = q.size();
            
            while (n--) {
                TreeNode* cur = q.front();
                q.pop();
                
                max_val = max(max_val, cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            
            res.push_back(max_val);
        }
        
        return res;
    }
};