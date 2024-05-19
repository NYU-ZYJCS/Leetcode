class Solution {
public:
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> res;
        
        for (int i = 0; i < n; ++i) {
            char c = expression[i];
            
            if (c == ' ' || isdigit(c)) continue;
            else {
                vector<int> leftResults = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightResults = diffWaysToCompute(expression.substr(i + 1));
                
                for (auto leftResult : leftResults) {
                    for (auto rightResult : rightResults) {
                        switch(c) {
                            case '+': 
                                res.push_back(leftResult + rightResult);
                                break;
                            case '-':
                                res.push_back(leftResult - rightResult);
                                break;
                            case '*':
                                res.push_back(leftResult * rightResult);
                                break;
                        }
                    }
                }
            }
        }
        if (res.empty()) res.push_back(stoi(expression));
        
        return res;
    }
};