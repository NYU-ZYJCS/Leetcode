class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n);
        for (auto e : edges) {
            indegree[e[1]]++;
        }
        
        int idx = -1;
        for (int i = 0; i< n; ++i) {
            if (indegree[i] == 0) {
                if (idx != -1) return -1;
                idx = i;
            }
        }
        
        return idx;
    }
};