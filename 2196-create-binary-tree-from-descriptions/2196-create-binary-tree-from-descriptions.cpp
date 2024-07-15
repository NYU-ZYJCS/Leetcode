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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode*> nodes;
        unordered_set<int> children;
        
        for (auto description : descriptions) {
            int parentVal = description[0];
            int childVal = description[1];
            int isLeft = description[2];

            if (!nodes.count(parentVal)) {
                nodes[parentVal] = new TreeNode(parentVal);
            }
            if (!nodes.count(childVal)) {
                nodes[childVal] = new TreeNode(childVal);
            }

            TreeNode* parent = nodes[parentVal];
            TreeNode* child = nodes[childVal];

            if (isLeft == 1) parent->left = child;
            else parent->right = child;

            children.insert(childVal);
        }
        
        for (auto [key, node] : nodes) {
            if (children.find(key) == children.end()) return node;
        }
        
        return nullptr;
    }
};