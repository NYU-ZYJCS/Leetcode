class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string res;
        vector<pair<int, char>> freqs = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
        
        while (1) {
            sort(freqs.begin(), freqs.end(), 
                 [](const pair<int, char> & p1, const pair<int, char> & p2) {
                return p1.first > p2.first;
            });

            bool hasNext = false;
            for (auto &[freq, c] : freqs) {
                int m = res.size();
                if (freq == 0) break;
                
                if (m >= 2 && res[m - 2] == c && res[m - 1] == c) {
                    continue;
                }
                
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