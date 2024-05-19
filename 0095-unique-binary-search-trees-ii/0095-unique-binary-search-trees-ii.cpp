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
        if (cache.find({start, end}) != cache.end()) return cache[{start, end}];
        
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftRoots = helper(start, i - 1);
            vector<TreeNode*> rightRoots = helper(i + 1, end);
            
            for (auto& leftRoot : leftRoots) {
                for (auto& rightRoot : rightRoots) {
                    TreeNode* root = new TreeNode(i, leftRoot, rightRoot);
                    cache[{start, end}].push_back(root);
                }
            }
        }
        
        return cache[{start, end}];
    }

private:
    map<pair<int, int>, vector<TreeNode*>> cache;
};