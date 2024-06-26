class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            result += mp[s[i]];
            if (i > 0 && mp[s[i]] > mp[s[i - 1]]) result -= 2 * mp[s[i - 1]];
        }
        
        return result;
    }
    
private:
    unordered_map<char,int> mp {
        {'I',1},   {'V',5},
        {'X',10},  {'L',50},
        {'C',100}, {'D',500},
        {'M',1000}
    };
};