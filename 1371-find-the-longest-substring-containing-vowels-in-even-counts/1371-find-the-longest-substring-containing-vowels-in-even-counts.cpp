class Solution {
public:
    int findTheLongestSubstring(string s) {
        int n = s.size();
        vector<int> pos(32, INT_MAX);
        pos[0] = -1;
        int status = 0, res = 0;
        
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            switch(c) {
                case 'a': status ^= 1; break;
                case 'e': status ^= 2; break;
                case 'i': status ^= 4; break;
                case 'o': status ^= 8; break;
                case 'u': status ^= 16; break;
                default: break;
            }
            if (pos[status] == INT_MAX) pos[status] = i;
            else res = max(res, i - pos[status]);
        }
        return res;
    }
};