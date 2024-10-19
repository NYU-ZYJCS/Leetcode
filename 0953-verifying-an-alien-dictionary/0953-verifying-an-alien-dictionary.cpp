class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<int> rank(26);
        
        for (int i = 0; i < order.size(); i++)
            rank[order[i] - 'a'] = i;
        
        for (int i = 1; i < words.size(); ++i) {
            bool valid = false;
            for (int j = 0; j < words[i - 1].size() && j < words[i].size(); j++) {
                int pre = rank[words[i - 1][j] - 'a'];
                int cur = rank[words[i][j] - 'a'];
                if (pre < cur) {
                    valid = true;
                    break;
                }
                if (pre > cur) return false;
            }
            
            if (!valid) {
                if (words[i - 1].size() > words[i].size()) return false;
            }
            
        }
        
        return true;
    }
};