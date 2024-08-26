class Solution {
public:
    vector<string> generateAbbreviations(string word) {
        helper(word, 0, "", 0);
        return ans;
    }
    
    void helper(string word, int pos, string cur, int count) {
        if (pos == word.size()) {
            if (count > 0) cur += to_string(count);
            ans.push_back(cur);
        } else {
            // add current character
            helper(word, pos + 1, cur + (count > 0 ? to_string(count) : "") + word[pos], 0);
            // abbreviate current character
            helper(word, pos + 1, cur, count + 1);
        }
    }
        
private:
    vector<string> ans;
};