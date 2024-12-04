class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        // str2[j] + 1
        
        int m = str1.length(), n = str2.length();
        if (m < n) return false;

        auto rotate = [](char c) { return (c + 1 - 'a') % 26 + 'a'; };

        int i = 0, j = 0;
        for (; i < m && j < n; i ++) 
            if (str1[i] == str2[j] || rotate(str1[i]) == str2[j]) 
                j ++;
        return j == n;

    }
};