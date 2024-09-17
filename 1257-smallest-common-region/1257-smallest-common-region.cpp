class Solution {
public:
    string findSmallestRegion(vector<vector<string>>& regions, string region1, string region2) {
        unordered_map<string, string> parent;
        unordered_set<string> seen;
        
        for (int i = 0; i < regions.size(); i++) {
            for (int j = 1; j < regions[i].size(); j++) {
                parent[regions[i][j]] = regions[i][0];
            }
        }
        
        while (parent.contains(region1)) {
            seen.insert(region1);
            region1 = parent[region1];
        }
        
        while (parent.contains(region2) && region1 != region2) {
            if (seen.contains(region2)) return region2;
            region2 = parent[region2];
        }
        
        return region1;
    }
};