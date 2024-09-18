class Solution {
public:
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        using ll = long long;
        using pll = pair<ll, ll>;

        vector<vector<pll>> graph(n + 1);
        vector<ll> distances(n + 1, LLONG_MAX);
        for (auto r : roads) {
            graph[r[0]].emplace_back(r[1], r[2] * (k + 1));
            graph[r[1]].emplace_back(r[0], r[2] * (k + 1));
        }

        for (int i = 0; i < n; ++i) {
            graph[0].emplace_back(i + 1, appleCost[i]);
        }

        priority_queue<pll, vector<pll>, greater<pll>> pq;
        pq.push({0, 0});
        distances[0] = 0;
        
        while (!pq.empty()) {
            auto [node, distance] = pq.top();
            pq.pop();
            
            if (distance > distances[node]) continue;
            for (auto [neighbor, cost] : graph[node]) {
                int next_distance = distance + cost;
                if (next_distance < distances[neighbor]) {
                    distances[neighbor] = next_distance;
                    pq.emplace(neighbor, next_distance);
                }
            }
        }
        distances.erase(distances.begin());
        return distances;
    }
};