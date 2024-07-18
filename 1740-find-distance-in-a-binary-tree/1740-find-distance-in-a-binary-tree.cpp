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
    int findDistance(TreeNode* root, int p, int q) {
        TreeNode* parent = getLowestAncestor(root, p, q);
        
        return getDistance(parent, p) + getDistance(parent, q);
    }
    
    TreeNode* getLowestAncestor(TreeNode* root, int p, int q) {
        if (root == nullptr) return nullptr;
        if (root->val == p || root->val == q) return root;
        
        TreeNode* left = getLowestAncestor(root->left, p, q);
        TreeNode* right = getLowestAncestor(root->right, p, q);
        
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }
    
    int getDistance(TreeNode* root, int target) {
        if (root == nullptr) return -1;
        
        if (root->val == target) return 0;
        
        int leftDistance = getDistance(root->left, target);
        if (leftDistance != -1) return leftDistance + 1;
        
        int rightDistance = getDistance(root->right, target);
        if (rightDistance != -1) return rightDistance + 1;
        
        return -1;
    }
};