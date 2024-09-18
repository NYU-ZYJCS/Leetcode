class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        for (auto num : nums) strs.push_back(to_string(num));
        
        ranges::sort(strs, [](const string& a, const string& b) {
            return a + b > b + a;
        });
        
        string res;
        if(strs[0] == "0") return "0";
        for (auto s : strs) res += s;
        
        return res;
    }
};