class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        stack<int> stk;
        stk.push(-1);
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (c == '(') stk.push(i);
            else {
                stk.pop();
                if (!stk.empty()) res = max(res, i - stk.top());
                else stk.push(i);
            }
        }
        
        return res;
    }
};