class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        
        int start_idx = 0;
        int n = words.size();
        
        while (start_idx < n) {
            int cur_length = words[start_idx].size();
            int end_idx = start_idx + 1;
            
            while (end_idx < n && cur_length + 1 + words[end_idx].size() <= maxWidth) {
                cur_length += 1 + words[end_idx++].size();
            }
            
            string temp = words[start_idx];
            int separate_count = end_idx - start_idx - 1;
            
            // only have one word or the last line
            if (end_idx == n || separate_count == 0) {
                for (int i = start_idx + 1; i < end_idx; ++i) {
                    temp += " " + words[i];
                }
                
                // fill in zero
                for (int i = temp.size(); i < maxWidth; ++i) {
                    temp += " ";
                }
            } else {
                int space_count = (maxWidth - cur_length) / separate_count;
                int space_remain = (maxWidth - cur_length) % separate_count;
                
                for (int i = start_idx + 1; i < end_idx; ++i) {
                    for (int j = 0; j < space_count; ++j) {
                        temp += " ";
                    }
                    
                    if (space_remain > 0) {
                        temp += " ";
                        space_remain--;
                    }
                    
                    temp += " " + words[i];
                }
            }
            
            result.push_back(temp);
            start_idx = end_idx;
        }
        
        return result;
    }
};