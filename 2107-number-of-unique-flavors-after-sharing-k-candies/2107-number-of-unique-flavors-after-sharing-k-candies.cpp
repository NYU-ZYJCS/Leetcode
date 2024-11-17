class Solution {
public:
    int shareCandies(vector<int>& candies, int k) {
        unordered_map<int, int> freq;
        
        for (auto c : candies) {
            freq[c]++;
        }
        
        int unique_count = freq.size();
        int res = INT_MIN;
        
        for (int i = 0; i < candies.size(); ++i) {
            freq[candies[i]]--;
            if (freq[candies[i]] == 0) unique_count--; 

            if (i >= k) { 
                freq[candies[i - k]]++;
                if (freq[candies[i - k]] == 1) unique_count++;
            }

            if (i >= k - 1) {
                res = max(res, unique_count);
            }
        }
        
        return res;
    }
};