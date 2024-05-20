class Solution {
public:
    int unionFind(int x) {
        if (parent[x] != x) parent[x] = unionFind(parent[x]);
        return parent[x];
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size(), provinces = n;
        parent.resize(n);
        iota(parent.begin(), parent.end(), 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isConnected[i][j]) { 
                    int x = unionFind(i), y = unionFind(j);
                    if (x != y) {
                        parent[x] = y;
                        --provinces;
                    }
                }
            }
        }
        
        return provinces;
    }
    
private:
    vector<int> parent;
};