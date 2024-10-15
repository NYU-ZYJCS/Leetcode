class Solution {
public:
    int calculate(string s) {
        int n = s.size(), num = 0;
        char flag = '+';
        vector<int> stk;
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            
            if (c == ' ') continue;
            
            if (!isdigit(c)) flag = c;
            else {
                while (i < n && isdigit(s[i])) num = num * 10 + (s[i++] - '0');

                switch(flag) {
                    case '-': stk.push_back(-num); break;
                    case '+': stk.push_back(num); break;
                    case '*': stk.back() *= num; break;
                    case '/': stk.back() /= num; break;
                }
                num = 0, --i;
            }
        }
        
        return accumulate(stk.begin(), stk.end(), 0);
    }
};