class Solution {
public:
    string countOfAtoms(string formula) {
        unordered_map<string, int> freq;
        stack<int> stk;
        string count, lower;
        
        stk.push(1);
        int i = formula.size() - 1;
        
        while (i >= 0) {
            char c = formula[i];
            if ('0' <= c && c <= '9') {
                count = c + count;
            } 
            else if ('A' <= c && c <= 'Z') {
                freq[formula.substr(i, 1) + lower] += stk.top() * (count.empty() ? 1 : stoi(count));
                count = "";
                lower = "";
            } 
            else if ('a' <= c && c <= 'z') {
                lower = c + lower;
            } 
            else if (c == '(') {
                stk.pop();
            } 
            else if (c == ')') {
                stk.push(stk.top() * (count.empty() ? 1 : stoi(count)));
                count = "";
            }
            --i;
        }
        
        string ans;
        vector<pair<string, int>> sortedAtoms(freq.begin(), freq.end());
        sort(sortedAtoms.begin(), sortedAtoms.end());
        
        for (auto it : sortedAtoms) {
            ans += it.first;
            if (it.second > 1) {
                ans += to_string(it.second);
            }
        }
        return ans;
    }
};