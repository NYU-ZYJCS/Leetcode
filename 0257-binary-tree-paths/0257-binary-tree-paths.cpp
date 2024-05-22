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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;

        function<void(TreeNode*, string)> helper = [&] (TreeNode* curNode, string path) {
            if (curNode == nullptr) return;
            if (curNode->left == curNode->right) {
                result.push_back(path + to_string(curNode->val));
                return;
            }
            
            string temp = path + to_string(curNode->val) + "->";
            helper(curNode->left, temp);
            helper(curNode->right, temp);
        };
        
        string path;
        helper(root, path);
        
        return result;
    }
};