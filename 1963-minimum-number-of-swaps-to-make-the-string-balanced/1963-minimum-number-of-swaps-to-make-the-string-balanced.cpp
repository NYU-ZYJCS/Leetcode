class Solution {
public:
    int minSwaps(string s) {
        stack<char> stk;
        int unbalanced = 0;
        for (auto c : s) {
            if (c == '[') stk.push(c);
            else {
                if (!stk.empty()) stk.pop();
                else unbalanced++;
            }
        }
        return (unbalanced + 1) / 2;
    }
};