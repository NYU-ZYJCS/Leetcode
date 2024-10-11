class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        // [1, 5], [2, 6], [3, 10]
        
        int n = times.size();
        vector<pair<int, int>> arrival;
        vector<pair<int, int>> leaving; 
        for (int i = 0; i < n; ++i) {
            arrival.emplace_back(times[i][0], i);
            leaving.emplace_back(times[i][1], i);
        }
        
        sort(arrival.begin(), arrival.end());
        sort(leaving.begin(), leaving.end());

        priority_queue<int, vector<int>, greater<int>> available;
        for (int i = 0; i < n; ++i) {
            available.push(i);
        }
        unordered_map<int, int> seats;
        
        int j = 0;
        for (auto& [time, person] : arrival) {
            while (j < n && leaving[j].first <= time) {
                available.push(seats[leaving[j].second]);
                ++j;
            }
            
            seats[person] = available.top();
            available.pop();
            if (person == targetFriend) return seats[person];
        }
        
        return -1;
    }
};