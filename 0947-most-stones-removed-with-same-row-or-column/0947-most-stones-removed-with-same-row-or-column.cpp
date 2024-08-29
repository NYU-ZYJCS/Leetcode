class Djset {
public:
    vector<int> rank;
    vector<int> parent;
    int count;
    
    Djset(int n) : parent(vector<int>(n)), rank(vector<int>(n)), count(n) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void merge(int x, int y) {
        int rootx = find(x);
        int rooty = find(y);
        
        if (rootx != rooty) {
            if (rank[rootx] < rank[rooty]) {
                swap(rootx, rooty);
            }
            parent[rooty] = rootx;
            if (rank[rootx] == rank[rooty]) rank[rootx] += 1;
            --count;
        }
    }
    
    int get_count() {
        return count;
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        Djset ds(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ds.merge(i, j);
                }
            }
        }
        return n - ds.get_count();

    }
};