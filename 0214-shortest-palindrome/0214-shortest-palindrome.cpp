class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        int mid = s.size();

        s = s + '#' + rev;

        int n = s.size();
        vector<int> next(n);
        auto getNext = [&] () {
            for (int i = 1, j = 0; i < n; ++i) {
                while (j > 0 && s[i] != s[j]) j = next[j - 1];
                if (s[i] == s[j]) ++j;
                next[i] = j;
            }
        };

        getNext();
        return s.substr(mid + 1, mid - next[n - 1]) + s.substr(0, mid);
    }
};