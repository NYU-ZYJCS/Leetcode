class Solution {
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<int> res(n);
        vector<int> size(n, 1);
        
        function<void(int, int, int)> dfs = [&] (int cur, int parent, int depth) {
            res[0] += depth;
            for (int neighbor : graph[cur]) {
                if (neighbor != parent) {
                    dfs(neighbor, cur, depth + 1);
                    size[cur] += size[neighbor];
                }
            }
        };
        dfs(0, -1, 0);
        
        function<void(int, int)> reroot = [&] (int cur, int parent) {
            for (auto neighbor : graph[cur]) {
                if (neighbor != parent) {
                    res[neighbor] = res[cur] + n - 2 * size[neighbor];
                    reroot(neighbor, cur);
                }
            }
        };
        reroot(0, -1);

        return res;
    }
};