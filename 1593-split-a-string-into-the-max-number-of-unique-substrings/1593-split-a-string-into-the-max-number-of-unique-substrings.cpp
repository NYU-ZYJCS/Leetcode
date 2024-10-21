class Solution {
public:
    int maxUniqueSplit(string s) {
        helper(0, 0, s);
        return max_count;
    }
    
    void helper(int pos, int count, string &s) {
        int n = s.size();
        if (pos >= n) {
            max_count = max(max_count, count);
            return;
        }
        
        for (int i = pos; i < n; ++i) {
            string split = s.substr(pos, i - pos + 1);
            if (st.find(split) == st.end()) {
                st.insert(split);
                helper(i + 1, count + 1, s);
                st.erase(split);
            }
        }
    }
    
private:
    int max_count = 0;
    unordered_set<string> st;
};