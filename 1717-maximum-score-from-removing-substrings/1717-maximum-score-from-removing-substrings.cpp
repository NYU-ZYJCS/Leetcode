class Solution {
public:
    int maximumGain(string s, int x, int y) {
        if (x >= y) {
            s = helper(s, "ab", x);
            s = helper(s, "ba", y);
        } else {
            s = helper(s, "ba", y);
            s = helper(s, "ab", x);  
        }
        
        return score;
    }
    
private:
    int score = 0;
    
    string helper(string s, string p, int val) {
        string temp;

        for (int i = 0; i < s.size(); ++i) {
            temp.push_back(s[i]);
            if (temp.size() >= 2 && temp[temp.size() - 2] == p[0] && temp[temp.size() - 1] == p[1]) {
                temp.pop_back();
                temp.pop_back();
                score += val;
            }
        }
        return temp;
    }
    
};