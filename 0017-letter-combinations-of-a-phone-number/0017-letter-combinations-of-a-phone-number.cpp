class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int n = digits.size();
        
        if (n == 0) return {};
        vector<string> result;
        string temp;
        
        function<void(int)> helper = [&] (int pos) {
            if (temp.size() == n) {
                result.push_back(temp);
                return;
            }
            
            for (int i = pos; i < n; ++i) {
                for (auto c : board[digits[i] - '0']) {
                    temp += c;
                    helper(i + 1);
                    temp.pop_back();
                }
            }
        };
        
        helper(0);
        return result;
    }
    
private:
    vector<string> board = {"", "", "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
};