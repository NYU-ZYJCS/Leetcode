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
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
    
    vector<TreeNode*> helper(int start, int end) {
        if (start > end) return {nullptr};
        vector<TreeNode*> roots;
        
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftRoots = helper(start, i - 1);
            vector<TreeNode*> rightRoots = helper(i + 1, end);
            
            for (auto& leftRoot : leftRoots) {
                for (auto& rightRoot : rightRoots) {
                    TreeNode* root = new TreeNode(i);
                    root->left = leftRoot;
                    root->right = rightRoot;
                    roots.push_back(root);
                }
            }
        }
        
        return roots;
    }
};