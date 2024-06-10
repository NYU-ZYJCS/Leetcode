class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int m = *max_element(heights.begin(), heights.end());
        vector<int> freq(m + 1);
        for (int h: heights) ++freq[h];
        
        int idx = 0, res = 0;
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= freq[i]; ++j) {
                if (heights[idx] != i) {
                    ++res;
                }
                ++idx;
            }
        }

        return res;
    }
};