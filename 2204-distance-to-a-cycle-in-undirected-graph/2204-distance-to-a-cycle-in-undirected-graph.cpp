class Solution {
public:
    vector<int> distanceToCycle(int n, vector<vector<int>>& edges) {
        vector<vector<int>> al(n);
        vector<int> res(n, 0), cnt(n);
        queue<int> q;
        for (auto &e : edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        for (int i = 0; i < n; ++i) {
            cnt[i] = al[i].size();
            if (cnt[i] == 1)
                q.push(i);        
        }
        while (!q.empty()) {
            int i = q.front(); q.pop();
            res[i] = INT_MAX;
            for (int j : al[i])
                if (cnt[j] > 1 && --cnt[j] == 1)
                    q.push(j);
        }
        for (int i = 0; i < n; ++i)
            if (cnt[i] > 1)
                q.push(i);
        while(!q.empty()) {
            int i = q.front(); q.pop();
            for (int j : al[i])
                if (res[j] > res[i] + 1) {
                    res[j] = res[i] + 1;
                    q.push(j);
                }
        }
        return res;
    }
};