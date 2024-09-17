class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        
        for (int i = 0; i < regions.size(); i++) {
            for (int j = 1; j < regions[i].size(); j++) {
                parent[regions[i][j]] = regions[i][0];
            }
        }
        
        string p1 = region1, p2 = region2;
        while (p1 != p2) {
            p1 = parent.contains(p1) ? parent[p1] : region2;
            p2 = parent.contains(p2) ? parent[p2] : region1;
        }
        
        return p1;
    }
};