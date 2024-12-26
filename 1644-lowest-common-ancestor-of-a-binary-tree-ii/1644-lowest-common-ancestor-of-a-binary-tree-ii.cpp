/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* node = helper(root, p, q);
        if (p_exist && q_exist) return node;
        return nullptr;
    }
    
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == nullptr) return root;
        
//         if (root == p) {
//             p_exist = true;
//             return root;
//         }
        
//         if (root == q) {
//             q_exist = true;
//             return root;
//         }
        
        TreeNode* left = helper(root->left, p, q);
        TreeNode* right = helper(root->right, p, q);
        
        if (root == p) {
            p_exist = true;
            return root;
        }
        
        if (root == q) {
            q_exist = true;
            return root;
        }
        
        if (left && right) return root;
        return left ? left : right;
    }
    
private:
    bool p_exist = false;
    bool q_exist = false;
};