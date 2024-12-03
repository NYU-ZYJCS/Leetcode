class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int p = 0;
        for (int i = 0; i < s.length(); ++i){
            if (p < spaces.size() && i == spaces[p]){
                ++p;
                res.push_back(' ');
            }
            res.push_back(s[i]);
        }
        return res;
    }
};