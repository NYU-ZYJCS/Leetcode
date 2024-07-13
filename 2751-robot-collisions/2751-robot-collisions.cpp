class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        
        
        ranges::sort(ids, [&] (const int& i, const int& j) {
            return positions[i] < positions[j];
        });
        
        vector<int> stk;
        for (auto id : ids) {
            if (directions[id] == 'R') {
                stk.push_back(id);
                continue;
            }
            
            while (!stk.empty()) {
                int top = stk.back();
                if (healths[top] > healths[id]) {
                    healths[top]--;
                    healths[id] = 0;
                    break;
                }
                
                if (healths[top] == healths[id]) {
                    healths[top] = 0;
                    healths[id] = 0;
                    stk.pop_back();
                    break;
                }
                
                healths[top] = 0;
                healths[id]--;
                stk.pop_back();
            }
        }
        
        healths.erase(remove(healths.begin(), healths.end(), 0), healths.end());
        return healths;
    }
};