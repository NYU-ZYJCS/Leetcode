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
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for (auto num : to_delete) s.insert(num);
        if (helper(root)) res.push_back(root);
        
        return res;
    }
    
private:
    vector<TreeNode*> res;
    unordered_set<int> s;

    TreeNode* helper(TreeNode* node) {
        if (node == nullptr) return nullptr;
        
        node->left = helper(node->left);
        node->right = helper(node->right);
        
        if (s.count(node->val) == 0) return node;
        if (node->left) res.push_back(node->left);
        if (node->right) res.push_back(node->right);
        
        return nullptr;
    }
};