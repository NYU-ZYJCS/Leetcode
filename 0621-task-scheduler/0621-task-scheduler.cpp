class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int result = 0;
        vector<int> freq(26, 0);

        int maxFreq = 1;
        for (auto c : tasks) {
            freq[c - 'A']++;
            maxFreq = max(maxFreq, freq[c - 'A']);
        }
        
        int lastLineCount = 0;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == maxFreq) ++lastLineCount;
        }
        
        return max((maxFreq - 1) * (n + 1) + lastLineCount, (int)tasks.size());
    }
};