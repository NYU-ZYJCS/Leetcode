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
    int countPairs(TreeNode* root, int distance) {
        helper(root, distance);
        return ans;

    }
    
    vector<int> helper(TreeNode* root, int distance) {
        if (root == nullptr) return {};
        if (root->left == root->right) return {0};
        
        vector<int> ret;
        auto left = helper(root->left, distance);
        for (auto& l : left) {
            if (++l > distance) continue;
            ret.push_back(l);
        }
        
        auto right = helper(root->right, distance);
        for (auto& r : right) {
            if (++r > distance) continue;
            ret.push_back(r);
        }
        
        for (auto l : left) {
            for (auto r : right) {
                ans += (l + r) <= distance;
            }
        }
        
        return ret;
    }
    
private:
    int ans = 0;
};