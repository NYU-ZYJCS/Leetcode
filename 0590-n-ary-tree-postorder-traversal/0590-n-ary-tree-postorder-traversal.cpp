/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* root) {
        helper(root);
        
        return ans;
    }
    
    void helper(Node* root) {
        if (root == nullptr) return;
        
        for (auto child : root->children) {
            helper(child);
        }
        ans.push_back(root->val);
    }
    
private:
    vector<int> ans;
};