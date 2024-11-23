class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        vector<pair<int, char>> freqs = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        
        while (1) {
            ranges::sort(freqs, greater<>());
            
            bool hasNext = false;
            for (auto& [freq, c] : freqs) {
                int m = res.size();
                
                if (freq == 0) continue;
                if (m >= 2 && res[m - 2] == c && res[m - 1] == c) continue;
                
                hasNext = true;
                res.push_back(c);
                --freq;
                break;
            }
            
            if (!hasNext) break;
        }
        
        return res;
    }
};