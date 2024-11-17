class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int res = 0, sign = 1;
        
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == ' ') continue;
            
            if (isdigit(s[i])) {
                int num = 0;
                while (i < s.size() && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    ++i;
                }
                --i;
                res += sign * num;
            } else {
                if (s[i] == '(') {
                    stk.push(res);
                    stk.push(sign);
                    sign = 1;
                    res = 0;
                } else if (s[i] == ')') {
                    res *= stk.top(); stk.pop();
                    res += stk.top(); stk.pop();
                } else if (s[i] == '+') {
                    sign = 1;
                } else if (s[i] == '-') {
                    sign = -1;
                }
            }
        }
        
        return res;
    }
};