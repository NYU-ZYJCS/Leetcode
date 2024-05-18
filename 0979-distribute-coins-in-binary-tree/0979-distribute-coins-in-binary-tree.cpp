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
    int distributeCoins(TreeNode* root) {
        dfs(root);
        return res;
    }
    
    int dfs(TreeNode* node) {
        if (node == nullptr) return 0;
        
        int d_left = dfs(node->left);
        int d_right = dfs(node->right);
        
        int d = d_left + d_right + node->val - 1;
        
        res += abs(d);
        
        return d;
    }
    
private:
    int res = 0;
};