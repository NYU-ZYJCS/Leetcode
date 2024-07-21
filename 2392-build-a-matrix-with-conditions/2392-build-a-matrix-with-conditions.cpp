class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        auto row = topo_sort(k, rowConditions), col = topo_sort(k, colConditions);
        if (row.size() < k || col.size() < k) return {};

        vector<vector<int>> ans(k, vector<int>(k));
        vector<int> pos(k);
        for (int i = 0; i < k; ++i) {
            pos[col[i]] = i; 
        }
        
        for (int i = 0; i < k; ++i) {
            ans[i][pos[row[i]]] = row[i] + 1;
        }
        
        return ans;
    }
    
    vector<int> topo_sort(int k, vector<vector<int>> &edges) {
        vector<vector<int>> g(k);
        vector<int> in_deg(k);
        
        for (auto e : edges) {
            int x = e[0] - 1, y = e[1] - 1;
            g[x].push_back(y);
            in_deg[y]++;
        }
        
        vector<int> order;
        queue<int> q;
        for (int i = 0; i < k; ++i)
            if (in_deg[i] == 0) q.push(i);

        while (!q.empty()) {
            int x = q.front();
            q.pop();
            order.push_back(x);
            
            for (auto y : g[x]) {
                if (--in_deg[y] == 0) {
                    q.push(y);
                }
            }
        }
        
        return order;
    }
};