class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<double, int>>> g(n);
        for (int i = 0; i < edges.size(); i++) {
            auto& e = edges[i];
            g[e[0]].emplace_back(succProb[i], e[1]);
            g[e[1]].emplace_back(succProb[i], e[0]);
        }

        priority_queue<pair<double, int>> q;
        vector<double> prob(n, 0);
        q.emplace(1.0, start);
        prob[start] = 1.0;
        
        while (!q.empty()) {
            auto [pb, node] = q.top(); 
            q.pop();
            
            if (pb < prob[node]) continue;
            
            for (auto& [pbNext, nodeNext] : g[node]) {
                if (prob[nodeNext] < prob[node] * pbNext) {
                    prob[nodeNext] = prob[node] * pbNext;
                    q.emplace(prob[nodeNext], nodeNext);
                }
            }
        }
        
        return prob[end];
    }
};