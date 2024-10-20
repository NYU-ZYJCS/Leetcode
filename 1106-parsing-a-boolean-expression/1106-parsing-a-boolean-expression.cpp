class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> stk;
        
        int n = expression.size();
        for (auto c : expression) {
            if (c == ',') continue;
            else if (c != ')') stk.push(c);
            else {
                int t = 0, f = 0;
                while (stk.top() != '(') {
                    stk.top() == 't' ? ++t : ++f;
                    stk.pop();
                }
                stk.pop();
                char op = stk.top();
                stk.pop();
                
                switch(op) {
                    case '!':
                        stk.push(t == 1 ? 'f' : 't');
                        break;
                    case '&':
                        stk.push(f > 0 ? 'f' : 't');
                        break;
                    case '|':
                        stk.push(t > 0 ? 't' : 'f');
                        break;
                }
            }
        }
        return stk.top() == 't';
    }
};