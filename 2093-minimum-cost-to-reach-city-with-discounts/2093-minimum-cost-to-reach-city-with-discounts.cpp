class Solution {
public:
    int minimumCost(int n, vector<vector<int>>& highways, int discounts) {
        vector<vector<pair<int, int>>> G(n);
        for (auto &h : highways) {
            G[h[0]].push_back({h[1], h[2]});
            G[h[1]].push_back({h[0], h[2]});
        }
        
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<>> pq;
        pq.push(make_tuple(0, 0, 0));
        vector<vector<int>> dist(n, vector<int>(discounts + 1, INT_MAX));
        dist[0][0] = 0;

        
        while (!pq.empty()) {
            int currentCost, city, discountsUsed;
            tie(currentCost, city, discountsUsed) = pq.top();
            pq.pop();

            if (currentCost > dist[city][discountsUsed]) {
                continue;
            }

            // Explore all neighbors of the current city
            for (int i = 0; i < G[city].size(); ++i) {
                int neighbor = G[city][i].first;
                int toll = G[city][i].second;

                // Case 1: Move to the neighbor without using a discount
                if (currentCost + toll < dist[neighbor][discountsUsed]) {
                    dist[neighbor][discountsUsed] = currentCost + toll;
                    pq.push(make_tuple(dist[neighbor][discountsUsed], neighbor, discountsUsed));
                }

                // Case 2: Move to the neighbor using a discount if available
                if (discountsUsed < discounts) {
                    int newCostWithDiscount = currentCost + toll / 2;
                    if (newCostWithDiscount < dist[neighbor][discountsUsed + 1]) {
                        dist[neighbor][discountsUsed + 1] = newCostWithDiscount;
                        pq.push(make_tuple(newCostWithDiscount, neighbor, discountsUsed + 1));
                    }
                }
            }
        }
        
        int minCost = *min_element(dist[n - 1].begin(), dist[n - 1].end());
        return minCost == INT_MAX ? -1 : minCost;
    }
};