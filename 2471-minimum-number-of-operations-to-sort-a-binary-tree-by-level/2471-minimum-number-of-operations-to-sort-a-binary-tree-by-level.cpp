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
private:
    vector<vector<int>> vec;
    
public:
    void dfs(TreeNode *node, int d) {
        if (node == nullptr) return;
        while (vec.size() <= d) vec.push_back(vector<int>());
        
        vec[d].push_back(node->val);
        dfs(node->left, d + 1);
        dfs(node->right, d + 1);
    }
    
    
    int helper(vector<int>& A) {
        vector<int> B = A;
        ranges::sort(B);
        unordered_map<int, int> mp;
        for (int i = 0; i < B.size(); ++i) mp[B[i]] = i;
        
        int count = 0;
        for (int i = 0; i < A.size(); ++i) {
            while (A[i] != B[i]) {
                swap(A[i], A[mp[A[i]]]);
                ++count;
            }
        }
        
        return count;
    }
    
    int minimumOperations(TreeNode* root) {
        dfs(root, 0);
        int res = 0;
        for (auto &A : vec) res += helper(A);
        
        return res;
    }
};