class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> st(allowed.begin(), allowed.end());
        int res = 0;

        for (string& word : words) {
            bool isConsistent = true;

            for (char c : word) {
                if (st.contains(c) == 0) {
                    isConsistent = false;
                    break;
                }
            }

            if (isConsistent) ++res;
        }
        
        return res;
    }
};