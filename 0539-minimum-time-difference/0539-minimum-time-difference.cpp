class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        bitset<1440> timeBits;
    
        for (string time : timePoints) {
            int h = stoi(time.substr(0, 2));
            int m = stoi(time.substr(3));
            int t = h * 60 + m;
            
            if (timeBits[t]) return 0;
            timeBits.set(t);
        }
        
        int first = -1, last = -1, prev = -1, minDiff = INT_MAX;
        for (int i = 0; i < 1440; ++i) {
            if (timeBits[i]) {
                if (first == -1) first = i;
                else minDiff = min(minDiff, i - prev);
                prev = i;
                last = i;
            }
        }
        minDiff = min(minDiff, 1440 - last + first);
        
        return minDiff;
    }
};