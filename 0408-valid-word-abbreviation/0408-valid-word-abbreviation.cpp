class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int i = 0, j = 0;
        while (i < word.size() && j < abbr.size()) {
            if (word[i] == abbr[j]) {
                ++i, ++j;
                continue;
            }

            
            if (abbr[j] <= '0' || abbr[j] > '9') {
                return false;
            }

            int start = j;
            while (j < abbr.size() && abbr[j] >= '0' && abbr[j] <= '9') {
                ++j;
            }

            int num = stoi(abbr.substr(start, j));
            i += num;
        }
        return i == word.size() && j == abbr.size();
    }
};