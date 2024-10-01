class Solution {
public:
    bool canWin(string currentState) {
        return win(currentState);
    }
    
    bool win(string cur_s) {
        if (win_hash.contains(cur_s)) return win_hash[cur_s];
        
        int n = cur_s.size();
        for (int i = 0; i < n - 1; ++i) {
            if (cur_s[i] == '+' && cur_s[i + 1] == '+') {
                cur_s[i] = cur_s[i + 1] = '-';
                bool result = win(cur_s);
                cur_s[i] = cur_s[i + 1] = '+';
                
                if (result == false) {
                    win_hash[cur_s] = true;
                    return true;
                }
            } 
        }
        
        win_hash[cur_s] = false;
        return win_hash[cur_s];
    }

private:
    unordered_map<string, bool> win_hash; 
};