class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> stk;
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            
            if (c == '(') {
                stk.push(i);
            } else if (c == ')') {
                if (!stk.empty() && s[stk.top()] == '(') stk.pop();
                else stk.push(i);
            }
        }
        
        while (!stk.empty()) {
            s.erase(stk.top(), 1);
            stk.pop();
        }
        
        return s;
    }
};