class Solution {
public:
    string compressedString(string word) {
        char pre_char = word[0];
        int pre_count = 1;
        
        string res;
        for (int i = 1; i < word.size(); ++i) {
            char cur_char = word[i];
            if (cur_char != pre_char || pre_count == 9) {
                res += to_string(pre_count) + string(1, pre_char);
                
                pre_char = cur_char;
                pre_count = 1;
            } else {
                pre_count++;
            }
        }
        
        res += to_string(pre_count) + string(1, pre_char);
        return res;
    }
};