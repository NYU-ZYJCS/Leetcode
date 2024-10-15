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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        helper(root, 0);
        return res;
    }
    
    int helper(TreeNode* root, int depth) {
        if (root == nullptr) {
            max_depth = max(max_depth, depth);
            return depth;
        }
        
        int left_depth = helper(root->left, depth + 1);
        int right_depth = helper(root->right, depth + 1);
        
        if (left_depth == right_depth && left_depth == max_depth) res = root;
        
        return max(left_depth, right_depth);
    }
    
private:
    int max_depth = -1;
    TreeNode* res = nullptr;
};