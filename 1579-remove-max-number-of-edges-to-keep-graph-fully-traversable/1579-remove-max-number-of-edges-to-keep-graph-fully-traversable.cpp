class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        dsu a, b;
        a.init(n);
        b.init(n);
        
        int ans = 0;
        for (auto edge : edges) {
            if (edge[0] == 3) {
                bool ba = a.merge(edge[1], edge[2]);
                bool bb = b.merge(edge[1], edge[2]);
                if (!ba && !bb) ++ans;
            }
        }
        
        for (auto edge : edges) {
            if ((edge[0] == 1 && !a.merge(edge[1], edge[2]))
               || (edge[0] == 2 && !b.merge(edge[1], edge[2]))) ++ans;
        }
        

        if (a.N > 1 || b.N > 1) return -1;        
        return ans;
    }
    
private:
    struct dsu {
        vector<int> parent;
        vector<int> rank;
        int N;
        
        void init(int n) {
            N = n;
            parent.resize(N + 1);
            rank.resize(N + 1, 1);
            for (int i = 1; i <= N; ++i) parent[i] = i;
        }
        
        int find(int x) {
            if (parent[x] != x) parent[x] = find(parent[x]);
            return parent[x];
        }
        
        bool merge(int x, int y) {
            int px = find(x), py = find(y);
            if (px == py) return false;
            
            // merge
            if (rank[px] < rank[py]) {
                parent[py] = px;
            } else {
                // rank[x] >= rank[y]
                parent[px] = py;
                if (rank[px] == rank[py]) rank[py]++;
            }
            --N;
            return true;
        }
    };
};