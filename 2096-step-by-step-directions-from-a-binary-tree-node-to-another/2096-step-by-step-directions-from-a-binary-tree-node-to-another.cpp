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
    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* lowestCommonAncestor = getLowestAncestor(root, startValue, destValue);
        
        string pathToStart;
        string pathToDest;

        // Find paths from LCA to start and destination nodes
        findPath(lowestCommonAncestor, startValue, pathToStart);
        findPath(lowestCommonAncestor, destValue, pathToDest);

        string directions;
        // Add "U" for each step to go up from start to LCA
        directions.append(pathToStart.length(), 'U');

        // Append the path from LCA to destination
        directions.append(pathToDest);

        return directions;
    }
    
    TreeNode* getLowestAncestor(TreeNode* root, int startValue, int destValue) {
        if (!root) return nullptr;
        if (root->val == startValue || root->val == destValue) return root;
        
        TreeNode* left = getLowestAncestor(root->left, startValue, destValue);
        TreeNode* right = getLowestAncestor(root->right, startValue, destValue);
        
        if (left == nullptr) return right;
        if (right == nullptr) return left;
        return root;
    }
    
    bool findPath(TreeNode* root, int targetValue, string& path) {
        if (!root) return false;
        
        if (root->val == targetValue) return true;
        
        path.push_back('L');
        if (findPath(root->left, targetValue, path)) {
            return true;
        };
        path.pop_back();
        
        path.push_back('R');
        if (findPath(root->right, targetValue, path)) {
            return true;
        }; 
        path.pop_back();
        
        return false;
    }
};