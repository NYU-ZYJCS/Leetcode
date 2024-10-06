class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> stk;
        
        for (int i = 0; i < num.size(); ++i) {
            // increasing
            while (k && stk.size() > 0 && num[i] < stk.back()) {
                stk.pop_back();
                k--;
            }
            stk.push_back(num[i]);
        }
        
        for (; k > 0; --k) stk.pop_back();
        
        string res;
        bool isLeadingZero = true;
        
        for (auto& d : stk) {
            if (isLeadingZero && d == '0') continue;
            isLeadingZero = false;
            res.push_back(d);
        }
        
        return res == "" ? "0" : res;
    }
};