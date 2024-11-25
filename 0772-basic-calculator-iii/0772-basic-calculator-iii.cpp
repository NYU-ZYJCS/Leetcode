class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return helper(s, i);
    }
    
    int helper(string s, int& i) {
        vector<int> nums;
        char flag = '+';
        int num = 0;
        
        for (; i < s.size(); ++i) {
            if (s[i] == ' ') continue;

            if (!isdigit(s[i]) && s[i] != '(' && s[i] != ')') {
                flag = s[i];
            } else {
                if (s[i] == ')') break;
                
                if (s[i] == '(') num = helper(s, ++i);
                
                else {
                    while (i < s.size() && isdigit(s[i])) num = num * 10 + (s[i++] - '0');
                    --i;
                }

                switch(flag) {
                    case '+':
                        nums.push_back(num); break;
                    case '-':
                        nums.push_back(-num); break;
                    case '*':
                        nums.back() *= num; break;
                    case '/':
                        nums.back() /= num; break;
                }

                num = 0;
            }
        }
        
        return accumulate(nums.begin(), nums.end(), 0);
    }
};