class Solution {
private:
    vector<int> parent;
    vector<int> ranks;
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }

    void _union(int x, int y) {
        int px = find(x), py = find(y);
        if (px == py) return;

        if (ranks[px] < ranks[py]) {
            parent[px] = py; 
        } else if (ranks[px] > ranks[py]) {
            parent[py] = px;
        } else {
            parent[py] = px;
            ++ranks[px];
        }
    }

public:
    int countComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        ranks.resize(n, 1);
        iota(parent.begin(), parent.end(), 0);

        for (auto e : edges) {
            _union(e[0], e[1]);
        }
        
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (i == parent[i]) ++res;
        }
        return res;
    }

};
