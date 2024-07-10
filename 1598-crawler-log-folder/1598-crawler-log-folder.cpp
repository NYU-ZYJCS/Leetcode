class Solution {
public:
    int minOperations(vector<string>& logs) {
        int result = 0;
        
        for (auto log : logs) {
            if (log == "./") {
                continue;
            } else if (log == "../") {
                result = max(0, result - 1);
            } else {
                ++result;
            }
        }
        
        return result;
    }
};