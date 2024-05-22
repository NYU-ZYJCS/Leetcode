class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        int n = s.size();
        vector<string> result;
        string temp;
        
        function<void(int, int)> helper = [&] (int pos, int count) {
            if (count > 4) return;
            if (pos == n && count == 4) {
                temp.pop_back();
                result.push_back(temp);
                return;
            }
            
            for (int i = pos; i < min(n, pos + 3); ++i) {
                string part = s.substr(pos, i - pos + 1);
                int num = stoi(part);
                if (part[0] == '0' && i > pos) return;
                if (num >= 0 && num <= 255) {
                    temp += part + ".";
                    helper(i + 1, count + 1);
                    temp = temp.substr(0, pos + count);
                }
            }
        };
        
        helper(0, 0);
        return result;
    }

};