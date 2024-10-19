class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        
        for (auto c : s) {
            if (c == '(') stk.push(c);
            else if (c == ')') {
                if (!stk.empty() && stk.top() == '(') stk.pop();
                else stk.push(')');
            }
        }
        
        return stk.size();
    }
};