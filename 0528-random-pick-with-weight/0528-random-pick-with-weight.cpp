class Solution {
public:
    Solution(vector<int>& w) {
        partial_sum(w.begin(), w.end(), back_inserter(prefix));
    }
    
    int pickIndex() {
        int weight = rand() % prefix.back();
        return upper_bound(prefix.begin(), prefix.end(), weight) - prefix.begin();
    }
    
private:
    vector<int> prefix;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */