class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int, int>> height;
        
        for (auto &b : buildings) {
            height.push_back({b[0], -b[2]});
            height.push_back({b[1], b[2]});
        }


        multiset<int> st;
        ranges::sort(height);
        st.insert(0);
        
        int preMaxHeight = 0;
        int curMaxHeight = 0;
        for (auto& h : height) {
            if (h.second < 0) st.insert(-h.second);
            else st.erase(st.find(h.second));
            
            curMaxHeight = *st.rbegin();
            if (preMaxHeight != curMaxHeight) {
                res.push_back({h.first, curMaxHeight});
                preMaxHeight = curMaxHeight;
            }
        }
        
        return res;
    }
};