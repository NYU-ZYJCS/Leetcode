class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        stringstream ss(path);
        string res, s;

        while (getline(ss, s, '/')) {
            if (s == "." || s == "") continue;
            if (s == ".." && !stk.empty()) stk.pop();
            else if (s != "..") stk.push(s);
        }
        
        while (!stk.empty()) {
            res = "/" + stk.top() + res;
            stk.pop();
        }
        
        return res.empty() ? "/" : res;
    }
};